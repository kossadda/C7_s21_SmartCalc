#include "s21_credit.h"

/// @brief Function for calculating monthly payments of annuity type
/// @param data Structure containing input parameters for calculation
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void calculate_credit(initial *data, payments *pay, another_payments *redemption) {
    int error_code = ALLOCATED;
    if(redemption) {
        redemption->current = 0;
    }

    int const_day = data->date.day;
    time_data next_month = data->date;
    next_month.leap = check_leap(next_month.year);
    add_month(&next_month, const_day);

    error_code = init_massive(pay);


    if(data->payment_type == ANNUITY && error_code == ALLOCATED) {
        double monthly_percent = data->rate / (100.0 * 12.0);
        pay->monthly = round(data->debt * monthly_percent / (1 - pow((1.0 + monthly_percent), data->months * (-1))) * 100) / 100;

        for(data->current = -1; data->debt != 0;) {
            check_days(data, &next_month);
            annuity(data, pay, next_month);
            add_month(&(data->date), const_day);
            add_month(&next_month, const_day);
        }
    } else if(data->payment_type == DIFFERENTIATED && error_code == ALLOCATED) {
        pay->main = round(data->debt/data->months * 100) / 100;
        pay->const_main = pay->main;
        
        for(data->current = -1; data->debt != 0; ) {
            long double full_percent = 0;
            check_days(data, &next_month);
            if(redemption && redemption->count) {
                for(int call = 0; compare_month(data->date, &(redemption->date[redemption->current]), next_month); call++) {
                    full_percent = redemp_payment(data, pay, &next_month, redemption, call);
                }
            }
            differentiated(data, pay, next_month, full_percent);
            add_month(&(data->date), const_day);
            add_month(&next_month, const_day);
        }
    }
}