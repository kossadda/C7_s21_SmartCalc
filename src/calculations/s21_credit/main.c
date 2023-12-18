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
    int payment_type;
} initial;

#define YEAR 365
#define LEAP_YEAR 366
#define DECEMBER_DAYS 31
#define ANNUITY 0
#define DIFFERENTIATED 1

void annuity(initial *data, payments *pay, int (*month_day)[2], long double (*results)[4], long double *full_res) {
    static long double rest = 0;

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
    if(rest) {
        pay->percent += rest;
        rest = 0;
    }
    if(data->current == 463) {
        data->current = 463;
    }
    if(pay->percent > pay->monthly) {
        rest = pay->percent - pay->monthly;
        pay->percent = pay->monthly;
        pay->main = 0;
    } else {
        if(data->debt >= pay->monthly) {
            pay->main = pay->monthly - pay->percent;
        } else {
            pay->main = data->debt;
            pay->monthly = pay->main + pay->percent;
        }
    }
    data->debt -= pay->main;
    results[data->current][0] = pay->monthly;
    full_res[0] += pay->monthly;
    results[data->current][1] = pay->main;
    full_res[1] += pay->main;
    results[data->current][2] = pay->percent;
    full_res[2] += pay->percent;
    results[data->current][3] = data->debt;
}

void differentiated(initial *data, payments *pay, int (*month_day)[2], long double (*results)[4], long double *full_res) {
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

void calculate_credit(initial *data, int (*month_day)[2], long double (*results)[4], long double *full_res) {
    payments pay;

    if(data->payment_type == DIFFERENTIATED) {
        pay.main = round(data->debt/data->months * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++) {
            differentiated(data, &pay, month_day, results, full_res);
        }
    } else if(data->payment_type == ANNUITY) {
        double monthly_percent = data->rate / (100.0 * 12.0);
        pay.monthly = round(data->debt * monthly_percent / (1 - pow((1.0 + monthly_percent), data->months * (-1))) * 100) / 100;

        for(data->current = 0; data->debt != 0; data->current++) {
            annuity(data, &pay, month_day, results, full_res);
        }
    }
}
