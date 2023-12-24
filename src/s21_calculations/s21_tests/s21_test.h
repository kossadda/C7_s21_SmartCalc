#ifndef S21_C_TESTS_H
#define S21_C_TESTS_H

#include "../s21_main.h"
#include <check.h>

// functions to test

int test_suite(Suite *test);
void free_memory(int row, payments *pay, another_payments *redemption);
void input_initial(initial *data, long double debt, long double months, int type, long double rate, int day, int month, int year);
void input_redemption(another_payments *redemption, int day, int month, int year, long double sum, int type);

// calculator tests

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

// credit tests

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
Suite *s21_redemption_term_1(void);
Suite *s21_redemption_pay_1(void);
 
#endif