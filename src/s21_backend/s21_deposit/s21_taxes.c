#include "s21_deposit.h"

static int write_taxes(deposit_init *data, investment *pay, long double *year_profit, long double non_taxable_amount);

/**
 * @brief Checks the current period for transition between years.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] end structure containing information about the end of the current period.
 * @param[in] last structure containing information about the last deposit day.
 * @param[out] year_profit amount accumulated during the year.
 * @param[in] non_taxable_amount tax free amount.
 * @param[in] begin_year the year from which the current period began.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int check_taxes(deposit_init *data, investment *pay, time_data end, time_data last, long double *year_profit, long double non_taxable_amount, int begin_year) {
    int error_code = ALLOCATED;
    
    if(begin_year != end.year && data->capital_time != BY_END_TERM) {
        data->date.year = begin_year;
        error_code = write_taxes(data, pay, year_profit, non_taxable_amount);
    }
    if(compare_dates(end, last) == DATE_EQUAL) {
        data->date.year = end.year;
        *year_profit += pay->profit;
        error_code = write_taxes(data, pay, year_profit, non_taxable_amount);
    }

    *year_profit += pay->profit;

    return error_code;
}

/**
 * @brief A function that records taxation in an array.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[out] year_profit amount accumulated during the year.
 * @param[in] non_taxable_amount tax free amount.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int write_taxes(deposit_init *data, investment *pay, long double *year_profit, long double non_taxable_amount) {
    int error_code = ALLOCATED;
    long double year_tax = 0;

    allocate_row(&pay->taxes, pay->taxes_count, TAXES_COLUMNS);
    if(error_code == ALLOCATED) {
        if(*year_profit > non_taxable_amount) {
            year_tax = round_value((*year_profit - non_taxable_amount) * NDFL_RATE / 100);

            pay->taxes[pay->taxes_count][3] = *year_profit - non_taxable_amount;
            pay->taxes[pay->taxes_count][4] = year_tax;
        } 

        pay->taxes[pay->taxes_count][0] = data->date.year;
        pay->taxes[pay->taxes_count][1] = *year_profit;
        pay->taxes[pay->taxes_count][2] = non_taxable_amount;
            
        *year_profit = 0; 
    }

    pay->taxes_count++;

    return error_code;
}
