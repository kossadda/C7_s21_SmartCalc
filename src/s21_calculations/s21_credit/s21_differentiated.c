#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void differentiated(initial *data, payments *pay, time_data next_month) {
    if(data->debt < pay->main) {
        pay->main = data->debt;
    }

    calc_percent(data, pay, next_month);
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;

    remember_result(data, pay);
}
