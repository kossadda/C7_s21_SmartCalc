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
    int diff = days[date->month] - date->day;
    date->month_days = next_month->day + diff;
}


/// @brief Function for determining date structure parameters for the next month
/// @param data Structure containing input parameters for calculation
void check_days(initial *data, time_data *next_month, int const_day) {
    data->date.leap = check_leap(data->date.year);
    next_month->leap = check_leap(next_month->year);
    if(data->date.month == 12) {
        if(check_leap(data->date.year + 1)) {
            data->date.month_days = data->date.day;
            data->date.leap = 2;
        } else if (data->date.leap) {
            data->date.month_days = data->date.day;
            data->date.leap = 3;
        } else {
            days_in_month(&(data->date), next_month);
        }
    } else {
        days_in_month(&(data->date), next_month);
    }
    add_month(&(data->date), const_day);
    add_month(next_month, const_day);
}

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