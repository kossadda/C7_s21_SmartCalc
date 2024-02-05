/**
 * @file s21_credit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for all credit calculator modules.
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef S21_C_CREDIT_H_
#define S21_C_CREDIT_H_

#include "./s21_common.h"

///@brief List defining constant statuses for functions used in the credit calc
enum credit_functions_status {
  DEBT_NOT_CHANGED = 0,  ///< Signals that the debt balance has not changed.
  DEBT_CHANGED = 1,      ///< Signals that the debt balance has changed

  ANNUITY = 0,         ///< Annuity type of monthly payments.
  DIFFERENTIATED = 1,  ///< Differentiated type of monthly payments.
  NOT_CHOSEN = 2,      ///< Type not selected (constant for front).

  REDUCE_TERM = 0,  ///< Early repayment to reduce the credit term.
  REDUCE_PAY = 1,   ///< Early repayment to reduce monthly payment.
};

///@brief Struct representing monthly and overall payment results.
typedef struct {
  long double main;        ///< Amount to pay the principal for the month.
  long double percent;     ///< Monthly interest payment amount.
  long double monthly;     ///< Total payment for the month.
  long double const_main;  ///< Buffer variable for save principal payment.
  long double **result;    ///< An array of all the above main fields.
  long double *total;      ///< An array where all monthly results are added up.
} payments;

/*!
 * @brief Struct representing init information about the credit.
 */
typedef struct {
  long double debt;  ///< Sets the credit amount/help track balance of the debt.
  long double rate;  ///< Credit interest rate.
  time_data date;    ///< Date of credit issue.
  int payment_type;  ///< Type of monthly payments.
  int months;        ///< Credit terms.
  int current;       ///< Counter that tracks actual number of months lending.
} credit_init;

///@brief Struct representing init information about early repayments.
typedef struct {
  time_data *date;   ///< An array containing all early repayment dates.
  long double *sum;  ///< An array containing all early repayment amounts.
  int *type;         ///< An array containing all types of early repayments.
  int count;         ///< Number of early repayments.
  int current;       ///< Counter that tracks actual number of repayments made.
} early_pay;

// Main functions

int calculate_credit(credit_init *data, payments *pay, early_pay *redemption);
int calculate_payments(credit_init *data, payments *pay, early_pay *redemption);
int redemp_payment(credit_init *data, payments *pay, early_pay *redemption,
                   time_data *next_month, long double *paid_percent,
                   int *change);

// Support functions

void remember_result(credit_init *data, payments *pay);

#endif
