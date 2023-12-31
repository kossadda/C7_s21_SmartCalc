#ifndef S21_C_CREDIT_H
#define S21_C_CREDIT_H

#include "../s21_common/s21_common.h"

#include <math.h>
#include <stdlib.h>

#define CHECK_NULL(ptr) (ptr == NULL)

/**
 * @brief List defining constant statuses for functions used in the credit calculator.
*/
enum credit_functions_status {
//  Changing of debt status.
    DEBT_NOT_CHANGED = 0, DEBT_CHANGED = 1,
//  Type of main payments.
    ANNUITY = 0, DIFFERENTIATED = 1, NOT_CHOSEN = 2,
//  Type of early payments.
    REDUCE_TERM = 0, REDUCE_PAY = 1,
};

/**
 * @brief Struct representing monthly and overall payment results.
*/
typedef struct payments {
    long double main;           /** Amount to pay the principal for the month.                                      */
    long double percent;        /** Monthly interest payment amount.                                                */
    long double monthly;        /** Total payment for the month.                                                    */
    long double const_main;     /** Buffer variable for remembering principal payment.                              */
    long double **result;       /** An array of all the above main fields of the structure for storing the results. */
    long double *total;         /** An array where all monthly results are added up.                                */
} payments;

/**
 * @brief Struct representing initial information about the credit.
*/
typedef struct initial {
    long double debt;           /** Sets the credit amount and subsequently helps track the balance of the debt. */
    long double rate;           /** Credit interest rate.                                                        */
    time_data date;             /** Date of credit issue.                                                        */
    int payment_type;           /** Type of monthly payments.                                                    */
    int months;                 /** Credit terms.                                                                */
    int current;                /** A counter that tracks the actual number of months of lending.                */
} initial;

/**
 * @brief Struct representing initial information about early repayments.
*/
typedef struct early_pay {
    time_data *date;            /** An array containing all early repayment dates.              */
    long double *sum;           /** An array containing all early repayment amounts.            */
    int *type;                  /** An array containing all types of early repayments.          */
    int count;                  /** Number of early repayments.                                 */
    int current;                /** A counter that tracks the actual number of repayments made. */
} early_pay;

// Main functions

int calculate_credit(initial *data, payments *pay, early_pay *redemption);
int calculate_payments(initial *data, payments *pay, early_pay *redemption);
int redemp_payment(initial *data, payments *pay, time_data *next_month, early_pay *redemption, long double *paid_percent, int *change);

// Support functions

void calc_percent(initial *data, payments *pay, time_data next_month);
long double round_value(long double number);
void remember_result(initial *data, payments *pay);
int init_redemption(early_pay *redemption);
int allocate_memory(initial *data, payments *pay);

// Calendar functions

void determine_date(time_data *this_month, time_data *next_month);
int check_leap(int year);
void add_month(time_data *date, int beginning_date);
int compare_date_with_month(time_data now, time_data *pay, time_data next);
int sub_date(time_data first, time_data second);
int sub_till_end_month(time_data date);

#endif
