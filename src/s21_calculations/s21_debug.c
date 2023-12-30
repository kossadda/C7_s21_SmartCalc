// #include "s21_tests/s21_test.h"
#include "s21_deposit/s21_deposit.h"
#include <stdio.h>

// void input_initial(initial *data, long double debt, long double months, int type, long double rate, int day, int month, int year) {
//     data->debt = debt;
//     data->months = months;
//     data->payment_type = type;
//     data->rate = rate;
//     data->date.day = day;
//     data->date.month = month;
//     data->date.year = year;
// }

// void input_redemption(early_pay *redemption, int day, int month, int year, long double sum, int type) {
//     redemption->date = (time_data *)realloc(redemption->date, (redemption->count + 1) * sizeof(time_data));
//     redemption->sum = (long double *)realloc(redemption->sum, (redemption->count + 1) * sizeof(long double));
//     redemption->type = (int *)realloc(redemption->type, (redemption->count + 1) * sizeof(int));
//     redemption->date[redemption->count].day = day;
//     redemption->date[redemption->count].month = month;
//     redemption->date[redemption->count].year = year;
//     redemption->sum[redemption->count] = sum;
//     redemption->type[redemption->count] = type;
//     redemption->count++; 
// }

// void free_memory(int row, payments *pay, early_pay *redemption) {
//     if(pay) {
//         int redemp_rows = 0;
//         if(redemption) {
//             redemp_rows = 1;
//         }
//         for(int i = 0; i < row + redemp_rows; i++) {
//             free(pay->result[i]);
//             pay->result[i] = NULL;
//         }
//         free(pay->result);
//         free(pay->total);
//         pay->result = NULL;
//         pay->total = NULL;
//     }
//     if(redemption) {
//         free(redemption->date);
//         free(redemption->sum);
//         free(redemption->type);
//         redemption->date = NULL;
//         redemption->sum = NULL;
//         redemption->type = NULL;
//     }
// }

// int logarifm(long double x, long double base) {
//     return ceil(log(x) / log(base));
// }

void print_all(init *data, investment *pay) {
    printf("MONTHLY:\n");
    for(int i = 0; i <= data->current; i++) {
        printf("%d", i + 1);
        for(int j = 0; j < 4; j++) {
            printf(" - %Lf", pay->result[i][j]);
        }
        printf("\n");
    }
    printf("\nTOTAL : %Lf  -  %Lf\n\n", pay->total[0], pay->total[1]);
}

void init_deposit(init *deposit, long double amount, int months, int day, int month, int year, long double rate, int capital) {
    deposit->amount = amount;
    deposit->months = months;
    deposit->date.day = day;
    deposit->date.month = month;
    deposit->date.year = year;
    deposit->rate = rate;
    deposit->capital = capital;
}

int main() {
    init data;
    investment pay;

    init_deposit(&data, 100000, 12, 1, 1, 2022, 10, 1);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {10471.28, 110471.28};

    print_all(&data, &pay);
}