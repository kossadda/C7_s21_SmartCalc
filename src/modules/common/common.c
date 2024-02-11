/**
 * @file common.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains all the common functions for the credit and
 * deposit modules
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/common.h"

/*!
 * @brief Rounds a long double number to the nearest e-2.
 *
 * @param[in] number rounded number.
 *
 * @return long double - result of rounding.
 */
long double round_value(long double number) {
  return round(number * 100) / 100;
}

/*!
 * @brief Function initializing a data array.
 *
 * @param[out] result an array of all the above main fields of the structure for
 * storing the results.
 * @param[out] total an array where all monthly results are added up.
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
int init_payments(long double ***result, long double **total) {
  int code = NOT_ALLOCATED;

  *total = (long double *)malloc(3 * sizeof(long double));
  int code_total = CHECK_NULL(*total);
  *result = (long double **)malloc(1 * sizeof(long double *));
  int code_result = CHECK_NULL(*result);

  code = code_total + code_result;

  (*total)[0] = 0;
  (*total)[1] = 0;
  (*total)[2] = 0;

  return code;
}

/*!
 * @brief Function for allocating memory in an array for the next payout period.
 *
 * @param[out] result an array of all the above main fields of the structure for
 * storing the results.
 * @param[in] current number of rows.
 * @param[in] columns
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
int allocate_row(long double ***result, int current, int columns) {
  int code = NOT_ALLOCATED;

  *result =
      (long double **)realloc(*result, (current + 1) * sizeof(long double *));
  int code_row = CHECK_NULL(*result);

  (*result)[current] = (long double *)malloc(columns * sizeof(long double));
  int code_column = CHECK_NULL((*result)[current]);

  code = code_row + code_column;

  if (code == ALLOCATED) {
    for (int i = 0; i < columns; i++) {
      (*result)[current][i] = 0;
    }
  }

  return code;
}

/*!
 * @brief Function for allocating memory in an array for the next payout period.
 *
 * @param[out] debt the balance of the debt.
 * @param[out] rate credit interest rate.
 * @param[out] leap contains information that the year is a leap year.
 * @param[out] month_days how many days are counted.
 * @return long double - calculation result.
 */
long double percent_formula(long double debt, long double rate, int leap,
                            int month_days) {
  return (debt * rate / 100) /
         ((leap == YEAR_IS_LEAP) ? LEAP_YEAR : YEAR_DAYS) * month_days;
}
