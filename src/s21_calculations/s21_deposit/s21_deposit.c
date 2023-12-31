#include "s21_deposit.h"
#include "stdio.h"

static int init_investment(investment *pay);
static int calc_period(init *data, investment *pay, time_data end_period);
static int allocate_row(init *data, investment *pay);
static void write_results(init data, investment *pay);
static void calc_profit(init data, investment *pay, time_data end_period);

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
void calculate_deposit(init *data, investment *pay)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    time_data last_day = determine_last_day(data->date, data->term_type, data->term);
    

    if(error_code == ALLOCATED) {
        data->date.leap = check_leap(data->date.year);

        error_code = init_investment(pay);
    }

    if(error_code == ALLOCATED) {
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            time_data end_period = data->date;
            add_one_period(&(data->date), &end_period, last_day, data->capital_time);

            error_code = calc_period(data, pay, end_period);
            
            data->date = end_period;
            data->current = (error_code == ALLOCATED) ? data->current : data->term;
        }
    }
}

/**
 * @brief Function for determining all payments for a certain period.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param end_period period end date.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int calc_period(init *data, investment *pay, time_data end_period)
{
    int error_code = ALLOCATED;
    data->current++;
    error_code = allocate_row(data, pay);
    if(error_code == ALLOCATED) {
        calc_profit(*data, pay, end_period);
        if(data->capital == CAPITAL) {
            pay->balance_changing = pay->profit;
            pay->receiving = 0;
            data->amount += pay->profit;
        } else if(data->capital == NOT_CAPITAL) {
            pay->balance_changing = 0;
            pay->receiving = pay->profit;
        }
        pay->balance = data->amount;
        write_results(*data, pay);
    }
    return error_code;
}

/**
 * @brief The function calculates the percentage of profit for the month.
 * 
 * @param data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param end_period period end date.
*/
static void calc_profit(init data, investment *pay, time_data end_period) {
    long double first_part_month = (data.amount * data.rate / 100) / ((data.date.leap) ? LEAP_YEAR : YEAR_DAYS) * data.date.month_days;
    long double second_part_month = (data.amount * data.rate / 100) / ((end_period.leap) ? LEAP_YEAR : YEAR_DAYS) * end_period.month_days;
    pay->profit = round((first_part_month + second_part_month) * 100) / 100;
}

/**
 * @brief Function for allocating memory in an array for the next payout period.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int allocate_row(init *data, investment *pay)
{
    int error_code = NOT_ALLOCATED;
    pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
    int error_code_row = CHECK_NULL(pay->result);
    pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
    int error_code_column = CHECK_NULL(pay->result[data->current]);
    error_code = error_code_row + error_code_column;
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
static int init_investment(investment *pay)
{
    int error_code = NOT_ALLOCATED;

    pay->total = (long double *)malloc(2 * sizeof(long double));
    int error_code_total = CHECK_NULL(pay->total);
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    int error_code_result = CHECK_NULL(pay->result);

    error_code = error_code_total + error_code_result;

    pay->total[0] = 0;
    pay->total[1] = 0;

    return error_code;
}

/**
 * @brief A function that writes the result of each month to an array.
 * 
 * @param data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
*/
static void write_results(init data, investment *pay)
{
    pay->result[data.current][0] = pay->profit;
    pay->result[data.current][1] = pay->balance_changing;
    pay->result[data.current][2] = pay->receiving;
    pay->result[data.current][3] = pay->balance;

    pay->total[0] += pay->profit;
    pay->total[1] = pay->balance;
}
