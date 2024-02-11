/**
 * @file deposit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for all deposit calculator modules.
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef C_DEPOSIT_H_
#define C_DEPOSIT_H_

#include "./common.h"

///@brief List defining constant status for functions used in the deposit calc.
enum deposit_functions_status {
  NOT_CAPITAL = 0,  ///< Account capitalization included.
  CAPITAL = 1,      ///< Account capitalization is disabled.

  REFILL = 0,       ///< Deposit refill operation.
  WITHDRAWALS = 1,  ///< Deposit partial withdrawal operation.

  TAX_RATE = 16,          ///< Current interest rate (from the central bank).
  NDFL_RATE = 13,         ///< Current tax interest rate (NDFL).
  NON_TAX_SUM = 1000000,  ///< Current tax-free amount of income.
};

///@brief Struct representing the monthly and total return of the deposit.
typedef struct {
  long double profit;            ///< Deposit return for the current period.
  long double balance_changing;  ///< Change in the amount in current period.
  long double receiving;         ///< Profit received that doesnt go to balance.
  long double balance;           ///< Amount deposited in the current period.
  long double **result;          ///< An array of all the above main fields.
  long double *total;            ///< An array all period results are added up.
  long double **taxes;           ///< An array containing the tax costs.
  int taxes_count;               ///< Number of tax periods.
} investment;

///@brief Struct representing init information about the deposit.
typedef struct {
  long double amount;  ///< Amount deposited.
  long double rate;    ///< Deposit interest rate.
  time_data date;      ///< Date of deposit placement
  int term;            ///< Deposit term.
  int term_type;       ///< Type of calculation of the period (days/months).
  int capital_time;    ///< Frequency of capitalization
  int capital;         ///< Interest capitalization status.
  int current;         ///< Counter that tracks actual number of payment period.
} deposit_init;

///@brief Struct representing init information about partial refill/withdrawals.
typedef struct {
  time_data *date;          ///< An array containing all operations dates.
  long double *sum;         ///< An array containing all operations amounts.
  int *type;                ///< An array containing all types of operations.
  long double min_balance;  ///< The amount below which cannot remain.
  int count;                ///< Number of operations.
  int current;              ///< Counter that tracks number of operation made.
} operations;

// Main functions

int calculate_deposit(deposit_init *data, investment *pay, operations *oper);
int calc_period(deposit_init *data, investment *pay, time_data end_period,
                long double percent);
void write_results(deposit_init data, investment *pay);
int check_operation(deposit_init *data, investment *pay, operations *oper,
                    time_data *end_period, long double *percent);
int check_taxes(deposit_init *data, investment *pay, time_data end,
                time_data last, long double *year_profit,
                long double non_taxable_amount, int begin_year);

#endif