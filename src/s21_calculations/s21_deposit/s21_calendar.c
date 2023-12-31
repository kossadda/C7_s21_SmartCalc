#include "s21_deposit.h"

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

void determine_date(time_data *this_month, time_data *next_month)
{
    this_month->leap = check_leap(this_month->year);
    next_month->leap = check_leap(next_month->year);
    this_month->month_days = sub_till_end_month(*this_month);
    next_month->month_days = next_month->day;
}

void add_months(time_data *date, int term, int beginning_date)
{
    for(int i = 0; i < term; i++) {
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
    
    date->leap = check_leap(date->year);
}

void add_days(time_data *date, int term)
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

int days_in_this_year(time_data date)
{
    int days[] = {0, JAN, (check_leap(date.year)) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    int days_in_year = date.day;
    for(int i = 1; i < date.month; i++) {
        days_in_year += days[i];
    }
    return days_in_year;
}

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

int sub_till_end_month(time_data date)
{
    int days[] = {0, JAN, (date.leap) ? LEAP_FEB : FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
    time_data last_day_month = date;
    last_day_month.day = days[date.month];
    return sub_date(last_day_month, date);
}