/**
 * @file s21_calculator.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains the main function for calculating
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/s21_calculator.h"

/*!
 * @brief Main function of result calculation.
 *
 * @param[out] str pointer to char coming from C++.
 * @param[in] x value of variable x.
 *
 * @return double - result of the calculation.
 * @retval True result of calculation - if all code segments completed without
 * errors.
 * @retval __DBL_MAX__ - if at least one code segment ends with an error (this
 * number cannot be obtained during calculations).
 */
double calculation(char *str, double x) {
  int wrong_expression = NO;
  char result_str[1500] = {0};
  double result = 0;

  if (str) {
    strcpy(result_str, str);
    wrong_expression = str_without_spaces(result_str);
    if (!wrong_expression) {
      input_varibles(result_str, x);
      wrong_expression = func_substitution(result_str);
      if (!wrong_expression) {
        result = notation(result_str);
      }
    }
  } else {
    wrong_expression = YES;
  }

  return (wrong_expression) ? __DBL_MAX__ : result;
}
