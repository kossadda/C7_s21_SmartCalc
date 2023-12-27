#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @param redemption Structure containing data on early repayments
int calculate_credit(initial *data, payments *pay, another_payments *redemption)
{
    int error_code = NOT_ALLOCATED;
    int error_code_data = NOT_ALLOCATED;
    int error_code_pay = NOT_ALLOCATED;

    time_data next_month;
    int const_day = 0;

    error_code_data = CHECK_NULL(data);
    error_code_pay = CHECK_NULL(pay);
    error_code = error_code_data + error_code_pay;
    
    if(error_code == ALLOCATED) {
        if(redemption) {
            redemption->current = 0;
        }
        const_day = data->date.day;
        next_month = data->date;
        next_month.leap = check_leap(next_month.year);
        add_month(&next_month, const_day);

        data->amount = data->debt;
        error_code = init_massive(pay);
    }

    if(error_code == ALLOCATED && data->payment_type == ANNUITY) {
        annuity(data, pay, redemption, next_month);
    } else if(error_code == ALLOCATED && data->payment_type == DIFFERENTIATED) {
        differentiated(data, pay, redemption, next_month);
    }
    return error_code;
}
