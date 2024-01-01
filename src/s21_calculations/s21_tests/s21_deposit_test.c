#include "s21_test.h"

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(deposit_by_day_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.61, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_day_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1617.99, 11617.99};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_day_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27692.28, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_day_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {30456.34, 178091.06};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

// START_TEST(deposit_by_day_5)
// {
//     deposit_init data;
//     investment pay;

//     init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, NOT_CAPITAL);

//     calculate_deposit(&data, &pay);
//     long double result_total[2] = {27692.28, 147634.72};

//     for(int i = 0; i < 2; i++) {
//         ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
//     }
//     free_deposit(data.current + 1, &pay);
// }

// START_TEST(deposit_by_day_6)
// {
//     deposit_init data;
//     investment pay;

//     init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_DAY, CAPITAL);

//     calculate_deposit(&data, &pay);
//     long double result_total[2] = {30456.34, 178091.06};

//     for(int i = 0; i < 2; i++) {
//         ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
//     }
//     free_deposit(data.current + 1, &pay);
// }


START_TEST(deposit_by_week_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.09, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_week_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1615.86, 11615.86};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_week_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_WEEK, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27694.5, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_week_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_WEEK, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {30419.95, 178054.67};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_month_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_month_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1607.55, 11607.55};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_month_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_MONTH, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27694.31, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_month_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_MONTH, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {30279.24, 177913.96};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_quarter_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_quarter_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1586.52, 11586.52};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_quarter_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_QUARTER, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27694.36, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_quarter_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_QUARTER, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {29942.8, 177577.52};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_halfyear_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_halfyear_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1556.26, 11556.26};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_halfyear_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_HALFYEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27694.34, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_halfyear_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_HALFYEAR, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {29456.11, 177090.83};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_year_1)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.01, 10000};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_year_2)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 10000, MONTHS_PERIOD, 12, 1, 1, 2020, 15, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {1500.01, 11500.01};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_year_3)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_YEAR, NOT_CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {27694.35, 147634.72};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

START_TEST(deposit_by_year_4)
{
    deposit_init data;
    investment pay;

    init_deposit(&data, 147634.72, MONTHS_PERIOD, 17, 7, 5, 2017, 13.218, BY_YEAR, CAPITAL);

    calculate_deposit(&data, &pay);
    long double result_total[2] = {28775.58, 176410.3};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_deposit(data.current + 1, &pay);
}

Suite *s21_deposit_by_day(void)
{
    Suite *deposit = suite_create("s21_deposit (frequency by day)");

    TCase *tc_deposit_by_day = tcase_create("test_deposit");
    tcase_add_test(tc_deposit_by_day, deposit_by_day_1);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_2);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_3);
    tcase_add_test(tc_deposit_by_day, deposit_by_day_4);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_5);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_6);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_7);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_8);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_9);
    // tcase_add_test(tc_deposit_by_day, deposit_by_day_10);
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
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_5);
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_6);
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_7);
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_8);
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_9);
    // tcase_add_test(tc_deposit_by_week, deposit_by_week_10);
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
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_5);
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_6);
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_7);
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_8);
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_9);
    // tcase_add_test(tc_deposit_by_month, deposit_by_month_10);
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
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_5);
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_6);
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_7);
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_8);
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_9);
    // tcase_add_test(tc_deposit_by_quarter, deposit_by_quarter_10);
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
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_5);
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_6);
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_7);
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_8);
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_9);
    // tcase_add_test(tc_deposit_by_halfyear, deposit_by_halfyear_10);
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
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_5);
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_6);
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_7);
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_8);
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_9);
    // tcase_add_test(tc_deposit_by_year, deposit_by_year_10);
    suite_add_tcase(deposit, tc_deposit_by_year);

    return deposit;
}
