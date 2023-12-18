#include <math.h>

typedef struct payments {
    long double main;
    long double percent;
    long double monthly;
} payments;

typedef struct initial {
    long double debt;
    long double rate;
    int current;
    int months;
} initial;

#define YEAR 365
#define LEAP_YEAR 366
#define DECEMBER_DAYS 31

void monthly_values(initial *data, payments *pay, int (*month_day)[2], long double (*results)[4], long double *full_res) {
    if(data->current >= data->months - 1 && data->debt < pay->main) {
        pay->main = data->debt;
    }
    if(month_day[data->current][1] < 2) {
        pay->percent = round((data->debt * data->rate / 100) / ((month_day[data->current][1]) ? LEAP_YEAR : YEAR) * month_day[data->current][0] * 100) / 100;
    } else {
        long double days_in_december = DECEMBER_DAYS - month_day[data->current][0];
        long double days_this_year = (month_day[data->current][1] == 2) ? YEAR : LEAP_YEAR;
        long double days_next_year = (days_this_year == YEAR) ? LEAP_YEAR : YEAR; 
        long double first_part_month = (data->debt * data->rate / 100) / days_this_year * days_in_december;
        long double second_part_month = (data->debt * data->rate / 100) / days_next_year * month_day[data->current][0];
        pay->percent = round((first_part_month + second_part_month) * 100) / 100;
    }
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;
    results[data->current][0] = pay->monthly;
    full_res[0] += pay->monthly;
    results[data->current][1] = pay->main;
    full_res[1] += pay->main;
    results[data->current][2] = pay->percent;
    full_res[2] += pay->percent;
    results[data->current][3] = data->debt;
}

void calculate_credit(initial data, int (*month_day)[2], long double (*results)[4], long double *full_res) {
    payments pay;
    pay.main = round(data.debt/data.months * 100) / 100;

    for(; data.current < data.months; data.current++) {
        monthly_values(&data, &pay, month_day, results, full_res);
    }
    if(data.debt > 0) {
        monthly_values(&data, &pay, month_day, results, full_res);
    }
}
