#include "s21_deposit.h"
#include "stdio.h"

static int init_investment(investment *pay);
static int calc_period(init *data, investment *pay, time_data next_month);
static int allocate_row(init *data, investment *pay);
static void write_results(init *data, investment *pay);
static void calc_profit(init *data, investment *pay, time_data next_month);
static int compare_dates(time_data first, time_data second);
time_data determine_last_day(time_data first_day, int term_type, int term);

void calculate_deposit(init *data, investment *pay)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    int const_date = data->date.day;

    time_data last_day = determine_last_day(data->date, data->term_type, data->term);
    

    if(error_code == ALLOCATED) {
        data->date.leap = check_leap(data->date.year);

        error_code = init_investment(pay);
    }

    if(error_code == ALLOCATED) {
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            time_data end_period = data->date;
            add_one_period(&(data->date), &end_period, last_day, data->capital_time);

            error_code = calc_period(data, pay, end_period);
            
            data->date = end_period;
            data->current = (error_code == ALLOCATED) ? data->current : data->term;
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

static void calc_profit(init *data, investment *pay, time_data next_month) {
    long double first_part_month = (data->amount * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR_DAYS) * data->date.month_days;
    long double second_part_month = (data->amount * data->rate / 100) / ((next_month.leap) ? LEAP_YEAR : YEAR_DAYS) * next_month.month_days;
    pay->profit = round((first_part_month + second_part_month) * 100) / 100;
}








static int compare_dates(time_data first, time_data second)
{
    int compare = DATE_EQUAL;

    if(first.year < second.year) {
        compare = DATE_BEFORE;
    } else if(first.year > second.year) {
        compare = DATE_AFTER;
    }
    if(compare == DATE_EQUAL) {
        if(first.month < second.month) {
            compare = DATE_BEFORE;
        } else if(first.month > second.month) {
            compare = DATE_AFTER;
        }
    }
    if(compare == DATE_EQUAL) {
        if(first.day < second.day) {
            compare = DATE_BEFORE;
        } else if(first.day > second.day) {
            compare = DATE_AFTER;
        }
    }

    return compare;
}

time_data determine_last_day(time_data date, int term_type, int term)
{
    if(term_type == DAYS_PERIOD) {
        add_days(&date, term);
    } else if(term_type == MONTHS_PERIOD) {
        int const_date = date.day;
        add_months(&date, term, const_date);
    }

    return date;
}

void add_one_period(time_data *begin, time_data *end, time_data last_day, int capital_type)
{
    int const_date = end->day;
    
    if(capital_type == BY_DAY) {
        add_days(end, DAY);
    } else if(capital_type == BY_WEEK) {
        add_days(end, WEEK);
    } else if(capital_type == BY_MONTH) {
        add_months(end, MONTH, const_date);
    } else if(capital_type == BY_QUARTER) {
        add_months(end, QUARTER, const_date);
    } else if(capital_type == BY_HALFYEAR) {
        add_months(end, HALFYEAR, const_date);
    } else if(capital_type == BY_YEAR) {
        add_months(end, YEAR, const_date);
    }

    if(compare_dates(*end, last_day) == DATE_AFTER) {
        *end = last_day;
    }

    if(begin->leap == end->leap) {
        begin->month_days = sub_date(*end, *begin);
        end->month_days = 0;
    } else {
        begin->month_days = ((begin->leap) ? LEAP_YEAR : YEAR_DAYS) - days_in_this_year(*begin);
        end->month_days = days_in_this_year(*end);
    }
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