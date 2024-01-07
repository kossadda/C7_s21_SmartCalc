#include "s21_deposit.h"
#include <stdio.h>

static int compare_date_with_period(time_data begin, time_data *oper, time_data end);
static int check_operation(deposit_init *data, investment *pay, operations *oper, time_data *end_period, long double *percent);


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
void calculate_deposit(deposit_init *data, investment *pay, operations *oper)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    int const_day = data->date.day;
    time_data last_day = determine_last_day(data->date, data->term_type, data->term);

    if(error_code == ALLOCATED) {
        if(oper) {
            oper->current = 0;
        }

        data->date.leap = check_leap(data->date.year);

        error_code = init_payments(&pay->result, &pay->total);
    }

    if(error_code == ALLOCATED) {
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            long double percent = 0;

            time_data end_period = data->date;
            add_one_period(&(data->date), &end_period, last_day, data->capital_time, const_day);

            check_operation(data, pay, oper, &end_period, &percent);

            error_code = calc_period(data, pay, end_period, percent);
            
            data->date = end_period;

            data->date = (error_code == ALLOCATED) ? data->date : last_day;
        }
    }
}

/**
 * @brief Determines whether the current early repayment is within the current month and calculates it.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] redemption structure containing data on early repayments.
 * @param[in] next_month structure containing the payment end date for the current month.
 * @param[in] paid_percent the amount deducted from the monthly interest in case of early repayment.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int check_operation(deposit_init *data, investment *pay, operations *oper, time_data *end_period, long double *percent)
{
    int error_code = ALLOCATED;

    if(oper && oper->count && oper->current < oper->count) {
        while(compare_date_with_period(data->date, &(oper->date[oper->current]), *end_period) == DATE_BETWEEN) {
            data->current++;
            error_code = allocate_row(&pay->result, data->current);

            *percent += calc_period_percent(data, &data->date, &(oper->date[oper->current]), end_period);

            pay->balance_changing = oper->sum[oper->current];
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

static int compare_date_with_period(time_data begin, time_data *oper, time_data end)
{
    int day_between = DATE_OUTSIDE;

    if(compare_dates(*oper, begin) != DATE_BEFORE && compare_dates(*oper, end) == DATE_BEFORE) {
        day_between = DATE_BETWEEN;
        oper->leap = check_leap(oper->year);
        oper->month_days = 0;
    }

    return day_between;
}

long double calc_period_percent(deposit_init *data, time_data *begin, time_data *oper, time_data *end)
{
    long double percent = 0;

    leap_days_between_dates(begin, oper);

    long double first_part = percent_formula(data->amount, data->rate, begin->leap, begin->month_days);
    percent = percent_formula(data->amount, data->rate, oper->leap, oper->month_days) + first_part;
    
    leap_days_between_dates(oper, end);

    *begin = *oper;
    
    return percent;
}

