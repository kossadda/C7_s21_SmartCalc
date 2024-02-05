/**
 * @file s21_test_credit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for credit test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _S21_TEST_CREDIT_H_
#define _S21_TEST_CREDIT_H_

#include "./../../debug/debug.h"

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

#endif  // _S21_TEST_CREDIT_H_
