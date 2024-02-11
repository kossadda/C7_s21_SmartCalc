/**
 * @file debug.h
 * @author emmonbea (moskaleviluak@icloud.com)
 * @brief debug header
 * @version 1.0
 * @date 2024-01-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DEBUG_H_
#define DEBUG_H_

#include <check.h>

#include "./../../modules/smartcalc.h"

void free_credit(int row, payments *pay, early_pay *redemption);
void free_deposit(int row, investment *pay, operations *oper);
void input_credit(credit_init *data, long double debt, long double months,
                  int type, long double rate, int day, int month, int year);
void init_redemption(early_pay *redemption);
void input_redemption(early_pay *redemption, int day, int month, int year,
                      long double sum, int type);
void init_deposit(deposit_init *deposit, long double amount, int term_type,
                  int term, int day, int month, int year, long double rate,
                  int capital_time, int capital);
void init_operations(operations *oper);
void input_operation(operations *oper, int day, int month, int year,
                     long double sum, int type, long double min_balance);

#endif  // DEBUG_H_