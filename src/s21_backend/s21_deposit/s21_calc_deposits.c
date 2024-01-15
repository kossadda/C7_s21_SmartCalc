/// \file
#include "s21_deposit.h"

/*!
 * @brief Function for determining all payments for a certain period.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] end_period period end date.
 * @param[in] percent the amount accumulated before the expected replenishment/withdrawal in the current period.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int calc_period(deposit_init *data, investment *pay, time_data end_period, long double percent)
{
    int error_code = ALLOCATED;

    data->current++;
    error_code = allocate_row(&pay->result, data->current, DEPOSIT_COLUMNS);

    if(error_code == ALLOCATED) {
        long double first_part_month = percent_formula(data->amount, data->rate, data->date.leap, data->date.month_days);
        long double second_part_month = percent_formula(data->amount, data->rate, end_period.leap, end_period.month_days);
        pay->profit = round_value(first_part_month + second_part_month + percent);
        
        if(data->capital == CAPITAL) {
            pay->balance_changing = pay->profit;
            pay->receiving = 0;
            data->amount += pay->profit;
        } else {
            pay->balance_changing = 0;
            pay->receiving = pay->profit;
        }

        pay->balance = data->amount;
        write_results(*data, pay);
    }

    return error_code;
}

/*!
 * @brief A function that writes the result of each month to an array.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and general payment data arrays.
*/
void write_results(deposit_init data, investment *pay)
{
    pay->result[data.current][0] = pay->profit;
    pay->result[data.current][1] = pay->balance_changing;
    pay->result[data.current][2] = pay->receiving;
    pay->result[data.current][3] = pay->balance;

    pay->total[0] += pay->profit;
    pay->total[1] = pay->balance;
}
