/**
 * @file s21_redemption.c
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 0.1
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "s21_credit.h"

static void determine_debt_changing(credit_init *data, early_pay *redemption, payments *pay, long double *paid_percent, int *change);
static void change_days_pays(credit_init *data, early_pay *redemption, time_data *next_month, payments *pay, long double monthly_pay, int change);
static int logarithm(long double x, long double base);

/*!
 * @brief
 * Calculates early payments.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[out] redemption structure containing data on early repayments.
 * @param[out] next_month structure containing the payment end date for the current month.
 * @param[out] paid_percent the amount deducted from the monthly interest in case of early repayment.
 * @param[out] change variable reporting the change in the debt balance in case of early repayment. DEBT_NOT_CHANGED = 0 - hasn't changed, DEBT_CHANGED = 1 - changed.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int redemp_payment(credit_init *data, payments *pay, early_pay *redemption, time_data *next_month, long double *paid_percent, int *change)
{
    long double monthly_pay = pay->monthly;
    int error_code = ALLOCATED;

    data->current++;
    error_code = allocate_row(&pay->result, data->current, CREDIT_COLUMNS);

    if(error_code == ALLOCATED) {
        determine_debt_changing(data, redemption, pay, paid_percent, change);

        pay->monthly = redemption->sum[redemption->current];
        pay->main = pay->monthly - pay->percent;

        if(data->debt < pay->main) {
            pay->main = data->debt;
            pay->monthly = pay->percent + pay->main;
        }
        data->debt -= pay->main;

        if(redemption->type[redemption->current] == REDUCE_TERM && pay->main && data->payment_type == ANNUITY) {
            data->months = logarithm(monthly_pay/(monthly_pay - data->rate/12/100 *data->debt), 1 + data->rate/12/100) + (data->current - redemption->current);
        } else if(redemption->type[redemption->current] == REDUCE_TERM && pay->main && data->payment_type == DIFFERENTIATED) {
            data->months = ceil(data->debt / pay->const_main);
        }

        remember_result(data, pay);

        change_days_pays(data, redemption, next_month, pay, monthly_pay, *change);

        redemption->current++;
    }
    return error_code;
}

/*!
 * @brief Calculates the interest payment and determines whether the balance of the debt has changed.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] redemption structure containing data on early repayments.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[out] paid_percent the amount deducted from the monthly interest in case of early repayment.
 * @param[out] change variable reporting the change in the debt balance in case of early repayment. DEBT_NOT_CHANGED = 0 - hasn't changed, DEBT_CHANGED = 1 - changed.
*/
static void determine_debt_changing(credit_init *data, early_pay *redemption, payments *pay, long double *paid_percent, int *change) {
    if(*change == DEBT_CHANGED) {
        redemption->date[redemption->current].month_days = sub_date(redemption->date[redemption->current], redemption->date[redemption->current - 1]);
    } else {
        redemption->date[redemption->current].month_days = sub_date(redemption->date[redemption->current], data->date);
    }

    long double percent = round_value((data->debt * data->rate / 100) / ((redemption->date[redemption->current].leap) ? LEAP_YEAR : YEAR_DAYS) * redemption->date[redemption->current].month_days);

    if(redemption->sum[redemption->current] > percent - *paid_percent) {
        *change = DEBT_CHANGED;
    } else {
        *change = DEBT_NOT_CHANGED;
    }

    if(*change == DEBT_CHANGED) {
        pay->percent = percent - *paid_percent;
        *paid_percent = 0;
    } else {
        pay->percent = (percent > redemption->sum[redemption->current]) ? redemption->sum[redemption->current] : percent;
        *paid_percent += pay->percent;
    }
}

/*!
 * @brief Changes the number of days remaining after the operation and changes the monthly payments according to the type of payments.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] redemption structure containing data on early repayments.
 * @param[out] next_month structure containing the payment end date for the current month.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] monthly_pay current monthly payment amount.
 * @param[in] change contains information about whether the amount of the debt has changed. DEBT_NOT_CHANGED = 0 - hasn't changed, DEBT_CHANGED = 1 - changed.
*/
static void change_days_pays(credit_init *data, early_pay *redemption, time_data *next_month, payments *pay, long double monthly_pay, int change) {
    if(change) {
        if(redemption->date[redemption->current].month == data->date.month && redemption->date[redemption->current].day >= data->date.day) {
            data->date.month_days = sub_till_end_month(redemption->date[redemption->current]);
        } else {
            data->date.month_days = 0;
            next_month->month_days = sub_date(*next_month, redemption->date[redemption->current]);
        }
    }

    if(data->payment_type == ANNUITY) {
        if(pay->main && redemption->type[redemption->current] == REDUCE_PAY) {
            monthly_pay = round_value(data->debt * data->rate / 12 / 100 / (1 - pow((1.0 + data->rate / 12 / 100), (data->months - (data->current - redemption->current)) * (-1))));
        }
        pay->monthly = monthly_pay;
    }
    
    if(data->payment_type == DIFFERENTIATED) {
        if(redemption->type[redemption->current] == REDUCE_PAY && change == DEBT_CHANGED) {
            int term = data->months - (data->current - redemption->current);
            pay->const_main = (term) ? round_value(data->debt/term) : pay->const_main;
        }
        pay->main = pay->const_main;
    }
}

/*!
 * @brief Determines the logarithm of an arbitrary number to an arbitrary base and rounds the result of the calculation.
 * 
 * @param[in] x the logarithm number of which must be determined.
 * @param[in] base the base by which the logarithm must be determined.
 * 
 * @return Result of a calculation.
*/
static int logarithm(long double x, long double base) {
    return ceil(log(x) / log(base));
}
