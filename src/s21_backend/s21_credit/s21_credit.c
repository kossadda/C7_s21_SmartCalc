#include "s21_credit.h"

/**
 * @brief Main function for calculating payments for all credit term.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[out] redemption structure containing data on early repayments.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int calculate_credit(credit_init *data, payments *pay, early_pay *redemption)
{
    int error_code_data = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_data + error_code_pay;
    
    if(error_code == ALLOCATED) {
        if(redemption) {
            redemption->current = 0;
        }
        
        error_code = init_payments(&pay->result, &pay->total);
    }

    if(error_code == ALLOCATED) {
        calculate_payments(data, pay, redemption);
    }
    
    return error_code;
}
