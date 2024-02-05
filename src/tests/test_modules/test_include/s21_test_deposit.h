/**
 * @file s21_test_deposit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for deposit test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _S21_TEST_DEPOSIT_H_
#define _S21_TEST_DEPOSIT_H_

#include "./../../debug/debug.h"

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

#endif  // _S21_TEST_DEPOSIT_H_
