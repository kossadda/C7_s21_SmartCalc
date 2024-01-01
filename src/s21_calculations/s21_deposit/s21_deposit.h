#ifndef S21_C_DEPOSIT_H
#define S21_C_DEPOSIT_H

#include "../s21_common/s21_common.h"

/**
 * @brief List defining constant statuses for functions used in the deposit calculator.
*/
enum deposit_functions_status {
//  Deposit capitalization enabled/disabled.
    NOT_CAPITAL = 0, CAPITAL = 1,
};

/**
 * @brief Struct representing the monthly and total return of the deposit
*/
typedef struct investment {
    long double profit;                 /** Deposit return for the current period                                           */
    long double balance_changing;       /** Change in the amount held on deposit in the current period.                     */
    long double receiving;              /** Profit received that does not go to the deposit balance.                        */
    long double balance;                /** Amount deposited in the current period.                                         */
    long double **result;               /** An array of all the above main fields of the structure for storing the results. */
    long double *total;                 /** An array where all period results are added up.                                 */
} investment;

/**
 * @brief Struct representing initial information about the deposit.
*/
typedef struct deposit_init {
    long double amount;                 /** Amount deposited.                                           */
    long double rate;                   /** Deposit interest rate.                                      */
    time_data date;                     /** Date of deposit placement                                   */
    int term;                           /** Deposit term.                                               */
    int term_type;                      /** Type of calculation of the period (days/months, etc.)       */
    int capital_time;                   /** Frequency of capitalization                                 */
    int capital;                        /** Interest capitalization status.                             */
    int current;                        /** A counter that tracks the actual number of payment periods. */
} deposit_init;

// Main functions

void calculate_deposit(deposit_init *depos, investment *pay);
int calc_period(deposit_init *data, investment *pay, time_data end_period);

#endif