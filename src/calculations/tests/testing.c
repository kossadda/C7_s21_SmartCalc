#include "../main.h"
#include <stdio.h>

typedef struct time {
    int day;
    int month;
    int year;
    int leap;
    int month_days;
} time;

int check_leap(int year) {
    int leap = 0;
    if(year % 400 == 0) {
        leap = 1;
    } else if(year % 4 == 0 && year % 100 != 0) {
        leap = 1;
    }
    return leap;
}

void daysInMonth(time *date) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(date->leap) {
        days[2] = 29;
    }

    date->month_days = days[date->month];
}

int main() {
    time date = {19, 12, 1999, 0, 0};
    int month_num = 12;

    for (int i = 0; i < month_num; i++, date.month++) {
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
        date.leap = check_leap(date.year);

        if(date.month == 12 && (check_leap(date.year) || check_leap(date.year + 1))) {
            date.month_days = date.day;
        } else {
            daysInMonth(&date);
        }
        printf("%d-%02d: %d days\n", date.year, date.month, date.month_days);
    }
}