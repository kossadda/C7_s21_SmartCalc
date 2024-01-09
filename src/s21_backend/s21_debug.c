#include "s21_tests/s21_test.h"
#include <stdio.h>

#define DEBUG_CREDIT
#ifndef DEBUG_CREDIT

void input_initial(credit_init *data, long double debt, long double months, int type, long double rate, int day, int month, int year) {
    data->debt = debt;
    data->months = months;
    data->payment_type = type;
    data->rate = rate;
    data->date.day = day;
    data->date.month = month;
    data->date.year = year;
}

void input_redemption(early_pay *redemption, int day, int month, int year, long double sum, int type) {
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

void free_memory(int row, payments *pay, early_pay *redemption) {
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

void print_credit(credit_init *data, payments *pay) {
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

#endif

#ifndef DEBUG_DEPOSIT
#define DEBUG_DEPOSIT

void print_deposit(deposit_init *data, investment *pay) {
    printf("MONTHLY:\n");
    int rows = data->current;
    int const_date = data->date.day;
    time_data last_day = determine_last_day(data->date, data->term_type, data->term);
    for(int i = 0; i <= rows; i++) {
        time_data end = data->date;

        add_one_period(&data->date, &end, last_day, data->capital_time, const_date);

        if(end.day < 10) {
            printf("0");
        }
        printf("%d.", end.day);
        if(end.month < 10) {
            printf("0");
        }
        printf("%d.", end.month);
        printf("%d", end.year);

        for(int j = 0; j < 4; j++) {
            printf(" - %Lf", pay->result[i][j]);
        }
        printf("\n");

        data->date = end;
    }
    printf("\nTOTAL : %.2Lf, %.2Lf\n\n", pay->total[0], pay->total[1]);
}

int init_operations(operations *oper)
{
    int error_code = NOT_ALLOCATED;
    oper->date = (time_data *)malloc(1 * sizeof(time_data));
    int error_code_date = CHECK_NULL(oper->date);
    oper->sum = (long double *)malloc(1 * sizeof(long double));
    int error_code_sum = CHECK_NULL(oper->sum);
    oper->type = (int *)malloc(1 * sizeof(int));
    int error_code_type = CHECK_NULL(oper->type);
    error_code = error_code_date + error_code_sum + error_code_type;
    oper->count = 0;
    oper->current = 0;
    oper->min_balance = 0;
    return error_code;
}


void init_deposit(deposit_init *deposit, long double amount, int term_type, int term, int day, int month, int year, long double rate, int capital_time, int capital) {
    deposit->amount = amount;
    deposit->term_type = term_type;
    deposit->term = term;
    deposit->date.day = day;
    deposit->date.month = month;
    deposit->date.year = year;
    deposit->rate = rate;
    deposit->capital_time = capital_time;
    deposit->capital = capital;
}

void input_operation(operations *oper, int day, int month, int year, long double sum, int type, long double min_balance) {
    oper->date = (time_data *)realloc(oper->date, (oper->count + 1) * sizeof(time_data));
    oper->sum = (long double *)realloc(oper->sum, (oper->count + 1) * sizeof(long double));
    oper->type = (int *)realloc(oper->type, (oper->count + 1) * sizeof(int));
    oper->date[oper->count].day = day;
    oper->date[oper->count].month = month;
    oper->date[oper->count].year = year;
    oper->sum[oper->count] = sum;
    oper->type[oper->count] = type;
    oper->min_balance = min_balance;
    oper->count++; 
}

#endif

#ifndef DEBUG
#define DEBUG
    // deposit_init data1 = data;

int main() {
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 77777777777.77, DAYS_PERIOD, 5342, 23, 11, 2023, 0.01, BY_YEAR, CAPITAL);

    deposit_init data1 = data;

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};



    
    data1.current = data.current;
    print_deposit(&data1, &pay);

    // print_credit(&data, &pay);
}

#endif