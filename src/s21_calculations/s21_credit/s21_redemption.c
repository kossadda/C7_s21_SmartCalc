#include "s21_credit.h"

static int logarithm(long double x, long double base);

/**
 * @brief
 * Calculates early payments.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] next_month structure containing the payment end date for the current month.
 * @param[in] redemption structure containing data on early repayments.
 * @param[in] paid_percent the amount deducted from the monthly interest in case of early repayment.
 * @param[in] change variable reporting the change in the debt balance in case of early repayment.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int redemp_payment(initial *data, payments *pay, time_data *next_month, early_pay *redemption, long double *paid_percent, int *change)
{
    long double monthly_pay = pay->monthly;
    int error_code = ALLOCATED;
    data->current++;
    error_code = allocate_memory(data, pay);
    if(error_code == ALLOCATED) {
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
        if(*change) {
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
            if(redemption->type[redemption->current] == REDUCE_PAY && *change == DEBT_CHANGED) {
                pay->const_main = round_value(data->debt/(data->months - (data->current - redemption->current)));
            }
            pay->main = pay->const_main;
        }
        redemption->current++;
    }
    return error_code;
}

/**
 * @brief Determines the logarithm of an arbitrary number to an arbitrary base and rounds the result of the calculation.
 * 
 * @param x the logarithm number of which must be determined.
 * @param base the base by which the logarithm must be determined.
 * 
 * @return Result of a calculation.
*/
static int logarithm(long double x, long double base) {
    return ceil(log(x) / log(base));
}
