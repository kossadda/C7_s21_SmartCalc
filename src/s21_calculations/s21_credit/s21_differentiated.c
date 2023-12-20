#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void differentiated(initial *data, payments *pay) {
    if(data->current >= data->months - 1 && data->debt < pay->main) {
        pay->main = data->debt;
    }
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
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;
    pay->result[data->current][0] = pay->monthly;
    pay->total[0] += pay->monthly;
    pay->result[data->current][1] = pay->main;
    pay->total[1] += pay->main;
    pay->result[data->current][2] = pay->percent;
    pay->total[2] += pay->percent;
    pay->result[data->current][3] = data->debt;
}
