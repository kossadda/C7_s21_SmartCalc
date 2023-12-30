#include "s21_credit.h"

static int init_massive(payments *pay);

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
    int error_code_data = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_data + error_code_pay;

    time_data next_month;
    
    if(error_code == ALLOCATED) {
        if(redemption) {
            redemption->current = 0;
        }
        next_month = data->date;
        next_month.leap = check_leap(next_month.year);
        add_month(&next_month, data->date.day);

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

/**
 * @brief Function initializing a data array.
 * 
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int init_massive(payments *pay)
{
    int error_code = NOT_ALLOCATED;
    int error_code_total = NOT_ALLOCATED;
    int error_code_result = NOT_ALLOCATED;
    pay->total = (long double *)malloc(3 * sizeof(long double));
    error_code_total = CHECK_NULL(pay->total);
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    error_code_result = CHECK_NULL(pay->result);
    error_code = error_code_total + error_code_result;
    pay->total[0] = 0;
    pay->total[1] = 0;
    pay->total[2] = 0;
    return error_code;
}