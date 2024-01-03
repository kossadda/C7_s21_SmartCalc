#include "s21_credit.h"

/**
 * @brief A function that writes the result of each month to an array.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
*/
void remember_result(credit_init *data, payments *pay)
{
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
}

// Пока под вопросом, плюсы пока используют эту статическую функцию вне класса, возможно стоит ее добавить там, а здесь применять исключительно в тестах.

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
    redemption->date = (time_data *)malloc(1 * sizeof(time_data));
    int error_code_date = CHECK_NULL(redemption->date);
    redemption->sum = (long double *)malloc(1 * sizeof(long double));
    int error_code_sum = CHECK_NULL(redemption->sum);
    redemption->type = (int *)malloc(1 * sizeof(int));
    int error_code_type = CHECK_NULL(redemption->type);
    error_code = error_code_date + error_code_sum + error_code_type;
    redemption->count = 0;
    redemption->current = 0;
    return error_code;
}
