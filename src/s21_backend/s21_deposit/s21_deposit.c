/// \file
#include "s21_deposit.h"

static int init_taxes(investment *pay);

/*!
 * @brief Main function for calculating payments for all deposit term.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[out] oper structure containing data on deposit/withdrawal operations.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int calculate_deposit(deposit_init *data, investment *pay, operations *oper)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    int const_day = data->date.day;
    time_data last_day = determine_last_day(data->date, data->term_type, data->term);

    if(error_code == ALLOCATED) {
        if(oper) {
            oper->current = 0;
            // oper->min_balance = 0;
        }
        data->date.leap = check_leap(data->date.year);
        
        int error_code_payments = init_payments(&pay->result, &pay->total);
        int error_code_taxes = init_taxes(pay);

        error_code = error_code_payments + error_code_taxes;
    }

    if(error_code == ALLOCATED) {
        time_data end_period = data->date;
        long double non_taxable_amount = NON_TAX_SUM * TAX_RATE / 100;
        long double year_profit = 0;
        
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            long double percent = 0;
            int begin_year = data->date.year;

            add_one_period(&(data->date), &end_period, last_day, data->capital_time, const_day);

            error_code = check_operation(data, pay, oper, &end_period, &percent);
            
            if(error_code == ALLOCATED) {
                error_code = calc_period(data, pay, end_period, percent);
            }

            if(error_code == ALLOCATED) {
                error_code = check_taxes(data, pay, end_period, last_day, &year_profit, non_taxable_amount, begin_year);
            }

            data->date = (error_code == ALLOCATED) ? end_period : last_day;
        }
    }
    return error_code;
}

/*!
 * @brief Function initializing a taxes array.
 * 
 * @param[out] pay structure containing buffer variables for taxes data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int init_taxes(investment *pay)
{
    int error_code = NOT_ALLOCATED;
    
    pay->taxes = (long double **)malloc(1 * sizeof(long double *));
    error_code = CHECK_NULL(pay->taxes);
    
    pay->taxes_count = 0;

    return error_code;
}
