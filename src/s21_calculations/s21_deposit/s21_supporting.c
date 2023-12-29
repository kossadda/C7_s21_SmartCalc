#include "s21_deposit.h"

// int init_massive(payments *pay)
// {
//     int error_code = NOT_ALLOCATED;
//     int error_code_total = NOT_ALLOCATED;
//     int error_code_result = NOT_ALLOCATED;
//     pay->total = (long double *)malloc(3 * sizeof(long double));
//     error_code_total = CHECK_NULL(pay->total);
//     pay->result = (long double **)malloc(1 * sizeof(long double *));
//     error_code_result = CHECK_NULL(pay->result);
//     error_code = error_code_total + error_code_result;
//     pay->total[0] = 0;
//     pay->total[1] = 0;
//     pay->total[2] = 0;
//     return error_code;
// }