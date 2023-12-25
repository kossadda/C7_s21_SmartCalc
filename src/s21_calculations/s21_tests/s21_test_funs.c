#include "s21_test.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/// @brief Function for clearing memory in payments arrays
/// @param pay Structure containing buffer variables for monthly results and general payment data arrays
void free_memory(int row, payments *pay, another_payments *redemption) {
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
/// @brief Function for testing the specified Suite
/// @param test Input Suite tests
/// @return Returns the error code. If the tests pass successfully - EXIT_SUCCESS, if unsuccessful - EXIT_FAILURE
int test_suite(Suite *test) {
    SRunner *suite_runner = srunner_create(test);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

/// @brief Function for entering initial data
/// @param data Structure containing input parameters for calculation
/// @param debt Balance owed
/// @param months Number of months of lending
/// @param type Payment type. ANNUITS - annuity, DEFFERENTIATED - differentiated
/// @param rate Interest rate
/// @param day Day of loan issue
/// @param month Month of loan issue
/// @param year Year of loan issue
void input_initial(initial *data, long double debt, long double months, int type, long double rate, int day, int month, int year) {
    data->debt = debt;
    data->months = months;
    data->payment_type = type;
    data->rate = rate;
    data->date.day = day;
    data->date.month = month;
    data->date.year = year;
}

void input_redemption(another_payments *redemption, int day, int month, int year, long double sum, int type) {
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