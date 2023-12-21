#ifndef S21_C_CREDIT_H
#define S21_C_CREDIT_H

#include <math.h>
#include <stdlib.h>

enum days_constants {
    YEAR = 365,
    LEAP_YEAR = 366,
    DECEMBER = 31,
};

enum payment_status {
    ANNUITY = 0,
    DIFFERENTIATED = 1,
    NOT_CHOSEN = 2,
};

enum year_status {
    YEAR_NOT_LEAP  = 0,
    YEAR_IS_LEAP = 1,
};

enum mallocate {
    ALLOCATED = 0,
    NOT_ALLOCATED = 1,
};

typedef struct time_data {
    int day;
    int month;
    int year;
    int leap;
    int month_days;
} time_data;

typedef struct payments {
    long double main;
    long double percent;
    long double monthly;
    long double *total;
    long double **result;
} payments;

typedef struct initial {
    int payment_type;
    long double debt;
    long double rate;
    int months;
    int current;
    time_data date;
} initial;

// main functions
void calculate_credit(initial *data, payments *pay);
void annuity(initial *data, payments *pay);
void differentiated(initial *data, payments *pay);
void calc_percent(initial *data, payments *pay);
void remember_result(initial *data, payments *pay);
int allocate_memory(initial *data, payments *pay);
int init_massive(payments *pay);

// calendar functions
void check_days(initial *data, time_data *next_month, int const_day);
int check_leap(int year);
void days_in_month(time_data *date, time_data *next_month);
void add_month(time_data *date, int beginning_date);

#endif