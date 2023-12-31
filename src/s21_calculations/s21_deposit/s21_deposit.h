#ifndef S21_C_DEPOSIT_H
#define S21_C_DEPOSIT_H

#include <math.h>
#include <stdlib.h>

#define CHECK_NULL(ptr) (ptr == NULL)

enum constants {
//  days constants
    JAN = 31, FEB = 28, MAR = 31, APR = 30, LEAP_FEB = 29,
    MAY = 31, JUN = 30, JUL = 31, AUG = 31,
    SEP = 30, OCT = 31, NOV = 30, DEC = 31,
//  another constants
    QUADRICENTENARY = 400, 
    CENTURY         = 100,
    LEAP_INTERVAL   =   4, 
    YEAR_DAYS       = 365,
    LEAP_YEAR       = 366,
};

enum deposit_functions_status {
//  Year leap status.
    YEAR_NOT_LEAP = 0, YEAR_IS_LEAP = 1,
//  Allocate memory status.
    ALLOCATED = 0, NOT_ALLOCATED = 1,
//  Type of term.
    DAYS_PERIOD = 0, MONTHS_PERIOD = 1,
//  Type of frequency of capitalization.
    BY_DAY     = 0, BY_WEEK     = 1, BY_MONTH  = 2, 
    BY_QUARTER = 3, BY_HALFYEAR = 4, BY_YEAR   = 5,
//  Numerical representation of capitalization periodicity.
    DAY = 1, WEEK = 7, MONTH = 1, QUARTER = 3, HALFYEAR = 6, YEAR = 12,
//  Dates compare status.
    DATE_EQUAL = 0, DATE_BEFORE = 1, DATE_AFTER = 2,
};

/**
 * @brief Struct representing data about a specific day.
*/
typedef struct time_data {
    int day;                            /** Day of the month.                                                   */
    int month;                          /** Month of the year.                                                  */
    int year;                           /** Year of this date.                                                  */
    int leap;                           /** Contains information whether the year is a leap year.               */
    int month_days;                     /** Number of days of the month included in the monthly payment period. */
} time_data;

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
typedef struct init {
    long double amount;                 /** Amount deposited.                                           */
    long double rate;                   /** Deposit interest rate.                                      */
    time_data date;                     /** Date of deposit placement                                   */
    int term;                           /** Deposit term.                                               */
    int term_type;                      /** Type of calculation of the period (days/months, etc.)       */
    int capital_time;                   /** Frequency of capitalization                                 */
    int capital;                        /** Interest capitalization status.                             */
    int current;                        /** A counter that tracks the actual number of payment periods. */
} init;

// Main functions

void calculate_deposit(init *depos, investment *pay);

// Calendar functions

void determine_date(time_data *this_month, time_data *next_month);
int check_leap(int year);
void add_days(time_data *date, int term);
void add_months(time_data *date, int term, int beginning_date);
int sub_date(time_data first, time_data second);
int sub_till_end_month(time_data date);
int days_in_this_year(time_data date);
void add_one_period(time_data *begin, time_data *end, time_data last_day, int capital_type);

#endif