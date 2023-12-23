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



int main() {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_TERM);
    // input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_TERM);
    // input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15455177.6, 12364567.22, 3090610.38};

    for(int i = 0; i < 3; i++) {
        printf("my:%Lf - true:%Lf\n", pay.total[i], result_total[i]);
    }
}