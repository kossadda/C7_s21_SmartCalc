#include "s21_deposit.h"

/**
 * @brief Function to define a year as a leap year.
 * 
 * @param year verified year.
 * 
 * @return Information about the leap year.
 * @retval YEAR_NOT_LEAP = 0 - in the case of a normal year.
 * @retval YEAR_IS_LEAP = 1 - in the case of a leap year.
*/
int check_leap(int year)
{
    int leap = YEAR_NOT_LEAP;
    if(year % QUADRICENTENARY == 0) {
        leap = YEAR_IS_LEAP;
    } else if(year % LEAP_INTERVAL == 0 && year % CENTURY != 0) {
        leap = YEAR_IS_LEAP;
    }
    return leap;
}

/**
 * @brief Function for determining date structure parameters for this and next month.
 * 
 * @param[in] this_month structure containing the payment start date for the current month.
 * @param[in] next_month structure containing the payment end date for the current month.
*/
void determine_date(time_data *this_month, time_data *next_month)
{
    this_month->leap = check_leap(this_month->year);
    next_month->leap = check_leap(next_month->year);
    this_month->month_days = sub_till_end_month(*this_month);
    next_month->month_days = next_month->day;
}

/**
 * @brief A function that determines the correct logic for adding a month to the current date.
 * 
 * @param[in] date structure containing the current date, the number of days in the month and a leap year variable.
 * @param beginning_date the original date received as input from the user.
*/
void add_month(time_data *date, int beginning_date)
{
    date->month += 1;
    if(date->month > 12) {
        date->month = 1;
        date->year += 1;
    }
    
    int days[] = {0, JAN, (check_leap(date->year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

    if(date->day != beginning_date) {
        date->day = beginning_date;
    }
    if(date->day > days[date->month]) {
        date->day = days[date->month];
    }
}

/**
 * @brief Determines whether the current maturity date is within the range of the current payment month.
 * 
 * @param now beginning of the payment period of the current month.
 * @param[in] pay early repayment date.
 * @param next end of the current month's payment period.
 * 
 * @return Information about the position of early payment date.
 * @retval DATE_OUTSIDE = 0 - if early_payment outside of current month.
 * @retval DATE_BETWEEN = 1 - if early_payment outside in the current month.
*/
// int compare_date_with_month(time_data now, time_data *pay, time_data next)
// {
//     int day_between = DATE_OUTSIDE;
//     if(pay->year == now.year || pay->year == next.year) {
//         if(pay->month == now.month && pay->day >= now.day) {
//             day_between = DATE_BETWEEN;
//             pay->month_days = sub_date(*pay, now);
//         } else if(pay->month == next.month && pay->day < next.day) {
//             day_between = DATE_BETWEEN;
//             pay->month_days = sub_date(*pay, now);
//         }
//         pay->leap = check_leap(pay->year);
//     }
//     return day_between;
// }

/**
 * @brief Determines how many days from the current date to the beginning of the current year.
 * 
 * @param date date from which the count is made.
 * 
 * @return Number of days in a year.
*/
static int days_in_this_year(time_data date)
{
    int days[] = {0, JAN, (check_leap(date.year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    int days_in_year = date.day;
    for(int i = 1; i < date.month; i++) {
        days_in_year += days[i];
    }
    return days_in_year;
}

/**
 * @brief Subtracts two dates.
 * 
 * @param first the date from which you need to subtract.
 * @param second date to be subtracted.
 * 
 * @return Number of days between two dates.
*/
int sub_date(time_data first, time_data second)
{
    int difference = 0;
    if(first.year == second.year) {
        difference = days_in_this_year(first) - days_in_this_year(second);
    } else {
        difference = days_in_this_year(first) + (((second.leap) ? LEAP_YEAR : YEAR) - days_in_this_year(second));
        for(int i = second.year + 1; i != first.year; i++) {
            difference += (check_leap(i)) ? LEAP_YEAR : YEAR;
        }
    }
    return difference;
}

/**
 * @brief Determines the number of days from the current date to the end of the current month.
 * 
 * @param date date from which the count is made.
 * 
 * @return Number of days until the end of the current month.
*/
int sub_till_end_month(time_data date)
{
    int days[] = {0, JAN, (date.leap) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    time_data last_day_month = date;
    last_day_month.day = days[date.month];
    return sub_date(last_day_month, date);
}