#ifndef S21_C_TESTS_H
#define S21_C_TESTS_H

#include "../s21_main.h"
#include <check.h>

// Functions to test

int test_suite(Suite *test);
void free_credit(int row, payments *pay, early_pay *redemption);
void free_deposit(int row, investment *pay, operations *oper);
void input_credit(credit_init *data, long double debt, long double months, int type, long double rate, int day, int month, int year);
void init_redemption(early_pay *redemption);
void input_redemption(early_pay *redemption, int day, int month, int year, long double sum, int type);
void init_deposit(deposit_init *deposit, long double amount, int term_type, int term, int day, int month, int year, long double rate, int capital_time, int capital);
void init_operations(operations *oper);
void input_operation(operations *oper, int day, int month, int year, long double sum, int type, long double min_balance);

// Calculator tests

Suite *s21_arifmetic_1(void);
Suite *s21_arifmetic_2(void);
Suite *s21_arifmetic_3(void);
Suite *s21_arifmetic_4(void);
Suite *s21_trigonometric_1(void);
Suite *s21_trigonometric_2(void);
Suite *s21_trigonometric_3(void);
Suite *s21_other_1(void);
Suite *s21_other_2(void);
Suite *s21_other_3(void);
Suite *s21_other_4(void);
Suite *s21_other_5(void);
Suite *s21_wrong_expressions_1(void);
Suite *s21_wrong_expressions_2(void);

// Credit tests

Suite *s21_annuity_1(void);
Suite *s21_annuity_2(void);
Suite *s21_annuity_3(void);
Suite *s21_annuity_4(void);
Suite *s21_annuity_5(void);
Suite *s21_differentiated_1(void);
Suite *s21_differentiated_2(void);
Suite *s21_differentiated_3(void);
Suite *s21_differentiated_4(void);
Suite *s21_differentiated_5(void);
Suite *s21_pointer_test(void);
Suite *s21_diff_redemption_term(void);
Suite *s21_diff_redemption_pay(void);
Suite *s21_annuity_redepmtion_term(void);
Suite *s21_annuity_redepmtion_pay(void);
Suite *s21_diff_redepmtion_combinated(void);
Suite *s21_annuity_redepmtion_combinated(void);

// Deposit tests

Suite *s21_deposit_by_month(void);
Suite *s21_deposit_by_day(void);
Suite *s21_deposit_by_week(void);
Suite *s21_deposit_by_quarter(void);
Suite *s21_deposit_by_halfyear(void);
Suite *s21_deposit_by_year(void);
Suite *s21_deposit_by_end_term(void);
Suite *s21_deposit_refill_by_day(void);
Suite *s21_deposit_refill_by_week(void);
Suite *s21_deposit_refill_by_month(void);
Suite *s21_deposit_refill_by_quarter(void);
Suite *s21_deposit_refill_by_halfyear(void);
Suite *s21_deposit_refill_by_year(void);
Suite *s21_deposit_refill_by_end_term(void);
Suite *s21_deposit_withdrawals_by_day(void);
Suite *s21_deposit_withdrawals_by_week(void);
Suite *s21_deposit_withdrawals_by_month(void);
Suite *s21_deposit_withdrawals_by_quarter(void);
Suite *s21_deposit_withdrawals_by_halfyear(void);
Suite *s21_deposit_withdrawals_by_year(void);
Suite *s21_deposit_withdrawals_by_end_term(void);
Suite *s21_deposit_combined_with_taxes(void);

#endif