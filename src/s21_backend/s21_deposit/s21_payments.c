/// \file
#include "s21_deposit.h"

static long double calc_period_percent(deposit_init *data, time_data *begin, time_data *oper, time_data *end);

/*!
 * @brief Determines whether the current early repayment is within the current month and calculates it.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for period results and general payment data arrays.
 * @param[out] oper structure containing data on deposit/withdrawal operations.
 * @param[out] end_period structure containing the payment end date for the current period.
 * @param[out] percent the amount accumulated before the expected replenishment/withdrawal in the current period.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int check_operation(deposit_init *data, investment *pay, operations *oper, time_data *end_period, long double *percent)
{
    int error_code = ALLOCATED;

    if(oper && oper->count && oper->current < oper->count) {
        while(compare_dates(oper->date[oper->current], data->date) != DATE_BEFORE && compare_dates(oper->date[oper->current], *end_period) == DATE_BEFORE) {
            data->current++;
            error_code = allocate_row(&pay->result, data->current, DEPOSIT_COLUMNS);

            long double oper_sum = oper->sum[oper->current];

            if((data->amount < oper_sum || data->amount - oper_sum < oper->min_balance) && oper->type[oper->current] == WITHDRAWALS) {
                pay->balance_changing = 0;
            } else {
                *percent += calc_period_percent(data, &data->date, &(oper->date[oper->current]), end_period);

                if(oper->type[oper->current] == REFILL) {
                    pay->balance_changing = oper->sum[oper->current];
                } else if(oper->type[oper->current] == WITHDRAWALS) {
                    pay->balance_changing = oper->sum[oper->current] * (-1.0);
                }
            }

            pay->balance = data->amount + pay->balance_changing;
            pay->profit = 0;
            pay->receiving = 0;

            write_results(*data, pay);
            
            data->amount += pay->balance_changing;
            oper->current++;
            
            if(oper->current == oper->count) {
                break;
            }
        }
    }
    
    return error_code;
}

/*!
 * @brief Calculates and records the transaction, remembering the accumulated amount before the transaction.
 * 
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] begin structure containing information about the beginning of the current period.
 * @param[out] operstructure containing information about the operation.
 * @param[out] end structure containing information about the end of the current period.
 * 
 * @return The amount accumulated before the operation.
*/
static long double calc_period_percent(deposit_init *data, time_data *begin, time_data *oper, time_data *end)
{
    long double percent = 0;

    leap_days_between_dates(begin, oper);

    percent = percent_formula(data->amount, data->rate, begin->leap, begin->month_days);
    percent += percent_formula(data->amount, data->rate, oper->leap, oper->month_days);
    
    leap_days_between_dates(oper, end);

    *begin = *oper;
    
    return percent;
}
