#include "s21_test.h"

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_day_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.61, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1617.99, 11617.99};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27692.28, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {30456.34, 178091.06};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229644.87, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {261720.87, 1157346.24};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.82, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {5034923.39, 12812701.16};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931284.35, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_day_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {6966499579.12, 7293241321.98};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_week_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.09, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1615.86, 11615.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.5, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {30419.95, 178054.67};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.64, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {261421.69, 1157047.06};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882819.34, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {5030844.09, 12808621.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 18037, 1, 1, 2024, 16.123, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {2601410292.21, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_week_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 18037, 1, 1, 2024, 16.123, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {925615593479.03, 925942335221.89};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_month_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1607.55, 11607.55};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.31, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {30279.24, 177913.96};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.87, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {260259.36, 1155884.73};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.11, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {5014960.02, 12792737.79};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931288.92, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_month_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {6822138779.35, 7148880522.21};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_quarter_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1586.52, 11586.52};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.36, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {29942.8, 177577.52};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.87, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {257405.01, 1153030.38};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.14, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {4974861.53, 12752639.3};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931289.5, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_quarter_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {6540254793.1, 6866996535.96};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_halfyear_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1556.26, 11556.26};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.34, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {29456.11, 177090.83};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.87, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {253275.69, 1148901.06};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.19, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {4916176.13, 12693953.9};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931289.31, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_halfyear_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {6158421560.45, 6485163303.31};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_year_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 11500.01};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.35, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {28775.58, 176410.3};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.87, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_6)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {245520.84, 1141146.21};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_7)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.18, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_8)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {4809852.33, 12587630.1};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_9)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931289.4, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_year_10)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {5505997235.41, 5832738978.27};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_by_end_term_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_END_TERM, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_end_term_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_END_TERM, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {27694.35, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_end_term_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 895625.37, MONTHS_PERIOD, 25, 8, 2, 1988, 12.345, BY_END_TERM, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {229643.88, 895625.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_end_term_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 7777777.77, MONTHS_PERIOD, 77, 7, 7, 1977, 7.777, BY_END_TERM, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {3882818.17, 7777777.77};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

START_TEST(deposit_by_end_term_5)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 326741742.86, DAYS_PERIOD, 7037, 1, 1, 2024, 16.123, BY_END_TERM, NOT_CAPITAL);

    calculate_deposit(&data, &pay, NULL);
    long double result_total[2] = {1014931289.38, 326741742.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, NULL);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_day_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_DAY, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {27815.05, 202815.05};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.28, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_DAY, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5303950.87, 19117885.09};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471749.36, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_DAY, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41526809.44, 186029932.67};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947582.6, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_DAY, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {50861846.52, 92932826.95};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092108.47, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_DAY, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {42493683.37, 116168328.6};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_day_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086504.37, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_week_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_WEEK, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {27778.37, 202778.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.87, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_WEEK, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5299936.53, 19113870.75};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.25, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_WEEK, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41505063.46, 186008186.69};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947583.74, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_WEEK, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {50810309.72, 92881290.15};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092100.07, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_WEEK, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {42459188.99, 116133834.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_week_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086507.75, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_month_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_MONTH, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {27636.03, 202636.03};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_MONTH, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5284328.43, 19098262.65};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.2, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_MONTH, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41420296.14, 185923419.37};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947584.18, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_MONTH, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {50610081.91, 92681062.34};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092099.52, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_MONTH, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {42325111.44, 115999756.67};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_month_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086508.05, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_quarter_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_QUARTER, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {27279.01, 202279.01};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_QUARTER, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5245229.35, 19059163.57};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.16, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_QUARTER, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41202790.15, 185705913.38};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947584.13, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_QUARTER, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {50102707.75, 92173688.18};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092099.68, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_QUARTER, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41986483.1, 115661128.33};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_quarter_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086507.93, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_halfyear_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26767.44, 201767.44};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5189094.39, 19003028.61};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.18, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {40882001.62, 185385124.85};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947584.14, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {49364771.59, 91435752.02};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092099.7, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {41500138.75, 115174783.98};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_halfyear_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086507.98, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_year_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_YEAR, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 200815.83};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_YEAR, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {5086208.02, 18900142.24};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.17, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_YEAR, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {40340725.2, 184843848.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947584.14, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_YEAR, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {47963663.67, 90034644.1};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092099.71, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_YEAR, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {40599318.75, 114273963.98};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_year_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086507.98, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_refill_by_end_term_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {25815.83, 175000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_end_term_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4471747.18, 13813934.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_end_term_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, REFILL, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {35947584.13, 144503123.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_end_term_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, REFILL, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33092099.71, 42070980.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_refill_by_end_term_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, REFILL, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, REFILL, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, REFILL, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {33086507.98, 73674645.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_day_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_DAY, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {20739.51, 145739.51};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19197.01, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_DAY, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4878199.41, 16220999.63};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078896.96, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_DAY, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {31861340.39, 92629329.62};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799978.62, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_DAY, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2667113.45, 293649.88};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462850.13, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_DAY, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {38018815.09, 89471240.32};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_day_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_DAY, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082699.38, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_week_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_WEEK, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {20712.22, 145712.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19197.14, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_WEEK, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4874480.79, 16217281.01};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.91, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_WEEK, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {31844231.67, 92612220.9};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.96, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_WEEK, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2663355.22, 289891.65};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462845.41, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_WEEK, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {37987524.98, 89439950.21};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_week_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_WEEK, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082701.1, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_month_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_MONTH, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {20604.87, 145604.87};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_MONTH, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4860015.6, 16202815.82};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.78, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_MONTH, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {31777599.25, 92545588.48};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.96, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_MONTH, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2648712.42, 275248.85};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462843.42, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_MONTH, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {37865831.27, 89318256.5};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_month_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_MONTH, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082700.21, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_quarter_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_QUARTER, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {20330.35, 145330.35};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_QUARTER, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4823663.1, 16166463.32};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.87, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_QUARTER, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {31605984.47, 92373973.7};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.96, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_QUARTER, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2611594.37, 238130.8};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462843.39, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_QUARTER, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {37557368.32, 89009793.55};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_quarter_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_QUARTER, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082700.16, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_halfyear_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19933.78, 144933.78};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4771120.2, 16113920.42};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.92, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {31352883.68, 92120872.91};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.97, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2557792.72, 184329.15};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462843.28, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {37111947.66, 88564372.89};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_halfyear_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_HALFYEAR, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082700.15, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_year_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_YEAR, CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 144196.97};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_YEAR, CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4673986.21, 16016786.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.91, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_YEAR, CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {30879882.35, 91647871.58};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_6)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.98, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_7)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_YEAR, CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {2456615.95, 83152.38};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_8)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462843.38, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_9)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_YEAR, CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {36275146.38, 87727571.61};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_year_10)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_YEAR, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082700.15, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_withdrawals_by_end_term_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 150000, MONTHS_PERIOD, 12, 23, 11, 2023, 15, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 5, 1, 2024, 25000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {19196.97, 125000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_end_term_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12578367.22, MONTHS_PERIOD, 52, 15, 2, 2011, 7.852, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 6, 6, 2013, 1235567, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {4078895.91, 11342800.22};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_end_term_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 102635556.23, MONTHS_PERIOD, 66, 7, 2, 2021, 5.562, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 7, 8, 2024, 25715345, WITHDRAWALS, 0);
    input_operation(&oper, 9, 9, 2024, 16152222, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {26799981.96, 60767989.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_end_term_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 8737647.43, MONTHS_PERIOD, 121, 31, 1, 2015, 8.476, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 2, 2, 2015, 22222222, WITHDRAWALS, 0);
    input_operation(&oper, 2, 2, 2018, 11111111, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {7462843.34, 8737647.43};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_withdrawals_by_end_term_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2020, 7.851, BY_END_TERM, NOT_CAPITAL);
    input_operation(&oper, 3, 5, 2022, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2024, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2025, 3333333, WITHDRAWALS, 0);
    input_operation(&oper, 10, 7, 2025, 4444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[2] = {29082700.15, 51452425.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay, &oper);
}

//  ==========================================================================================================================================================================================

START_TEST(deposit_hardest_combined_with_taxes_1)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 62563535.23, MONTHS_PERIOD, 76, 22, 11, 2024, 7.851, BY_MONTH, CAPITAL);
    input_operation(&oper, 3, 5, 2026, 1111111, WITHDRAWALS, 0);
    input_operation(&oper, 29, 2, 2028, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 3, 7, 2029, 5555555, REFILL, 0);
    input_operation(&oper, 10, 7, 2029, 84444444, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[] = {27771206.62, 8112519.85};
    long double taxes_total[] = {31539.52, 645439.9, 692317.11, 746005.07, 789538.84, 482595.78, 57065.31, 0};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    for(int i = 0; i < pay.taxes_count; i++) {
        ck_assert_double_eq_tol(taxes_total[i], pay.taxes[i][4], 1e-3);
    }

    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_hardest_combined_with_taxes_2)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 12343452.12, MONTHS_PERIOD, 51, 29, 2, 2028, 11.213, BY_QUARTER, CAPITAL);
    input_operation(&oper, 1, 2, 2029, 2533444, REFILL, 0);
    input_operation(&oper, 5, 6, 2030, 1245234, WITHDRAWALS, 0);
    input_operation(&oper, 1, 1, 2031, 2222222, WITHDRAWALS, 0);
    input_operation(&oper, 11, 11, 2031, 987656, REFILL, 0);
    input_operation(&oper, 8, 7, 2032, 12423556, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[] = {7904118.47, 20301214.59};
    long double taxes_total[] = {117705.23, 215840.09, 240191.97, 230803.86, 118994.26};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    for(int i = 0; i < pay.taxes_count; i++) {
        ck_assert_double_eq_tol(taxes_total[i], pay.taxes[i][4], 1e-3);
    }

    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_hardest_combined_with_taxes_3)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 9999999.99, MONTHS_PERIOD, 99, 9, 9, 2029, 9.999, BY_DAY, CAPITAL);
    input_operation(&oper, 4, 12, 2029, 6672311, WITHDRAWALS, 0);
    input_operation(&oper, 1, 2, 2030, 42335566, REFILL, 0);
    input_operation(&oper, 7, 2, 2030, 31000000, WITHDRAWALS, 0);
    input_operation(&oper, 28, 2, 2030, 3211111, REFILL, 0);
    input_operation(&oper, 8, 8, 2035, 12001233, WITHDRAWALS, 0);
    input_operation(&oper, 5, 6, 2037, 1987656, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[] = {18969788.40, 26830577.39};
    long double taxes_total[] = {13627.57, 212783.29, 251701.34, 280353.54, 312018.13, 347012.21, 322474.46, 257736.70, 281165.25};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    for(int i = 0; i < pay.taxes_count; i++) {
        ck_assert_double_eq_tol(taxes_total[i], pay.taxes[i][4], 1e-3);
    }

    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_hardest_combined_with_taxes_4)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 61253378.11, MONTHS_PERIOD, 92, 21, 2, 2029, 22.311, BY_WEEK, CAPITAL);
    input_operation(&oper, 4, 12, 2029, 6672311, WITHDRAWALS, 0);
    input_operation(&oper, 1, 2, 2030, 42335566, REFILL, 0);
    input_operation(&oper, 7, 2, 2030, 31000000, WITHDRAWALS, 0);
    input_operation(&oper, 28, 2, 2030, 3211111, REFILL, 0);
    input_operation(&oper, 8, 8, 2033, 12001233, WITHDRAWALS, 0);
    input_operation(&oper, 5, 6, 2034, 1987656, REFILL, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[] = {291466976.93, 350581144.04};
    long double taxes_total[] = {1613201.00, 2576462.36, 3335798.59, 4087113.25, 4979624.68, 6010542.11, 7539762.38, 7581802.63};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    for(int i = 0; i < pay.taxes_count; i++) {
        ck_assert_double_eq_tol(taxes_total[i], pay.taxes[i][4], 1e-3);
    }

    free_deposit(data.current + 1, &pay, &oper);
}

START_TEST(deposit_hardest_combined_with_taxes_5)
{
    deposit_init data;
    investment pay;
    operations oper;
    init_operations(&oper);

    init_deposit(&data, 771332.12, MONTHS_PERIOD, 56, 22, 6, 2025, 17.275, BY_HALFYEAR, CAPITAL);
    input_operation(&oper, 23, 6, 2025, 42335566, REFILL, 0);
    input_operation(&oper, 29, 7, 2025, 1987656, REFILL, 0);
    input_operation(&oper, 8, 8, 2025, 12001233, WITHDRAWALS, 0);
    input_operation(&oper, 28, 2, 2029, 3211111, REFILL, 0);
    input_operation(&oper, 4, 12, 2029, 6672311, WITHDRAWALS, 0);
    input_operation(&oper, 7, 2, 2030, 31000000, WITHDRAWALS, 0);

    calculate_deposit(&data, &pay, &oper);
    long double result_total[] = {39244887.07, 37877008.19};
    long double taxes_total[] = {379390.00, 826608.15, 979320.07, 1159635.47, 1425421.40, 206660.23};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    for(int i = 0; i < pay.taxes_count; i++) {
        ck_assert_double_eq_tol(taxes_total[i], pay.taxes[i][4], 1e-3);
    }

    free_deposit(data.current + 1, &pay, &oper);
}

Suite *s21_deposit_by_day(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by day)");

    TCase *tc_deposit_by_day = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_day, deposit_by_day_1);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_2);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_3);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_4);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_5);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_6);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_7);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_8);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_9);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_10);
    suite_add_tcase(deposit, tc_deposit_by_day);

    return deposit;
}

Suite *s21_deposit_by_week(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by week)");

    TCase *tc_deposit_by_week = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_week, deposit_by_week_1);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_2);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_3);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_4);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_5);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_6);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_7);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_8);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_9);
    tcase_add_test(tc_deposit_by_week, deposit_by_week_10);
    suite_add_tcase(deposit, tc_deposit_by_week);

    return deposit;
}

Suite *s21_deposit_by_month(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by month)");

    TCase *tc_deposit_by_month = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_month, deposit_by_month_1);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_2);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_3);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_4);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_5);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_6);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_7);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_8);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_9);
    tcase_add_test(tc_deposit_by_month, deposit_by_month_10);
    suite_add_tcase(deposit, tc_deposit_by_month);

    return deposit;
}

Suite *s21_deposit_by_quarter(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by quarter)");

    TCase *tc_deposit_by_quarter = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_1);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_2);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_3);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_4);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_5);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_6);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_7);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_8);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_9);
    tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_10);
    suite_add_tcase(deposit, tc_deposit_by_quarter);

    return deposit;
}

Suite *s21_deposit_by_halfyear(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by halfyear)");

    TCase *tc_deposit_by_halfyear = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_1);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_2);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_3);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_4);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_5);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_6);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_7);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_8);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_9);
    tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_10);
    suite_add_tcase(deposit, tc_deposit_by_halfyear);

    return deposit;
}

Suite *s21_deposit_by_year(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by year)");

    TCase *tc_deposit_by_year = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_year, deposit_by_year_1);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_2);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_3);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_4);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_5);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_6);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_7);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_8);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_9);
    tcase_add_test(tc_deposit_by_year, deposit_by_year_10);
    suite_add_tcase(deposit, tc_deposit_by_year);

    return deposit;
}

Suite *s21_deposit_by_end_term(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by end term)");

    TCase *tc_deposit_by_end_term = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_end_term, deposit_by_end_term_1);
    tcase_add_test(tc_deposit_by_end_term, deposit_by_end_term_2);
    tcase_add_test(tc_deposit_by_end_term, deposit_by_end_term_3);
    tcase_add_test(tc_deposit_by_end_term, deposit_by_end_term_4);
    tcase_add_test(tc_deposit_by_end_term, deposit_by_end_term_5);
    suite_add_tcase(deposit, tc_deposit_by_end_term);

    return deposit;
}

Suite *s21_deposit_refill_by_day(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by day)");

    TCase *tc_deposit_refill_by_day = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_1);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_2);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_3);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_4);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_5);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_6);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_7);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_8);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_9);
    tcase_add_test(tc_deposit_refill_by_day, deposit_refill_by_day_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_day);

    return deposit;
}

Suite *s21_deposit_refill_by_week(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by week)");

    TCase *tc_deposit_refill_by_week = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_1);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_2);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_3);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_4);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_5);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_6);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_7);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_8);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_9);
    tcase_add_test(tc_deposit_refill_by_week, deposit_refill_by_week_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_week);

    return deposit;
}

Suite *s21_deposit_refill_by_month(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by month)");

    TCase *tc_deposit_refill_by_month = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_1);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_2);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_3);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_4);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_5);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_6);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_7);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_8);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_9);
    tcase_add_test(tc_deposit_refill_by_month, deposit_refill_by_month_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_month);

    return deposit;
}

Suite *s21_deposit_refill_by_quarter(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by quarter)");

    TCase *tc_deposit_refill_by_quarter = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_1);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_2);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_3);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_4);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_5);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_6);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_7);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_8);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_9);
    tcase_add_test(tc_deposit_refill_by_quarter, deposit_refill_by_quarter_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_quarter);

    return deposit;
}

Suite *s21_deposit_refill_by_halfyear(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by halfyear)");

    TCase *tc_deposit_refill_by_halfyear = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_1);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_2);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_3);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_4);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_5);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_6);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_7);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_8);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_9);
    tcase_add_test(tc_deposit_refill_by_halfyear, deposit_refill_by_halfyear_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_halfyear);

    return deposit;
}

Suite *s21_deposit_refill_by_year(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by year)");

    TCase *tc_deposit_refill_by_year = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_1);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_2);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_3);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_4);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_5);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_6);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_7);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_8);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_9);
    tcase_add_test(tc_deposit_refill_by_year, deposit_refill_by_year_10);
    suite_add_tcase(deposit, tc_deposit_refill_by_year);

    return deposit;
}

Suite *s21_deposit_refill_by_end_term(void)
{
    Suite *deposit = suite_create("s21_deposit (with refill and frequency by end term)");

    TCase *tc_deposit_refill_by_end_term = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_refill_by_end_term, deposit_refill_by_end_term_1);
    tcase_add_test(tc_deposit_refill_by_end_term, deposit_refill_by_end_term_2);
    tcase_add_test(tc_deposit_refill_by_end_term, deposit_refill_by_end_term_3);
    tcase_add_test(tc_deposit_refill_by_end_term, deposit_refill_by_end_term_4);
    tcase_add_test(tc_deposit_refill_by_end_term, deposit_refill_by_end_term_5);
    suite_add_tcase(deposit, tc_deposit_refill_by_end_term);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_day(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by day)");

    TCase *tc_deposit_withdrawals_by_day = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_1);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_2);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_3);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_4);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_5);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_6);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_7);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_8);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_9);
    tcase_add_test(tc_deposit_withdrawals_by_day, deposit_withdrawals_by_day_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_day);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_week(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by week)");

    TCase *tc_deposit_withdrawals_by_week = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_1);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_2);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_3);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_4);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_5);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_6);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_7);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_8);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_9);
    tcase_add_test(tc_deposit_withdrawals_by_week, deposit_withdrawals_by_week_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_week);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_month(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by month)");

    TCase *tc_deposit_withdrawals_by_month = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_1);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_2);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_3);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_4);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_5);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_6);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_7);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_8);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_9);
    tcase_add_test(tc_deposit_withdrawals_by_month, deposit_withdrawals_by_month_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_month);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_quarter(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by quarter)");

    TCase *tc_deposit_withdrawals_by_quarter = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_1);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_2);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_3);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_4);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_5);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_6);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_7);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_8);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_9);
    tcase_add_test(tc_deposit_withdrawals_by_quarter, deposit_withdrawals_by_quarter_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_quarter);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_halfyear(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by halfyear)");

    TCase *tc_deposit_withdrawals_by_halfyear = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_1);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_2);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_3);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_4);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_5);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_6);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_7);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_8);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_9);
    tcase_add_test(tc_deposit_withdrawals_by_halfyear, deposit_withdrawals_by_halfyear_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_halfyear);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_year(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by year)");

    TCase *tc_deposit_withdrawals_by_year = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_1);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_2);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_3);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_4);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_5);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_6);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_7);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_8);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_9);
    tcase_add_test(tc_deposit_withdrawals_by_year, deposit_withdrawals_by_year_10);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_year);

    return deposit;
}

Suite *s21_deposit_withdrawals_by_end_term(void)
{
    Suite *deposit = suite_create("s21_deposit (with withdrawals and frequency by end term)");

    TCase *tc_deposit_withdrawals_by_end_term = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_withdrawals_by_end_term, deposit_withdrawals_by_end_term_1);
    tcase_add_test(tc_deposit_withdrawals_by_end_term, deposit_withdrawals_by_end_term_2);
    tcase_add_test(tc_deposit_withdrawals_by_end_term, deposit_withdrawals_by_end_term_3);
    tcase_add_test(tc_deposit_withdrawals_by_end_term, deposit_withdrawals_by_end_term_4);
    tcase_add_test(tc_deposit_withdrawals_by_end_term, deposit_withdrawals_by_end_term_5);
    suite_add_tcase(deposit, tc_deposit_withdrawals_by_end_term);

    return deposit;
}

Suite *s21_deposit_combined_with_taxes(void)
{
    Suite *deposit = suite_create("s21_deposit (hardest variations combined with taxes)");

    TCase *tc_deposit_combined_with_taxes = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_combined_with_taxes, deposit_hardest_combined_with_taxes_1);
    tcase_add_test(tc_deposit_combined_with_taxes, deposit_hardest_combined_with_taxes_2);
    tcase_add_test(tc_deposit_combined_with_taxes, deposit_hardest_combined_with_taxes_3);
    tcase_add_test(tc_deposit_combined_with_taxes, deposit_hardest_combined_with_taxes_4);
    tcase_add_test(tc_deposit_combined_with_taxes, deposit_hardest_combined_with_taxes_5);
    suite_add_tcase(deposit, tc_deposit_combined_with_taxes);

    return deposit;
}