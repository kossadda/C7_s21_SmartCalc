#include "s21_common.h"

static void add_months(time_data *date, int term, int beginning_date);
static void add_days(time_data *date, int term);
static void move_to_end_term(time_data *begin, time_data *end);

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
int compare_date_with_month(time_data now, time_data *pay, time_data next)
{
    int day_between = DATE_OUTSIDE;
    if(pay->year == now.year || pay->year == next.year) {
        if(pay->month == now.month && pay->day >= now.day) {
            day_between = DATE_BETWEEN;
            pay->month_days = sub_date(*pay, now);
        } else if(pay->month == next.month && pay->day < next.day) {
            day_between = DATE_BETWEEN;
            pay->month_days = sub_date(*pay, now);
        }
        pay->leap = check_leap(pay->year);
    }
    return day_between;
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
        difference = days_in_this_year(first) + (((second.leap) ? LEAP_YEAR : YEAR_DAYS) - days_in_this_year(second));
        for(int i = second.year + 1; i != first.year; i++) {
            difference += (check_leap(i)) ? LEAP_YEAR : YEAR_DAYS;
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

/**
 * @brief Function comparing two dates.
 * 
 * @param first first date compared.
 * @param second second date compared.
 * 
 * @return Position of the first date relative to the second.
 * @retval DATE_EQUAL = 0 - if the dates are the same.
 * @retval DATE_BEFORE = 1 - if the first date is earlier than the second.
 * @retval DATE_AFTER = 2 - if the second date is earlier than the first.
*/
int compare_dates(time_data first, time_data second)
{
    int compare = DATE_EQUAL;

    if(first.year < second.year) {
        compare = DATE_BEFORE;
    } else if(first.year > second.year) {
        compare = DATE_AFTER;
    }
    if(compare == DATE_EQUAL) {
        if(first.month < second.month) {
            compare = DATE_BEFORE;
        } else if(first.month > second.month) {
            compare = DATE_AFTER;
        }
    }
    if(compare == DATE_EQUAL) {
        if(first.day < second.day) {
            compare = DATE_BEFORE;
        } else if(first.day > second.day) {
            compare = DATE_AFTER;
        }
    }

    return compare;
}

void leap_days_between_dates(time_data *first, time_data *second)
{
    int leap_days = 0;
    int normal_days = 0;
    first->leap = check_leap(first->year);
    second->leap = check_leap(second->year);

    if(first->year != second->year) {
        int first_date_years_day = (first->leap ? LEAP_YEAR : YEAR_DAYS) - days_in_this_year(*first);
        int second_date_years_day = days_in_this_year(*second);

        if(first->leap) {
            leap_days += first_date_years_day;
        } else {
            normal_days += first_date_years_day;
        }
        if(second->leap) {
            leap_days += second_date_years_day;
        } else {
            normal_days += second_date_years_day;
        }

        for(int i = first->year + 1; i < second->year; i++) {
            if(check_leap(i)) {
                leap_days += LEAP_YEAR;
            } else {
                normal_days += YEAR_DAYS;
            }
        }

        first->month_days = leap_days;
        first->leap = YEAR_IS_LEAP;

        second->month_days = normal_days;
        second->leap = YEAR_NOT_LEAP;
    } else {
        second->month_days = sub_date(*second, *first);
        first->month_days = 0;
    }
}

/**
 * @brief Defines the last day of the deposit.
 * 
 * @param date deposit opening date.
 * @param term_type what period is specified by the user (days/months).
 * @param term deposit term.
 * 
 * @return Last day of the deposit.
*/
time_data determine_last_day(time_data date, int term_type, int term)
{
    if(term_type == DAYS_PERIOD) {
        add_days(&date, term);
    } else if(term_type == MONTHS_PERIOD) {
        int const_date = date.day;
        add_months(&date, term, const_date);
    }

    return date;
}

/**
 * @brief Determines how many days from the current date to the beginning of the current year.
 * 
 * @param date date from which the count is made.
 * 
 * @return Number of days in a year.
*/
int days_in_this_year(time_data date)
{
    int days[] = {0, JAN, (check_leap(date.year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    int days_in_year = date.day;

    for(int i = 1; i < date.month; i++) {
        days_in_year += days[i];
    }

    return days_in_year;
}

/**
 * @brief Moves the specified date relative to the specified period.
 * 
 * @param[in] begin period start date.
 * @param[in] end period end date.
 * @param last_day deposit end day.
 * @param capital_type type of payment periodization.
*/
void add_one_period(time_data *begin, time_data *end, time_data last_day, int capital_type, int const_date)
{
    if(capital_type == BY_DAY) {
        add_days(end, DAY);
    } else if(capital_type == BY_WEEK) {
        add_days(end, WEEK);
    } else if(capital_type == BY_MONTH || capital_type == CREDIT_MONTH) {
        add_months(end, MONTH, const_date);
    } else if(capital_type == BY_QUARTER) {
        add_months(end, QUARTER, const_date);
    } else if(capital_type == BY_HALFYEAR) {
        add_months(end, HALFYEAR, const_date);
    } else if(capital_type == BY_YEAR) {
        add_months(end, YEAR, const_date);
    }

    if(capital_type != CREDIT_MONTH && compare_dates(*end, last_day) == DATE_AFTER) {
        *end = last_day;
    }

    if(capital_type == BY_END_TERM) {
        *end = last_day;
        move_to_end_term(begin, end);
    } else if(capital_type == CREDIT_MONTH) {
        begin->month_days = sub_till_end_month(*begin);
        end->month_days = end->day;
    } else {
        if(begin->leap == end->leap) {
            begin->month_days = sub_date(*end, *begin);
            end->month_days = 0;
        } else {
            begin->month_days = ((begin->leap) ? LEAP_YEAR : YEAR_DAYS) - days_in_this_year(*begin);
            end->month_days = days_in_this_year(*end);
        }
    }
}

/**
 * @brief A function that determines the number of days in leap years and ordinary years for a lump sum payment.
 * 
 * @param[in] begin deposit start date.
 * @param[in] end deposit end date.
*/
static void move_to_end_term(time_data *begin, time_data *end) {
    begin->month_days = 0;
    end->month_days = 0;

    if(begin->year == end->year) {
        begin->month_days = sub_date(*end, *begin);;
    } else {
        int begin_days = ((begin->leap) ? LEAP_YEAR : YEAR_DAYS) - days_in_this_year(*begin);
        int end_days = days_in_this_year(*end);
        if(begin->leap) {
            end->month_days += begin_days;
        } else {
            begin->month_days += begin_days;
        }
        if(end->leap) {
            end->month_days += end_days;
        } else {
            begin->month_days += end_days;
        }
        for(int i = begin->year + 1; i < end->year; i++) {
            if(check_leap(i)) {
                end->month_days += LEAP_YEAR;
            } else {
                begin->month_days += YEAR_DAYS;
            }
        }
        begin->leap = YEAR_NOT_LEAP;
        end->leap = YEAR_IS_LEAP;
    }

    // begin->day = end->day;
    // begin->month = end->month;
    // begin->year = end->year;
}

/**
 * @brief A function that determines the correct logic for adding a month to the current date.
 * 
 * @param[in] date date by which the required time period.
 * @param term number of added months.
 * @param beginning_date the original date received as input from the user.
*/
static void add_months(time_data *date, int term, int beginning_date)
{
    int days[] = {0, JAN, (check_leap(date->year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    
    for(int i = 0; i < term; i++) {
        date->month += 1;
        if(date->month > 12) {
            date->month = 1;
            date->year += 1;
        }
        

        if(date->day != beginning_date) {
            date->day = beginning_date;
        }
        if(date->day > days[date->month]) {
            date->day = days[date->month];
        }
    }
    
    date->leap = check_leap(date->year);
}

/**
 * @brief A function that determines the correct logic for adding a days to the current date.
 * 
 * @param[in] date date by which the required time period.
 * @param term number of added days.
*/
static void add_days(time_data *date, int term)
{
    int days[] = {0, JAN, (check_leap(date->year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

    for(int i = 0; i < term; i++) {
        date->day++;
        if(date->day > days[date->month]) {
            date->day = 1;
            date->month++;
            if(date->month > 12) {
                date->month = 1;
                date->year++;
                if(check_leap(date->year)) {
                    days[2] = LEAP_FEB;
                } else {
                    days[2] = FEB;
                }
            }
        }
    }

    date->leap = check_leap(date->year);
}
