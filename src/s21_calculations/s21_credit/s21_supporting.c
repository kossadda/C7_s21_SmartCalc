#include "s21_credit.h"

/// @brief A function that calculates what part of the monthly payment goes to interest
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void calc_percent(initial *data, payments *pay, time_data next_month) {
    long double first_part_month = (data->debt * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days;
    long double second_part_month = (data->debt * data->rate / 100) / ((next_month.leap) ? LEAP_YEAR : YEAR) * next_month.month_days;
    pay->percent = round((first_part_month + second_part_month) * 100) / 100;
}

/// @brief A function that writes the result of each month to an array
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void remember_result(initial *data, payments *pay) {
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
}

/// @brief Function initializing a data array
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @return Returns the error code. If memory is allocated - ALLOCATED, if not - NOT_ALLOCATED
int init_massive(payments *pay) {
    int error_code = NOT_ALLOCATED;
    pay->total = (long double *)malloc(3 * sizeof(long double));
    if(pay->total) {
        error_code = ALLOCATED;
    }
    pay->result = (long double **)malloc(1 * sizeof(long double *));
    if(pay->result) {
        error_code = ALLOCATED;
    } else {
        error_code = NOT_ALLOCATED;
    }
    if(!error_code) {
        pay->total[0] = 0;
        pay->total[1] = 0;
        pay->total[2] = 0;
    }
    return error_code;
}

void init_redemption(another_payments *redemption) {
    redemption->date = (time_data *)malloc(1 * sizeof(time_data));
    redemption->sum = (long double *)malloc(1 * sizeof(long double));
    redemption->type = (int *)malloc(1 * sizeof(int));
    redemption->count = 0;
    redemption->current = 0;
}

/// @brief A function that allocates additional memory for an initialized array
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @return Returns the error code. If memory is allocated - ALLOCATED, if not - NOT_ALLOCATED
int allocate_memory(initial *data, payments *pay) {
    int error_code = NOT_ALLOCATED;
    pay->result = (long double **)realloc(pay->result, (data->current + 1) * sizeof(long double *));
    if(pay->result) {
        error_code = ALLOCATED;
    }
    pay->result[data->current] = (long double *)malloc(4 * sizeof(long double));
    if(pay->result[data->current]) {
        error_code = ALLOCATED;
    } else {
        error_code = NOT_ALLOCATED;
    }
    return error_code;
}

void redemp_payment(initial *data, payments *pay, time_data *next_month, another_payments *redemption, long double *full_percent, int *change) {
    data->current++;
    allocate_memory(data, pay);
    if(*change) {
        redemption->date[redemption->current].month_days = sub_date(redemption->date[redemption->current], redemption->date[redemption->current - 1]);
    } else {
        redemption->date[redemption->current].month_days = sub_date(redemption->date[redemption->current], data->date);
    }
    long double percent = round((data->debt * data->rate / 100) / ((redemption->date[redemption->current].leap) ? LEAP_YEAR : YEAR) * redemption->date[redemption->current].month_days * 100) / 100;
    if(redemption->sum[redemption->current] > percent) {
        *change = 1;
    } else {
        *change = 0;
    }
    if(*change) {
        pay->percent = percent - *full_percent;
        *full_percent = 0;
    } else {
        pay->percent = (percent > redemption->sum[redemption->current]) ? redemption->sum[redemption->current] : percent;
        *full_percent += pay->percent;
    }

    pay->monthly = redemption->sum[redemption->current];
    pay->main = pay->monthly - pay->percent;
    if(data->debt < pay->main) {
        pay->main = data->debt;
        pay->monthly = pay->percent + pay->main;
    }
    data->debt -= pay->main;

    remember_result(data, pay);
    if(*change) {
        if(redemption->date[redemption->current].month == data->date.month && redemption->date[redemption->current].day >= data->date.day) {
            data->date.month_days = sub_till_end_month(redemption->date[redemption->current]);
        } else {
            data->date.month_days = 0;
            next_month->month_days = sub_date(*next_month, redemption->date[redemption->current]);
        }
    }
    if(redemption->type[redemption->current] == REDUCE_PAY) {
        pay->const_main -= round(pay->main/(data->months - (data->current - redemption->current)) * 100) / 100;
    }
    pay->main = pay->const_main;
    redemption->current++;
}
