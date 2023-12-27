#include "s21_credit.h"

int logarifm(long double x, long double base) {
    return ceil(log(x) / log(base));
}

/// @brief Calculates early payment
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @param next_month Structure containing the payment end date for the current month
/// @param redemption Structure containing data on early repayments
/// @param paid_percent The amount deducted from the monthly interest in case of early repayment
/// @param change Variable reporting the change in the debt balance in case of early repayment
int redemp_payment(initial *data, payments *pay, time_data *next_month, another_payments *redemption, long double *paid_percent, int *change)
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
        long double percent = round_value((data->debt * data->rate / 100) / ((redemption->date[redemption->current].leap) ? LEAP_YEAR : YEAR) * redemption->date[redemption->current].month_days);
        if(redemption->sum[redemption->current] > percent) {
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
            data->months = logarifm(monthly_pay/(monthly_pay - data->rate/12/100 *data->debt), 1 + data->rate/12/100) + (data->current - redemption->current);
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
