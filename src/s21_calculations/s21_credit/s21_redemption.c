#include "s21_credit.h"

/// @brief Calculates early payment
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @param next_month Structure containing the payment end date for the current month
/// @param redemption Structure containing data on early repayments
/// @param paid_percent The amount deducted from the monthly interest in case of early repayment
/// @param change Variable reporting the change in the debt balance in case of early repayment
int redemp_payment(initial *data, payments *pay, time_data *next_month, another_payments *redemption, long double *paid_percent, int *change)
{
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

        remember_result(data, pay);
        if(*change) {
            if(redemption->date[redemption->current].month == data->date.month && redemption->date[redemption->current].day >= data->date.day) {
                data->date.month_days = sub_till_end_month(redemption->date[redemption->current]);
            } else {
                data->date.month_days = 0;
                next_month->month_days = sub_date(*next_month, redemption->date[redemption->current]);
            }
        }
        if(redemption->type[redemption->current] == REDUCE_PAY) {
            if(data->payment_type == ANNUITY) {
                pay->const_main = pay->main;
            }
            pay->const_main -= round_value(pay->main/(data->months - (data->current - redemption->current)));
        }
        pay->main = pay->const_main;
        redemption->current++;
    }
    return error_code;
}
