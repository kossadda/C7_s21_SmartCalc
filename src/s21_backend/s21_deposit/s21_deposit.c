#include "s21_deposit.h"

static int init_taxes(investment *pay);

/**
 * @brief Main function for calculating payments for all deposit term.
 * 
 * @param[in] data structure containing input parameters for calculation.
 * @param[in] pay structure containing buffer variables for monthly results and general payment data arrays.
 * 
 * @return Error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
*/
int calculate_deposit(deposit_init *data, investment *pay, operations *oper)
{
    int error_code_depos = CHECK_NULL(data);
    int error_code_pay = CHECK_NULL(pay);
    int error_code = error_code_depos + error_code_pay;

    int const_day = data->date.day;
    time_data last_day = determine_last_day(data->date, data->term_type, data->term);

    if(error_code == ALLOCATED) {
        if(oper) {
            oper->current = 0;
        }
        pay->taxes_count = 0;
        data->date.leap = check_leap(data->date.year);

        int error_code_payments = init_payments(&pay->result, &pay->total);
        int error_code_taxes = init_taxes(pay);

        error_code = error_code_payments + error_code_taxes;
    }

    if(error_code == ALLOCATED) {
        time_data end_period = data->date;
        long double non_taxable_amount = NON_TAX_SUM * TAX_RATE / 100;
        long double year_profit = 0;
        long double year_tax = 0;
        
        for(data->current = -1; compare_dates(data->date, last_day) != DATE_EQUAL;) {
            long double percent = 0;

            add_one_period(&(data->date), &end_period, last_day, data->capital_time, const_day);

            error_code = check_operation(data, pay, oper, &end_period, &percent);
            
            if(error_code == ALLOCATED) {
                error_code = calc_period(data, pay, end_period, percent);
            }









            if(data->date.month == DECEMBER) {
                allocate_row(&pay->taxes, pay->taxes_count, TAXES_COLUMNS);
                if(year_profit > non_taxable_amount) {
                    year_tax = (year_profit - non_taxable_amount) * NDFL_RATE / 100;

                    pay->taxes[pay->taxes_count][1] = year_profit;
                    pay->taxes[pay->taxes_count][3] = year_profit - non_taxable_amount;
                    pay->taxes[pay->taxes_count][4] = year_tax;
                    year_profit = 0; 
                } else {
                    pay->taxes[pay->taxes_count][1] = 0;
                    pay->taxes[pay->taxes_count][3] = 0;
                    pay->taxes[pay->taxes_count][4] = 0;
                }
                pay->taxes[pay->taxes_count][0] = data->date.year;
                pay->taxes[pay->taxes_count][2] = non_taxable_amount;
                 
                pay->taxes_count++;

            }
            if(compare_dates(end_period, last_day) == DATE_EQUAL) {
                allocate_row(&pay->taxes, pay->taxes_count, TAXES_COLUMNS);
                if(year_profit > non_taxable_amount) {
                    year_tax = (year_profit + pay->profit - non_taxable_amount) * NDFL_RATE / 100;
                    
                    pay->taxes[pay->taxes_count][1] = year_profit + pay->profit;
                    pay->taxes[pay->taxes_count][3] = year_profit + pay->profit - non_taxable_amount;
                    pay->taxes[pay->taxes_count][4] = year_tax;
                } else {
                    pay->taxes[pay->taxes_count][1] = 0;
                    pay->taxes[pay->taxes_count][3] = 0;
                    pay->taxes[pay->taxes_count][4] = 0;
                }

                pay->taxes[pay->taxes_count][0] = data->date.year;
                pay->taxes[pay->taxes_count][2] = non_taxable_amount;
                
                pay->taxes_count++;
            }









            year_profit += pay->profit;

            data->date = (error_code == ALLOCATED) ? end_period : last_day;
        }
    }
    return error_code;
}

static int init_taxes(investment *pay)
{
    int error_code = NOT_ALLOCATED;
    
    pay->taxes = (long double **)malloc(1 * sizeof(long double *));
    error_code = CHECK_NULL(pay->taxes);

    return error_code;
}

// static int allocate_tax_row(investment *pay)
// {
//     int error_code = NOT_ALLOCATED;

//     pay->taxes = (long double **)realloc(*pay->taxes, (pay->taxes_count + 1) * sizeof(long double *));
//     int error_code_t = CHECK_NULL(*result);

//     (*result)[current] = (long double *)malloc(4 * sizeof(long double));
//     int error_code_column = CHECK_NULL((*result)[current]);

//     error_code = error_code_row + error_code_column;

//     return error_code;
// }