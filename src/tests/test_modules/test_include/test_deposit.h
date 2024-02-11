/**
 * @file test_deposit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for deposit test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _TEST_DEPOSIT_H_
#define _TEST_DEPOSIT_H_

#include "./../../debug/debug.h"

Suite *deposit_by_month(void);
Suite *deposit_by_day(void);
Suite *deposit_by_week(void);
Suite *deposit_by_quarter(void);
Suite *deposit_by_halfyear(void);
Suite *deposit_by_year(void);
Suite *deposit_by_end_term(void);
Suite *deposit_refill_by_day(void);
Suite *deposit_refill_by_week(void);
Suite *deposit_refill_by_month(void);
Suite *deposit_refill_by_quarter(void);
Suite *deposit_refill_by_halfyear(void);
Suite *deposit_refill_by_year(void);
Suite *deposit_refill_by_end_term(void);
Suite *deposit_withdrawals_by_day(void);
Suite *deposit_withdrawals_by_week(void);
Suite *deposit_withdrawals_by_month(void);
Suite *deposit_withdrawals_by_quarter(void);
Suite *deposit_withdrawals_by_halfyear(void);
Suite *deposit_withdrawals_by_year(void);
Suite *deposit_withdrawals_by_end_term(void);
Suite *deposit_combined_with_taxes(void);

#endif  // _TEST_DEPOSIT_H_
