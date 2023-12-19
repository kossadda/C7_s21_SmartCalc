#include <math.h>
#include <stdlib.h>

typedef struct time_data {
    int day;
    int month;
    int year;
    int leap;
    int month_days;
} time_data;

typedef struct payments {
    long double main;
    long double percent;
    long double monthly;
    long double *total;
    long double **result;
} payments;

typedef struct initial {
    int payment_type;
    long double debt;
    long double rate;
    int months;
    int current;
    time_data date;
} initial;

#define YEAR 365
#define LEAP_YEAR 366
#define DECEMBER_DAYS 31
#define ANNUITY 0
#define DIFFERENTIATED 1

int check_leap(int year) {
    int leap = 0;
    if(year % 400 == 0) {
        leap = 1;
    } else if(year % 4 == 0 && year % 100 != 0) {
        leap = 1;
    }
    return leap;
}

void daysInMonth(time_data *date) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(date->leap) {
        days[2] = 29;
    }

    date->month_days = days[date->month];
}

void annuity(initial *data, payments *pay) {
    static long double rest = 0;

    if(data->date.leap < 2) {
        pay->percent = round((data->debt * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days * 100) / 100;
    } else {
        long double days_in_december = DECEMBER_DAYS - data->date.month_days;
        long double days_this_year = (data->date.leap == 2) ? YEAR : LEAP_YEAR;
        long double days_next_year = (days_this_year == YEAR) ? LEAP_YEAR : YEAR; 
        long double first_part_month = (data->debt * data->rate / 100) / days_this_year * days_in_december;
        long double second_part_month = (data->debt * data->rate / 100) / days_next_year * data->date.month_days;
        pay->percent = round((first_part_month + second_part_month) * 100) / 100;
    }
    if(rest) {
        pay->percent += rest;
        rest = 0;
    }
    if(pay->percent > pay->monthly) {
        rest = pay->percent - pay->monthly;
        pay->percent = pay->monthly;
        pay->main = 0;
    } else {
        if(data->debt >= pay->monthly) {
            pay->main = pay->monthly - pay->percent;
        } else if(data->debt < pay->monthly && data->debt + pay->percent > pay->monthly) {
            pay->main = pay->monthly - pay->percent;
        } else {
            pay->main = data->debt;
            pay->monthly = pay->main + pay->percent;
        }
    }
    data->debt -= pay->main;
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
}

void differentiated(initial *data, payments *pay) {
    if(data->current >= data->months - 1 && data->debt < pay->main) {
        pay->main = data->debt;
    }
    if(data->date.leap < 2) {
        pay->percent = round((data->debt * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days * 100) / 100;
    } else {
        long double days_in_december = DECEMBER_DAYS - data->date.month_days;
        long double days_this_year = (data->date.leap == 2) ? YEAR : LEAP_YEAR;
        long double days_next_year = (days_this_year == YEAR) ? LEAP_YEAR : YEAR; 
        long double first_part_month = (data->debt * data->rate / 100) / days_this_year * days_in_december;
        long double second_part_month = (data->debt * data->rate / 100) / days_next_year * data->date.month_days;
        pay->percent = round((first_part_month + second_part_month) * 100) / 100;
    }
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
}

void check_days(initial *data) {
    if(data->date.month > 12) {
        data->date.month = 1;
        data->date.year++;
    }
    data->date.leap = check_leap(data->date.year);
    if(data->date.month == 12) {
        if(check_leap(data->date.year + 1)) {
            data->date.month_days = data->date.day;
            data->date.leap = 2;
        } else if (data->date.leap) {
            data->date.month_days = data->date.day;
            data->date.leap = 3;
        } 
    } else {
        daysInMonth(&(data->date));
    }
}

void calculate_credit(initial *data, payments *pay) {
    pay->total = (long double *)malloc(3 * sizeof(long double));
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    pay->total[0] = 0;
    pay->total[1] = 0;
    pay->total[2] = 0;
    if(data->payment_type == DIFFERENTIATED) {
        pay->main = round(data->debt/data->months * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++, data->date.month++) {
            pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
            pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
            check_days(data);
            differentiated(data, pay);
        }
    } else if(data->payment_type == ANNUITY) {
        double monthly_percent = data->rate / (100.0 * 12.0);
        pay->monthly = round(data->debt * monthly_percent / (1 - pow((1.0 + monthly_percent), data->months * (-1))) * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++, data->date.month++) {
            pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
            pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
            check_days(data);
            annuity(data, pay);
        }
    }
}

// int main() {
//     initial data;
//     payments pay;
//     data.debt = 120000;
//     data.months = 12;
//     data.payment_type = ANNUITY;
//     data.rate = 12;
//     data.date.day = 19;
//     data.date.month = 12;
//     data.date.year = 2023;

//     calculate_credit(&data, &pay);
// }
