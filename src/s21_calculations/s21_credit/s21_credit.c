#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void calculate_credit(initial *data, payments *pay) {
    int const_day = data->date.day;
    time_data next_month = data->date;
    next_month.leap = check_leap(next_month.year);
    add_month(&next_month, const_day);

    pay->total = (long double *)malloc(3 * sizeof(long double));
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    pay->total[0] = 0;
    pay->total[1] = 0;
    pay->total[2] = 0;

    if(data->payment_type == DIFFERENTIATED) {
        pay->main = round(data->debt/data->months * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++) {
            pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
            pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
            check_days(data, &next_month, const_day);
            differentiated(data, pay);
        }
    } else if(data->payment_type == ANNUITY) {
        double monthly_percent = data->rate / (100.0 * 12.0);
        pay->monthly = round(data->debt * monthly_percent / (1 - pow((1.0 + monthly_percent), data->months * (-1))) * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++) {
            pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
            pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
            check_days(data, &next_month, const_day);
            annuity(data, pay);
        }
    }
}
