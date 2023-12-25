#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void differentiated(initial *data, payments *pay, time_data next_month, long double full_percent) {
    int error_code = ALLOCATED;
    if(data->debt) {
        data->current++;
        error_code = allocate_memory(data, pay);
        if(error_code == ALLOCATED) {
            if(data->debt < pay->main) {
                pay->main = data->debt;
            }
            calc_percent(data, pay, next_month);
            pay->percent -= full_percent;
            pay->monthly = pay->main + pay->percent;
            data->debt -= pay->main;
            remember_result(data, pay);
        }
    }
}
