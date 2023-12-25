#include "s21_credit.h"

/// @brief Function to define a year as a leap year
/// @param year Verified year
/// @return Returns information about the leap year. YEAR_NOT_LEAP - in the case of a normal year, YEAR_IS_LEAP - in the case of a leap year
int check_leap(int year) {
    int leap = YEAR_NOT_LEAP;
    if(year % 400 == 0) {
        leap = YEAR_IS_LEAP;
    } else if(year % 4 == 0 && year % 100 != 0) {
        leap = YEAR_IS_LEAP;
    }
    return leap;
}

/// @brief Function to determine the number of days in a month. The result is entered into the structure
/// @param date A structure containing the current date, the number of days in the month and a leap year variable
void days_in_month(time_data *date, time_data *next_month) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date->leap) {
        days[2] = 29;
    }
    date->month_days = days[date->month] - date->day;
    next_month->month_days = next_month->day;
}

/// @brief Function for determining date structure parameters for the next month
/// @param data Structure containing input parameters for calculation
void check_days(initial *data, time_data *next_month) {
    data->date.leap = check_leap(data->date.year);
    next_month->leap = check_leap(next_month->year);
    days_in_month(&(data->date), next_month);
}

/// @brief A function that determines the correct logic for adding a month to the current date
/// @param date A structure containing the current date, the number of days in the month and a leap year variable
/// @param beginning_date The original date received as input from the user
void add_month(time_data *date, int beginning_date) {
    date->month += 1;
    if(date->month > 12) {
        date->month = 1;
        date->year += 1;
    }
    
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date->leap) {
        days[2] = 29;
    }

    if(date->day != beginning_date) {
        date->day = beginning_date;
    }
    if(date->day > days[date->month]) {
        date->day = days[date->month];
    }
}

void set_date(time_data *date, int day, int month, int year) {
    date->day = day;
    date->month = month;
    date->year = year;
    date->leap = check_leap(year);
}

int compare_month(time_data now, time_data *pay, time_data next) {
    int day_between = 0;
    if(pay->year == now.year || pay->year == next.year) {
        if(pay->month == now.month && pay->day >= now.day) {
            day_between = 1;
            pay->month_days = sub_date(*pay, now);
        } else if(pay->month == next.month && pay->day < next.day) {
            day_between = 1;
            pay->month_days = sub_date(*pay, now);
        }
    }
    pay->leap = check_leap(pay->year);
    return day_between;
}

int sub_date(time_data first, time_data second) {
    first.leap = check_leap(first.year);
    second.leap = check_leap(second.year);
    int all_days_1 = first.day;
    int all_days_2 = second.day;
    int diff = 0;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(first.leap) {
        days[2] = 29;
    }
    for(int i = 1; i < first.month; i++) {
        all_days_1 += days[i];
    }
    if(second.leap) {
        days[2] = 29;
    }
    for(int i = 1; i < second.month; i++) {
        all_days_2 += days[i];
    }
    if(first.year == second.year) {
        diff = all_days_1 - all_days_2;
    } else {
        diff = all_days_1 + (((second.leap) ? 366 : 365) - all_days_2);
        for(int i = second.year + 1; i != first.year; i++) {
            int check = check_leap(i);
            if(check) {
                diff += 366;
            } else {
                diff += 365;
            }
        }
    }
    return diff;
}

int sub_till_end_month(time_data date) {
    date.leap = check_leap(date.year);
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(date.leap) {
        days[2] = 29;
    }
    time_data last_day_month = date;
    last_day_month.day = days[date.month];
    return sub_date(last_day_month, date);
}