#include "s21_test.h"

/**
 * @brief Function for clearing memory in payments arrays.
 * 
 * @param pay structure containing buffer variables for monthly results and general payment data arrays.
*/
void free_credit(int row, payments *pay, early_pay *redemption) {
    if(pay) {
        int redemp_rows = 0;
        if(redemption) {
            redemp_rows = 1;
        }
        for(int i = 0; i < row + redemp_rows; i++) {
            free(pay->result[i]);
            pay->result[i] = NULL;
        }
        if(pay->result) {
            free(pay->result);
            pay->result = NULL;
        }
        if(pay->total) {
            free(pay->total);
            pay->total = NULL;
        }
    }
    if(redemption) {
        if(redemption->date) {
            free(redemption->date);
            redemption->date = NULL;
        }
        if(redemption->sum) {
            free(redemption->sum);
            redemption->sum = NULL;
        }
        if(redemption->type) {
            free(redemption->type);
            redemption->type = NULL;
        }
    }
}

void free_deposit(int row, investment *pay) {
    if(pay) {
        for(int i = 0; i < row; i++) {
            free(pay->result[i]);
            pay->result[i] = NULL;
        }
        if(pay->result) {
            free(pay->result);
            pay->result = NULL;
        }
        if(pay->total) {
            free(pay->total);
            pay->total = NULL;
        }
    }
}

/**
 * @brief Function for testing the specified Suite.
 * 
 * @param test input Suite tests
 * 
 * @return Returns the error code.
 * @retval EXIT_SUCCESS = 0 - if the tests pass successfully.
 * @retval EXIT_FAILURE = 1 - if the tests pass unsuccessful.
*/
int test_suite(Suite *test) {
    SRunner *suite_runner = srunner_create(test);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

/**
 * @brief Function for filling in loan initialization fields.
 * 
 * @param data structure containing input parameters for calculation.
 * @param debt balance owed.
 * @param months number of months of lending.
 * @param type payment type. ANNUITY - annuity, DEFFERENTIATED - differentiated.
 * @param rate interest rate.
 * @param day day of loan issue.
 * @param month month of loan issue.
 * @param year year of loan issue.
*/
void input_initial(initial *data, long double debt, long double months, int type, long double rate, int day, int month, int year) {
    data->debt = debt;
    data->months = months;
    data->payment_type = type;
    data->rate = rate;
    data->date.day = day;
    data->date.month = month;
    data->date.year = year;
}

/**
 * @brief Function for filling in the fields for initializing early repayment.
 * 
 * @param day day of early payment.
 * @param month month of early payment.
 * @param year year of early payment.
 * @param sum sum of early payment.
 * @param type type of early payment.
*/
void input_redemption(early_pay *redemption, int day, int month, int year, long double sum, int type) {
    redemption->date = (time_data *)realloc(redemption->date, (redemption->count + 1) * sizeof(time_data));
    redemption->sum = (long double *)realloc(redemption->sum, (redemption->count + 1) * sizeof(long double));
    redemption->type = (int *)realloc(redemption->type, (redemption->count + 1) * sizeof(int));
    redemption->date[redemption->count].day = day;
    redemption->date[redemption->count].month = month;
    redemption->date[redemption->count].year = year;
    redemption->sum[redemption->count] = sum;
    redemption->type[redemption->count] = type;
    redemption->count++; 
}

/**
 * @brief Function for filling in deposit initialization fields.
 * 
 * @param amount amount of deposit.
 * @param term_type type of deposit term.
 * @param term deposit term.
 * @param day deposit opening day.
 * @param month deposit opening month.
 * @param year deposit opening year.
 * @param rate deposit interest rate.
 * @param capital_time frequency of deposit payments.
 * @param capital Deposit capitalization enabled/disabled. NOT_CAPIT = 0 -  disabled, CAPIT = 1 - enabled.
*/
void init_deposit(init *deposit, long double amount, int term_type, int term, int day, int month, int year, long double rate, int capital_time, int capital) {
    deposit->amount = amount;
    deposit->term_type = term_type;
    deposit->term = term;
    deposit->date.day = day;
    deposit->date.month = month;
    deposit->date.year = year;
    deposit->rate = rate;
    deposit->capital_time = capital_time;
    deposit->capital = capital;
}