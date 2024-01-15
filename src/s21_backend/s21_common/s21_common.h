/**
 * @file s21_common.h
 * @author kossadda (https://github.com/kossadda)
 * @brief 
 * @version 0.1
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef S21_C_COMMON_
#define S21_C_COMMON_

#include <math.h>
#include <stdlib.h>

#define CHECK_NULL(ptr) (ptr == NULL)

enum calendar_constants {
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
//  Date between two dates status.
    DATE_OUTSIDE = 0, DATE_BETWEEN = 1,
//  Dates compare status.
    DATE_EQUAL = 0, DATE_BEFORE = 1, DATE_AFTER = 2,
//  Type of frequency of capitalization.
    BY_DAY      = -1, BY_WEEK = -2, BY_MONTH    = -3, BY_QUARTER   = -4,
    BY_HALFYEAR = -5, BY_YEAR = -6, BY_END_TERM = -7, CREDIT_MONTH = -8,
//  Numerical representation of capitalization periodicity.
    DAY = 1, WEEK = 7, MONTH = 1, QUARTER = 3, HALFYEAR = 6, YEAR = 12,
//  Type of term.
    DAYS_PERIOD = 0, MONTHS_PERIOD = 1,
};

enum common_constants {
//  Year leap status.
    YEAR_NOT_LEAP = 0, YEAR_IS_LEAP = 1,
//  Allocate memory status.
    ALLOCATED = 0, NOT_ALLOCATED = 1,
//  Number of result columns.
    CREDIT_COLUMNS = 4, DEPOSIT_COLUMNS = 4, TAXES_COLUMNS = 5,
};

/*!
 * @brief Struct representing data about a specific day.
*/
typedef struct time_data {
    int day;                    /**< Day of the month.                                                   */
    int month;                  /**< Month of the year.                                                  */
    int year;                   /**< Year of this date.                                                  */
    int leap;                   /**< Contains information whether the year is a leap year.               */
    int month_days;             /**< Number of days of the month included in the monthly payment period. */
} time_data;

// Calendar checks.

int check_leap(int year);
int compare_date_with_month(time_data now, time_data *pay, time_data next);
int compare_dates(time_data first, time_data second);

// Calendar arithmetic.

void add_one_period(time_data *begin, time_data *end, time_data last_day, int capital_type, int const_date);
int sub_till_end_month(time_data date);
int sub_date(time_data first, time_data second);
int days_in_this_year(time_data date);
void leap_days_between_dates(time_data *first, time_data *second);
time_data determine_last_day(time_data date, int term_type, int term);

// Another functions.

int init_payments(long double ***result, long double **total);
int allocate_row(long double ***result, int current, int columns);
long double percent_formula(long double debt, long double rate, int leap, int month_days);
long double round_value(long double number);

#endif
