#include "s21_credit.h"

int compare_month(time_data now, time_data *pay, time_data next) {
    int day_between = 0;
    if(pay->year == now.year || pay->year == next.year) {
        if(pay->month == now.month && pay->day >= now.day) {
            day_between = 1;
            pay->leap = now.leap;
            pay->month_days = pay->day - now.day;
        } else if(pay->month == next.month && pay->day < next.day) {
            day_between = 1;
            pay->leap = next.leap;
            pay->month_days = now.month_days + pay->day;
        }
    }
    return day_between;
}

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void differentiated(initial *data, payments *pay, time_data next_month, another_payments *redemption) {
    int redemption_pay = 0;
    static int less_days = 0;
    if(data->debt < pay->main) {
        pay->main = data->debt;
    }
    if(less_days) {
        data->date.month_days -= less_days - 1;
        less_days = 0;
    }
    calc_percent(data, pay, next_month);
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;

    remember_result(data, pay);

    for(int i = 0; i < redemption->count; i++) {
        int day_between = compare_month(data->date, &(redemption->date[i]), next_month);
        if(day_between && redemption->sum[i]) {
            data->current++;
            allocate_memory(data, pay);
            i = redemption->count;
            redemption_pay++;
        }
    }
    if(redemption_pay) {
        long double temp = round((data->debt * data->rate / 100) / ((redemption->date[redemption->current].leap) ? LEAP_YEAR : YEAR) * redemption->date[redemption->current].month_days * 100) / 100;
        pay->percent = temp;
        pay->monthly = redemption->sum[redemption->current];
        pay->main = pay->monthly - pay->percent;
        data->debt -= pay->main;

        redemption->sum[redemption->current] = 0;
        remember_result(data, pay);
        less_days = redemption->date[redemption->current].day;
        redemption->current++;
        if(redemption->type[redemption->current] == REDUCE_PAY) {
            pay->const_main -= round(pay->main/(data->months - (data->current - redemption->current) - 1) * 100) / 100;
        }
    }
    pay->main = pay->const_main;
}
