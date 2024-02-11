/**
 * @file comparison.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains the main functions for comparisons
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/calculator.h"

/*!
 * @brief A function designed to compare the priorities of two lexems (current
 * and at the top of the stack).
 *
 * @param[in] current current lexem.
 * @param[in] top_stack lexem on top of stack.
 *
 * @return int - status of the current lexem in relation to the lexem at the
 * top of the stack.
 * @retval LOW_PRIORITY = 0 - if the current lexem is of lower priority.
 * @retval EQUAL_PRIORITY = 1 - if the current lexem has equal priority.
 * @retval HIGH_PRIORITY = 2 - if the current lexem has higher priority.
 */
int prior_comparison(const char current, const char top_stack) {
  int decision = LOW_PRIORITY;

  int priority_1 = determine_priority(current);
  int priority_2 = determine_priority(top_stack);

  if (priority_1 < priority_2) {
    decision = EQUAL_PRIORITY;
  } else if (priority_1 == priority_2 && !check(current, RIGHT_ASSOCIATIVE)) {
    decision = HIGH_PRIORITY;
  }

  if (check(current, OP_BRCK CL_BRCK) || check(top_stack, OP_BRCK CL_BRCK)) {
    decision = LOW_PRIORITY;
  }

  return decision;
}

/*!
 * @brief The function determines the priority of the input lexem.
 *
 * @param[in] lexem lexem.
 *
 * @return int - lexem priority.
 * @retval 1 - if lexem one of "+-".
 * @retval 2 - if lexem one of "* / mod".
 * @retval 3 - if lexem is "^".
 * @retval 4 - if lexem one of "sin cos tan acos atan log ln".
 * @retval 5 - if lexem one of "( )".
 */
int determine_priority(const char lexem) {
  int priority = 0;

  if (check(lexem, ADD SUB)) {
    priority = 1;
  } else if (check(lexem, MUL DIV MOD)) {
    priority = 2;
  } else if (check(lexem, EXP)) {
    priority = 3;
  } else if (check(lexem, TRIGONOMETRIC_CHARS)) {
    priority = 4;
  } else if (check(lexem, OP_BRCK CL_BRCK)) {
    priority = 5;
  }

  return priority;
}
