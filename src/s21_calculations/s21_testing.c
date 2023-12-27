#include "s21_tests/s21_test.h"
#include <stdio.h>

void input_initial(initial *data, long double debt, long double months, int type, long double rate, int day, int month, int year) {
    data->debt = debt;
    data->months = months;
    data->payment_type = type;
    data->rate = rate;
    data->date.day = day;
    data->date.month = month;
    data->date.year = year;
}

void input_redemption(another_payments *redemption, int day, int month, int year, long double sum, int type) {
    redemption->date = (time_data *)realloc(redemption->date, (redemption->count + 1) * sizeof(time_data));
    redemption->sum = (long double *)realloc(redemption->sum, (redemption->count + 1) * sizeof(long double));
    redemption->type = (int *)realloc(redemption->type, (redemption->count + 1) * sizeof(int));
    redemption->date[redemption->count].day = day;
    redemption->date[redemption->count].month = month;
    redemption->date[redemption->count].year = year;
    redemption->sum[redemption->count] = sum;
    redemption->type[redemption->count] = type;
    redemption->count++; 
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void free_memory(int row, payments *pay, another_payments *redemption) {
    if(pay) {
        int redemp_rows = 0;
        if(redemption) {
            redemp_rows = 1;
        }
        for(int i = 0; i < row + redemp_rows; i++) {
            free(pay->result[i]);
            pay->result[i] = NULL;
        }
        free(pay->result);
        free(pay->total);
        pay->result = NULL;
        pay->total = NULL;
    }
    if(redemption) {
        free(redemption->date);
        free(redemption->sum);
        free(redemption->type);
        redemption->date = NULL;
        redemption->sum = NULL;
        redemption->type = NULL;
    }
}

// int logarifm(long double x, long double base) {
//     return ceil(log(x) / log(base));
// }

int main() {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    // input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    // input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 23, 12, 2022, 25000, REDUCE_TERM);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349564.71, 333333.33, 16231.38};



    // input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    // input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 23, 12, 2022, 25000, REDUCE_TERM);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349778.95, 333333.33, 16445.62};



    // input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349952.41, 333333.33, 16619.08};



    // input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {350115.62, 333333.33, 16782.29};



    // input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349952.41, 333333.33, 16619.08};



    // input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {350705.73, 333333.33, 17372.4};


    // input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349864.07, 333333.33, 16530.74};


    // input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_TERM);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {350361.73, 333333.33, 17028.4};


    // input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    // input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    // input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_TERM);
    // input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {349537.98, 333333.33, 16204.65};



    // input_initial(&data, 12364567.22, 55, ANNUITY, 11.211, 11, 01, 2019);
    // input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_TERM);
    // input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_TERM);
    // input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {15692895.04, 12364567.22, 3328327.82};


    // input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    // input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_TERM);
    // input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_TERM);
    // input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {15038562.61, 12364567.22, 2673995.39};


    // input_initial(&data, 55321523.34, 43, ANNUITY, 21.463, 03, 01, 2019);
    // input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_PAY);
    // input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_PAY);
    // input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_PAY);
    // input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {79371094.51, 55321523.34, 24049571.17};


    // input_initial(&data, 55321523.34, 43, DIFFERENTIATED, 21.463, 03, 01, 2019);
    // input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_PAY);
    // input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_PAY);
    // input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_PAY);
    // input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_PAY);

    // calculate_credit(&data, &pay, &redemption);
    // long double result_total[3] = {77065876.72, 55321523.34, 21744353.38};

    for(int i = 0; i < 3; i++) {
        printf("  my:%Lf\ntrue:%Lf\n\n", pay.total[i], result_total[i]);
    }
    free_memory(data.current, &pay, &redemption);
}


    // int kek = logarifm(224810.31/(224810.31-0.0093*9261116.42), 1 + 0.0093);