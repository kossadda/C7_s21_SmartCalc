#include "s21_credit.h"

/**
 * @brief A function that calculates what part of the monthly payment goes to interest.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param next_month structure containing the payment end date for the current month.
*/
void calc_percent(initial *data, payments *pay, time_data next_month)
{
    long double first_part_month = (data->debt * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days;
    long double second_part_month = (data->debt * data->rate / 100) / ((next_month.leap) ? LEAP_YEAR : YEAR) * next_month.month_days;
    pay->percent = round((first_part_month + second_part_month) * 100) / 100;
}

/**
 * @brief A function that writes the result of each month to an array.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
*/
void remember_result(initial *data, payments *pay)
{
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
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
int init_massive(payments *pay)
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

/**
 * @brief Function for initializing early repayment arrays.
 * 
 * @param[in] redemption structure containing data on early repayments.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int init_redemption(early_pay *redemption)
{
    int error_code = NOT_ALLOCATED;
    int error_code_date = NOT_ALLOCATED;
    int error_code_sum = NOT_ALLOCATED;
    int error_code_type = NOT_ALLOCATED;
    redemption->date = (time_data *)malloc(1 * sizeof(time_data));
    error_code = CHECK_NULL(redemption->date);
    redemption->sum = (long double *)malloc(1 * sizeof(long double));
    error_code = CHECK_NULL(redemption->sum);
    redemption->type = (int *)malloc(1 * sizeof(int));
    error_code = CHECK_NULL(redemption->type);
    error_code = error_code_date + error_code_sum + error_code_type;
    redemption->count = 0;
    redemption->current = 0;
    return error_code;
}

/**
 * @brief A function that allocates additional memory for an initialized array.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int allocate_memory(initial *data, payments *pay)
{
    int error_code = NOT_ALLOCATED;
    int error_code_row = NOT_ALLOCATED;
    int error_code_column = NOT_ALLOCATED;
    pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
    error_code_row = CHECK_NULL(pay->result);
    pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
    error_code_column = CHECK_NULL(pay->result[data->current]);
    error_code = error_code_row + error_code_column;
    return error_code;
}

/**
 * @brief Rounds a long double number to the nearest e-2.
 * 
 * @param number rounded number.
 * 
 * @return Result of rounding.
*/
long double round_value(long double number)
{
    return round(number * 100) / 100;
}