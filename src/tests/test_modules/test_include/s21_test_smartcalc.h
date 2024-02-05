/**
 * @file s21_test_smartcalc.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for smartcalc test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _S21_TEST_SMARTCALC_H_
#define _S21_TEST_SMARTCALC_H_

#include "./../../debug/debug.h"

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

#endif  // _S21_TEST_SMARTCALC_H_
