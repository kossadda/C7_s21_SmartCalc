#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
/// @param redemption Structure containing data on early repayments
int calculate_credit(initial *data, payments *pay, another_payments *redemption) {
    int error_code = NOT_ALLOCATED;
    time_data next_month;
    int const_day = 0;
    
    error_code = CHECK_NULL(data);
    error_code = (error_code == ALLOCATED && CHECK_NULL(pay) == ALLOCATED) ? ALLOCATED : NOT_ALLOCATED;
    
    if(error_code == ALLOCATED) {
        if(redemption) {
            redemption->current = 0;
        }
        const_day = data->date.day;
        next_month = data->date;
        next_month.leap = check_leap(next_month.year);
        add_month(&next_month, const_day);

        error_code = init_massive(pay);
    }

    if(error_code == ALLOCATED && data->payment_type == ANNUITY) {
        double monthly_percent = data->rate / (100.0 * 12.0);
        pay->monthly = round_value(data->debt * monthly_percent / (1 - pow((1.0 + monthly_percent), data->months * (-1))));

        for(data->current = -1; data->debt != 0;) {
            determine_date(&data->date, &next_month);
            annuity(data, pay, next_month);
            add_month(&(data->date), const_day);
            add_month(&next_month, const_day);
        }
    } else if(error_code == ALLOCATED && data->payment_type == DIFFERENTIATED) {
        differentiated(data, pay, redemption, next_month);
    }
    return error_code;
}
