#include "s21_credit.h"

static int calculate_this_month(initial *data, payments *pay, time_data next_month, long double paid_percent);
static int check_and_calc_redemption(initial *data, payments *pay, early_pay *redemption, time_data *next_month, long double *paid_percent);

/**
 * @brief Calculates monthly payments by differentiated payment type.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param[in] redemption structure containing data on early repayments.
 * @param next_month structure containing the payment end date for the current month.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int differentiated(initial *data, payments *pay, early_pay *redemption, time_data next_month)
{
    int error_code = ALLOCATED;
    int const_day = data->date.day;
    pay->main = round_value(data->debt/data->months);
    pay->const_main = pay->main;
    
    for(data->current = -1; data->debt != 0; ) {
        long double paid_percent = 0;
        determine_date(&data->date, &next_month);
        error_code = check_and_calc_redemption(data, pay, redemption, &next_month, &paid_percent);
        error_code = (error_code == ALLOCATED) ? calculate_this_month(data, pay, next_month, paid_percent) : error_code;
        add_month(&(data->date), const_day);
        add_month(&next_month, const_day);
        data->debt = (error_code == ALLOCATED) ? data->debt : 0;
    }
    return error_code;
}

/**
 * @brief Function for calculating monthly payments of annuity type.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * @param next_month structure containing the payment end date for the current month.
 * @param paid_percent the amount deducted from the monthly interest in case of early repayment.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int calculate_this_month(initial *data, payments *pay, time_data next_month, long double paid_percent)
{
    int error_code = ALLOCATED;
    if(data->debt) {
        data->current++;
        error_code = allocate_memory(data, pay);
        if(error_code == ALLOCATED) {
            if(data->debt < pay->main) {
                pay->main = data->debt;
            }
            calc_percent(data, pay, next_month);
            pay->percent -= paid_percent;
            pay->monthly = pay->main + pay->percent;
            data->debt -= pay->main;
            remember_result(data, pay);
        }
    }
    return error_code;
}

/**
 * @brief Determines whether the current early repayment is within the current month and calculates it
 * 
 * @param[in] data structure containing input parameters for calculation
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays
 * @param[in] redemption structure containing data on early repayments
 * @param[in] next_month structure containing the payment end date for the current month
 * @param[in] paid_percent the amount deducted from the monthly interest in case of early repayment
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
static int check_and_calc_redemption(initial *data, payments *pay, early_pay *redemption, time_data *next_month, long double *paid_percent)
{
    int error_code = ALLOCATED;
    int change = DEBT_NOT_CHANGED;
    if(redemption && redemption->sum && redemption->current < redemption->count) {
        while(compare_date_with_month(data->date, &(redemption->date[redemption->current]), *next_month) == DATE_BETWEEN) {
            error_code = redemp_payment(data, pay, next_month, redemption, paid_percent, &change);
            if(redemption->current == redemption->count) {
                break;
            }
        }
    }
    return error_code;
}
