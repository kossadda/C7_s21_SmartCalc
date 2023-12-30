#include "s21_deposit.h"
#include "stdio.h"

static int init_investment(investment *pay);
static int calc_period(init *data, investment *pay, time_data next_month);
static int allocate_row(init *data, investment *pay);
static void write_results(init *data, investment *pay);
static void calc_profit(init *data, investment *pay, time_data next_month);

void calculate_deposit(init *data, investment *pay)
{
    int error_code = NOT_ALLOCATED;
    int error_code_depos = NOT_ALLOCATED;
    int error_code_pay = NOT_ALLOCATED;

    error_code_depos = CHECK_NULL(data);
    error_code_pay = CHECK_NULL(pay);
    error_code = error_code_depos + error_code_pay;

    int const_date = data->date.day;
    time_data next_month;

    if(error_code == ALLOCATED) {
        next_month = data->date;
        next_month.leap = check_leap(next_month.year);
        add_month(&next_month, data->date.day);

        error_code = init_investment(pay);
    }

    if(error_code == ALLOCATED) {
        for(data->current = -1; data->current < data->months - 1;) {
            determine_date(&data->date, &next_month);

            error_code = calc_period(data, pay, next_month);
            
            add_month(&(data->date), const_date);
            add_month(&next_month, const_date);

            data->current = (error_code == ALLOCATED) ? data->current : data->months;
        }
    }
}

static int calc_period(init *data, investment *pay, time_data next_month)
{
    int error_code = ALLOCATED;
    data->current++;
    error_code = allocate_row(data, pay);
    if(error_code == ALLOCATED) {
        calc_profit(data, pay, next_month);
        if(data->capital) {
            pay->balance_changing = pay->profit;
            pay->receiving = 0;
            data->amount += pay->profit;
        } else {
            pay->balance_changing = 0;
            pay->receiving = pay->profit;
        }
        pay->balance = data->amount;
        write_results(data, pay);
    }
    return error_code;
}

static int allocate_row(init *data, investment *pay)
{
    int error_code = NOT_ALLOCATED;
    pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
    int error_code_row = CHECK_NULL(pay->result);
    pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
    int error_code_column = CHECK_NULL(pay->result[data->current]);
    error_code = error_code_row + error_code_column;
    return error_code;
}

static int init_investment(investment *pay)
{
    int error_code = NOT_ALLOCATED;

    pay->total = (long double *)malloc(2 * sizeof(long double));
    int error_code_total = CHECK_NULL(pay->total);
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    int error_code_result = CHECK_NULL(pay->result);

    error_code = error_code_total + error_code_result;

    pay->total[0] = 0;
    pay->total[1] = 0;

    return error_code;
}

static void write_results(init *data, investment *pay)
{
    pay->result[data->current][0] = pay->profit;
    pay->total[0] += pay->profit;
    pay->result[data->current][1] = pay->balance_changing;
    pay->result[data->current][2] = pay->receiving;
    pay->result[data->current][3] = pay->balance;
    pay->total[1] = pay->balance;
}

static void calc_profit(init *data, investment *pay, time_data next_month) {
    long double first_part_month = (data->amount * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days;
    long double second_part_month = (data->amount * data->rate / 100) / ((next_month.leap) ? LEAP_YEAR : YEAR) * next_month.month_days;
    pay->profit = round((first_part_month + second_part_month) * 100) / 100;
}