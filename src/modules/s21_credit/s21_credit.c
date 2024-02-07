/**
 * @file s21_credit.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains the main function for calculating credit
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/s21_credit.h"

/*!
 * @brief Main function for calculating payments for all credit term.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[out] redemption structure containing data on early repayments.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
int calculate_credit(credit_init *data, payments *pay, early_pay *redemption) {
  int code_data = CHECK_NULL(data);
  int code_pay = CHECK_NULL(pay);
  int code = code_data + code_pay;

  if (code == ALLOCATED) {
    if (redemption) {
      redemption->current = 0;
    }

    code = init_payments(&pay->result, &pay->total);
  }

  if (code == ALLOCATED) {
    calculate_payments(data, pay, redemption);
  }

  return code;
}
