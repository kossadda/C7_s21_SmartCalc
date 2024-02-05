/**
 * @file s21_common.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for all common deposit and credit calculator modules.
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef S21_C_COMMON_H_
#define S21_C_COMMON_H_

#include <math.h>
#include <stdlib.h>

///@brief Check pointer for NULL.
#define CHECK_NULL(ptr) (ptr == NULL)

///@brief Contains constants for calendar functions.
enum calendar_constants {
  JAN = 31,       ///< Number of days in January.
  FEB = 28,       ///< Number of days in February.
  MAR = 31,       ///< Number of days in March.
  APR = 30,       ///< Number of days in April.
  LEAP_FEB = 29,  ///< Number of days in leap Feabruary.
  MAY = 31,       ///< Number of days in May.
  JUN = 30,       ///< Number of days in June.
  JUL = 31,       ///< Number of days in Jule.
  AUG = 31,       ///< Number of days in August.
  SEP = 30,       ///< Number of days in September.
  OCT = 31,       ///< Number of days in October.
  NOV = 30,       ///< Number of days in November.
  DEC = 31,       ///< Number of days in December.

  QUADRICENTENARY = 400,  ///< Quadricentenary interval.
  CENTURY = 100,          ///< Century interval.
  LEAP_INTERVAL = 4,      ///< Leap year interval.
  YEAR_DAYS = 365,        ///< Number of days in a normal year.
  LEAP_YEAR = 366,        ///< Number of days in a leap year

  DATE_OUTSIDE = 0,  ///< Day outside the specified interval.
  DATE_BETWEEN = 1,  ///< Day in the specified interval.

  DATE_EQUAL = 0,   ///< The two dates given are the same.
  DATE_BEFORE = 1,  ///< The first date is less than the second.
  DATE_AFTER = 2,   ///< The first date is greater than the second.

  BY_DAY = -1,        ///< Shift the current period by a day.
  BY_WEEK = -2,       ///< Shift the current period by a week.
  BY_MONTH = -3,      ///< Shift the current period by a deposit month.
  BY_QUARTER = -4,    ///< Shift the current period by a quarter.
  BY_HALFYEAR = -5,   ///< Shift the current period by a halfyear.
  BY_YEAR = -6,       ///< Shift the current period by a year.
  BY_END_TERM = -7,   ///< Shift the current period by end term.
  CREDIT_MONTH = -8,  ///< Shift the current period by a credit month.

  DAY = 1,       ///< Number of days when period shifts by day.
  WEEK = 7,      ///< Number of days when period shifts by week.
  MONTH = 1,     ///< Number of months when period shifts by month.
  QUARTER = 3,   ///< Number of months when period shifts by quarter.
  HALFYEAR = 6,  ///< Number of months when period shifts by halfyear.
  YEAR = 12,     ///< Number of months when period shifts by year.

  DAYS_PERIOD = 0,    ///< The entry period is indicated in days.
  MONTHS_PERIOD = 1,  ///< The input period is indicated in months.
};

///@brief Contains common constants for deposit and credit calculators.
enum common_constants {
  YEAR_NOT_LEAP = 0,  ///< This year is a leap year.
  YEAR_IS_LEAP = 1,   ///< This year is not a leap year.

  ALLOCATED = 0,      ///< Memory was allocated successfully.
  NOT_ALLOCATED = 1,  ///< Memory was allocated unsuccessfully.

  CREDIT_COLUMNS = 4,   ///< Select the number of columns for the credit table.
  DEPOSIT_COLUMNS = 4,  ///< Select the number of columns for the deposit table.
  TAXES_COLUMNS = 5,    ///< Select the number of columns for the tax table.
};

///@brief Struct representing data about a specific day.
typedef struct {
  int day;         ///< Day of the month.
  int month;       ///< Month of the year.
  int year;        ///< Year of this date.
  int leap;        ///< Contains information whether the year is a leap year.
  int month_days;  ///< Number of days included in the monthly payment period.
} time_data;

// Calendar checks.

int check_leap(int year);
int compare_date_with_month(time_data now, time_data *pay, time_data next);
int compare_dates(time_data first, time_data second);

// Calendar arithmetic.

void add_one_period(time_data *begin, time_data *end, time_data last_day,
                    int capital_type, int const_date);
int sub_till_end_month(time_data date);
int sub_date(time_data first, time_data second);
int days_in_this_year(time_data date);
void leap_days_between_dates(time_data *first, time_data *second);
time_data determine_last_day(time_data date, int term_type, int term);

// Another functions.

int init_payments(long double ***result, long double **total);
int allocate_row(long double ***result, int current, int columns);
long double percent_formula(long double debt, long double rate, int leap,
                            int month_days);
long double round_value(long double number);

#endif
