/**
 * @file test_credit.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for credit test module.
 * @version 1.0
 * @date 2024-02-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _TEST_CREDIT_H_
#define _TEST_CREDIT_H_

#include "./../../debug/debug.h"

Suite *annuity_1(void);
Suite *annuity_2(void);
Suite *annuity_3(void);
Suite *annuity_4(void);
Suite *annuity_5(void);
Suite *differentiated_1(void);
Suite *differentiated_2(void);
Suite *differentiated_3(void);
Suite *differentiated_4(void);
Suite *differentiated_5(void);
Suite *pointer_test(void);
Suite *diff_redemption_term(void);
Suite *diff_redemption_pay(void);
Suite *annuity_redepmtion_term(void);
Suite *annuity_redepmtion_pay(void);
Suite *diff_redepmtion_combinated(void);
Suite *annuity_redepmtion_combinated(void);

#endif  // _TEST_CREDIT_H_
