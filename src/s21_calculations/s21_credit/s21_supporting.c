#include "s21_credit.h"

/// @brief A function that calculates what part of the monthly payment goes to interest
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void calc_percent(initial *data, payments *pay) {
    if(data->date.leap < 2) {
        pay->percent = round((data->debt * data->rate / 100) / ((data->date.leap) ? LEAP_YEAR : YEAR) * data->date.month_days * 100) / 100;
    } else {
        long double days_in_december = DECEMBER - data->date.month_days;
        long double days_this_year = (data->date.leap == 2) ? YEAR : LEAP_YEAR;
        long double days_next_year = (days_this_year == YEAR) ? LEAP_YEAR : YEAR; 
        long double first_part_month = (data->debt * data->rate / 100) / days_this_year * days_in_december;
        long double second_part_month = (data->debt * data->rate / 100) / days_next_year * data->date.month_days;
        pay->percent = round((first_part_month + second_part_month) * 100) / 100;
    }
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
    pay->result[data->current] = (long double *)malloc(5 * sizeof(long double));
    if(pay->result[data->current]) {
        error_code = ALLOCATED;
    } else {
        error_code = NOT_ALLOCATED;
    }
    return error_code;
}