#include "s21_credit.h"

/**
 * @brief Function for calculating monthly payments of annuity type.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] redemption structure containing data on early repayments.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int calculate_credit(initial *data, payments *pay, early_pay *redemption)
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

        error_code = init_massive(pay);
    }

    if(error_code == ALLOCATED) {
        if(data->payment_type == ANNUITY) {
            annuity(data, pay, redemption, next_month);
        } else if(data->payment_type == DIFFERENTIATED) {
            differentiated(data, pay, redemption, next_month);
        }
    }
    return error_code;
}
