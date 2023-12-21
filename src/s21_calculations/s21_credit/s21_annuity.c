#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void annuity(initial *data, payments *pay) {
    static long double rest = 0;

    calc_percent(data, pay);

    if(rest) {
        pay->percent += rest;
        rest = 0;
    }
    if(pay->percent > pay->monthly) {
        rest = pay->percent - pay->monthly;
        pay->percent = pay->monthly;
        pay->main = 0;
    } else {
        if(data->debt >= pay->monthly) {
            pay->main = pay->monthly - pay->percent;
        } else if(data->debt < pay->monthly && data->debt + pay->percent > pay->monthly) {
            pay->main = pay->monthly - pay->percent;
        } else {
            pay->main = data->debt;
            pay->monthly = pay->main + pay->percent;
        }
    }
    data->debt -= pay->main;
    
    remember_result(data, pay);
}
