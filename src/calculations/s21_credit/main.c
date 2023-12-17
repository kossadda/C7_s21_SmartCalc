#include <stdio.h>
#include <math.h>

typedef struct payments {
    long double main;
    long double percent;
    long double monthly;
} payments;

void monthly_values(long double *debt, int months, payments *pay, long double (*results)[4], long double *full_res, int iteration, long double rate, int (*month_day)[2]) {
    if(iteration >= months - 1 && *debt < pay->main) {
        pay->main = *debt;
    }
    if(month_day[iteration][1] < 2) {
        pay->percent = round((*debt * rate / 100) / ((month_day[iteration][1]) ? 366 : 365) * month_day[iteration][0] * 100) / 100;
    } else {
        long double days_in_december = 31 - month_day[iteration][0];
        long double days_this_year = (month_day[iteration][1] == 2) ? 365 : 366;
        long double days_next_year = (days_this_year == 365) ? 366 : 365; 
        long double first_part_month = (*debt * rate / 100) / days_this_year * days_in_december;
        long double second_part_month = (*debt * rate / 100) / days_next_year * month_day[iteration][0];
        pay->percent = round((first_part_month + second_part_month) * 100) / 100;
    }
    pay->monthly = pay->main + pay->percent;
    *debt -= pay->main;
    results[iteration][0] = pay->monthly;
    full_res[0] += pay->monthly;
    results[iteration][1] = pay->main;
    full_res[1] += pay->main;
    results[iteration][2] = pay->percent;
    // if(pay->percent >= 0.005 &&  pay->percent < 0.01) {
    //     results[iteration][2] = 0.02;
    // }
    full_res[2] += pay->percent;
    results[iteration][3] = *debt;
}

void calculate_credit(long double amount, int months, int (*month_day)[2], long double rate, long double (*results)[4], long double *full_res) {

    long double debt = amount;
    payments pay;
    pay.main = round(amount/months * 100) / 100;

    for(int i = 0; i < months; i++) {
        monthly_values(&debt, months, &pay, results, full_res, i, rate, month_day);
        // if(i == months - 1 && debt < pay.main) {
        //     pay.main = debt;
        // }
        // if(month_day[i][1] < 2) {
        //     pay.percent = round((debt * rate / 100) / ((month_day[i][1]) ? 366 : 365) * month_day[i][0] * 100) / 100;
        // } else {
        //     long double days_in_december = 31 - month_day[i][0];
        //     long double days_this_year = (month_day[i][1] == 2) ? 365 : 366;
        //     long double days_next_year = (days_this_year == 365) ? 366 : 365; 
        //     long double first_part_month = (debt * rate / 100) / days_this_year * days_in_december;
        //     long double second_part_month = (debt * rate / 100) / days_next_year * month_day[i][0];
        //     pay.percent = round((first_part_month + second_part_month) * 100) / 100;
        // }
        // pay.monthly = pay.main + pay.percent;
        // debt -= pay.main;
        // results[i][0] = pay.monthly;
        // full_res[0] += pay.monthly;
        // results[i][1] = pay.main;
        // full_res[1] += pay.main;
        // results[i][2] = pay.percent;
        // full_res[2] += pay.percent;
        // results[i][3] = debt;
    }
    if(debt > 0) {
        monthly_values(&debt, months, &pay, results, full_res, months, rate, month_day);
        // full_res[0] += debt;
        // full_res[1] += debt;
    }
}
