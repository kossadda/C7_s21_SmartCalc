/**
 * @file test_smartcalc.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for smartcalc test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _TEST_SMARTCALC_H_
#define _TEST_SMARTCALC_H_

#include "./../../debug/debug.h"

Suite *arifmetic_1(void);
Suite *arifmetic_2(void);
Suite *arifmetic_3(void);
Suite *arifmetic_4(void);
Suite *trigonometric_1(void);
Suite *trigonometric_2(void);
Suite *trigonometric_3(void);
Suite *other_1(void);
Suite *other_2(void);
Suite *other_3(void);
Suite *other_4(void);
Suite *other_5(void);
Suite *wrong_expressions_1(void);
Suite *wrong_expressions_2(void);

#endif  // _TEST_SMARTCALC_H_
