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

int main() {
    initial data;
    payments pay;
    
    input_initial(&data, 1000, 4, ANNUITY, 5, 06, 07, 2021);
    calculate_credit(&data, &pay);
    long double result_total[3] = {1010.57, 1000, 10.57};

    for(int i = 0; i < 3; i++) {
        printf("my:%Lf - true:%Lf\n", pay.total[i], result_total[i]);
    }
}