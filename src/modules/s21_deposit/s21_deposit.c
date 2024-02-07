/**
 * @file s21_deposit.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains the main function for calculating deposit
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/s21_deposit.h"

static int init_taxes(investment *pay);

/*!
 * @brief Main function for calculating payments for all deposit term.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[out] oper structure containing data on deposit/withdrawal operations.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
int calculate_deposit(deposit_init *data, investment *pay, operations *oper) {
  int code_depos = CHECK_NULL(data);
  int code_pay = CHECK_NULL(pay);
  int code = code_depos + code_pay;

  int const_day = data->date.day;
  time_data last_day =
      determine_last_day(data->date, data->term_type, data->term);

  if (code == ALLOCATED) {
    if (oper) {
      oper->current = 0;
    }
    data->date.leap = check_leap(data->date.year);

    int code_payments = init_payments(&pay->result, &pay->total);
    int code_taxes = init_taxes(pay);

    code = code_payments + code_taxes;
  }

  if (code == ALLOCATED) {
    time_data end_period = data->date;
    long double non_taxable_amount = NON_TAX_SUM * TAX_RATE / 100;
    long double year_profit = 0;

    for (data->current = -1;
         compare_dates(data->date, last_day) != DATE_EQUAL;) {
      long double percent = 0;
      int begin_year = data->date.year;

      add_one_period(&(data->date), &end_period, last_day, data->capital_time,
                     const_day);

      code = check_operation(data, pay, oper, &end_period, &percent);

      if (code == ALLOCATED) {
        code = calc_period(data, pay, end_period, percent);
      }

      if (code == ALLOCATED) {
        code = check_taxes(data, pay, end_period, last_day, &year_profit,
                           non_taxable_amount, begin_year);
      }

      data->date = (code == ALLOCATED) ? end_period : last_day;
    }
  }

  return code;
}

/*!
 * @brief Function initializing a taxes array.
 *
 * @param[out] pay structure containing buffer variables for taxes data arrays.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
static int init_taxes(investment *pay) {
  int code = NOT_ALLOCATED;

  pay->taxes = (long double **)malloc(1 * sizeof(long double *));
  code = CHECK_NULL(pay->taxes);

  pay->taxes_count = 0;

  return code;
}
