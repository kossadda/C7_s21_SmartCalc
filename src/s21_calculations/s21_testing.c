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
    
    input_initial(&data, 1674111.57, 71, ANNUITY, 8.244, 5, 5, 2005);
    calculate_credit(&data, &pay);
    long double result_total[3] = {2121675.22, 167411.57, 447563.65};

    for(int i = 0; i < 3; i++) {
        printf("my:%Lf - true:%Lf\n", pay.total[i], result_total[i]);
    }
}