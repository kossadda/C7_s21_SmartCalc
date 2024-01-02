#include "s21_deposit.h"

/**
 * @brief Main function for calculating payments for all deposit term.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
void calculate_deposit(deposit_init *data, investment *pay)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    int const_day = data->date.day;
    time_data last_day = determine_last_day(data->date, data->term_type, data->term);

    if(error_code == ALLOCATED) {
        data->date.leap = check_leap(data->date.year);

        error_code = init_payments(&pay->result, &pay->total);
    }

    if(error_code == ALLOCATED) {
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            time_data end_period = data->date;
            add_one_period(&(data->date), &end_period, last_day, data->capital_time, const_day);

            error_code = calc_period(data, pay, end_period);
            
            if(data->capital_time != BY_END_TERM) {
                data->date = end_period;
            }

            data->current = (error_code == ALLOCATED) ? data->current : data->term;
        }
    }
}
