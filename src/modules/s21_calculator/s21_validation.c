/**
 * @file s21_validation.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains a block of functions for checking a string for
 * valid characters
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdarg.h>

#include "./../include/s21_calculator.h"

static int check_trigonometric(char *true_str, int *count, const char *str,
                               size_t *i);
static void add_symbol(char *str, int *count, int mode, ...);

/*!
 * @brief A function for excluding spaces from a string, as well as validating
 * the string for only valid characters.
 *
 * @param[out] str string to process.
 *
 * @return int - error code.
 * @retval NO = 0 - the string contains valid characters.
 * @retval YES = 1 - there are invalid characters.
 */
int str_without_spaces(char *str) {
  int wrong_expression = NO;
  int str_len = strlen(str);
  char temp_str[str_len + 1];
  int count = 0;

  if (!str_len) {
    wrong_expression = YES;
  } else {
    for (int i = 0; i < str_len; i++) {
      if (check(str[i], INCLUDE_CHARS)) {
        if (str[i] != CHAR_SPACE) {
          temp_str[count++] = str[i];
        }
      } else {
        wrong_expression = YES;
        i = strlen(str);
      }
    }
  }

  if (wrong_expression == NO) {
    temp_str[count] = CHAR_ZERO;
    strcpy(str, temp_str);
  }

  return wrong_expression;
}

/*!
 * @brief Function for replacing variables x, constants (e, Pi) with their
 * corresponding values and additional processing.
 *
 * @param[out] str string to process.
 * @param[in] var value of variable x.
 */
void input_varibles(char *str, double var) {
  char true_str[1500] = {0};
  int count = 0;

  add_symbol(true_str, &count, STRING, BEGIN_ADDITION OP_BRCK);
  if (*str == CHAR_E) {
    add_symbol(true_str, &count, NUMBER, EXP_NUMBER);
  }

  for (size_t i = 0; i < strlen(str); i++) {
    if (check(str[i], VARIABLE PI)) {
      if (i && check(str[i - 1], NUMBERS CL_BRCK E PI VARIABLE)) {
        add_symbol(true_str, &count, ONE_CHAR, CHAR_MUL);
      }

      if (str[i] == CHAR_VAR) {
        add_symbol(true_str, &count, NUMBER, var);
      } else if (str[i] == CHAR_PI) {
        add_symbol(true_str, &count, NUMBER, PI_NUMBER);
      }

      if (check(str[i + 1], NUMBERS OP_BRCK E PI)) {
        add_symbol(true_str, &count, ONE_CHAR, CHAR_MUL);
      }
    } else if (str[i] == CHAR_E && i &&
               !(check(str[i - 1], NUMBERS) &&
                 check(str[i + 1], NUMBERS MINUS))) {
      if (check(str[i - 1], NUMBERS CL_BRCK E)) {
        add_symbol(true_str, &count, ONE_CHAR, CHAR_MUL);
      }

      add_symbol(true_str, &count, NUMBER, EXP_NUMBER);

      if (check(str[i + 1], NUMBERS OP_BRCK)) {
        add_symbol(true_str, &count, ONE_CHAR, CHAR_MUL);
      }
    } else {
      add_symbol(true_str, &count, ONE_CHAR, str[i]);
    }
  }

  add_symbol(true_str, &count, ONE_CHAR, CHAR_CL_BRCK);
  strcpy(str, true_str);
}

/*!
 * @brief A function for replacing full function names with their shortened
 * versions in char format (for ease of parsing) and additional processing.
 *
 * @param[out] str string to process.
 *
 * @return int - error code.
 * @retval NO = 0 - the string contains valid characters.
 * @retval YES = 1 - there are invalid characters.
 */
int func_substitution(char *str) {
  int wrong_expression = NO;
  char true_str[1500] = {0};
  int count = 0;

  for (size_t i = 0; i < strlen(str); i++) {
    if ((check(str[i], WRONG_BEGINNING)) &&
        check(str[i - 1], PREV_TRIGONTRC_CHARS NUMBERS)) {
      wrong_expression = YES;
      i = strlen(str);
    } else if ((check(str[i], BEGIN_TRIGONTRC_CHARS) &&
                check(str[i - 1], PREV_TRIGONTRC_CHARS)) ||
               (check(str[i], MOD))) {
      wrong_expression = check_trigonometric(true_str, &count, str, &i);
    } else if (check(str[i], NUMBERS CL_BRCK) && check(str[i + 1], OP_BRCK)) {
      add_symbol(true_str, &count, TWO_CHAR, str[i], CHAR_MUL);
    } else if (check(str[i], CL_BRCK) && check(str[i + 1], DOT)) {
      wrong_expression = YES;
    } else if (check(str[i], BINARY_OPERATIONS) &&
               check(str[i + 1], BINARY_OPERATIONS)) {
      wrong_expression = YES;
    } else if (check(str[i], CL_BRCK) &&
               check(str[i + 1], NUMBERS BEGIN_TRIGONTRC_CHARS)) {
      add_symbol(true_str, &count, TWO_CHAR, str[i], CHAR_MUL);
    } else {
      add_symbol(true_str, &count, ONE_CHAR, str[i]);
    }

    if (str[i] == CHAR_OP_BRCK && check(str[i + 1], ADD MINUS)) {
      if (str[i + 1] == CHAR_MINUS) {
        add_symbol(true_str, &count, ONE_CHAR, CHAR_UNAR);
      }
      if (str[i + 1] == CHAR_MINUS && str[i + 2] == CHAR_OP_BRCK) {
        add_symbol(true_str, &count, STRING, BEGIN_ADDITION);
      }
      i++;
    }

    if (wrong_expression == YES) {
      i = strlen(str);
    }
  }

  if (wrong_expression == NO) {
    for (size_t i = 0; i < strlen(true_str); i++) {
      if (true_str[i] == CHAR_MINUS && true_str[i - 1] != CHAR_E) {
        true_str[i] = CHAR_SUB;
      } else if (true_str[i] == CHAR_UNAR) {
        true_str[i] = CHAR_MINUS;
      }
    }

    strcpy(str, true_str);
  }

  return wrong_expression;
}

/*!
 * @brief A function that checks the possible full name of the function for
 * compliance with those specified in the parser.
 *
 * @param[out] true_str mathematical expression with substituted symbols.
 * @param[out] count counter for a string with replaced characters.
 * @param[out] str string with full names.
 * @param[out] i counter for a line with full names.
 *
 * @return int - error code.
 * @retval NO = 0 - the string contains valid characters.
 * @retval YES = 1 - there are invalid characters.
 */
static int check_trigonometric(char *true_str, int *count, const char *str,
                               size_t *i) {
  char temp[10] = {0};
  int temp_count = 0;
  int wrong_expression = NO;

  if (str[*i] == CHAR_MOD) {
    for (int j = 0; str[*i] != CHAR_ZERO; j++) {
      if (j > 4 ||
          check(str[*i], NUMBERS MINUS BEGIN_TRIGONTRC_CHARS OP_BRCK)) {
        break;
      }

      temp[temp_count++] = str[(*i)++];
    }
  } else {
    for (int j = 0; str[*i] != CHAR_ZERO; j++) {
      if (j > 4 || str[*i] == CHAR_OP_BRCK) {
        break;
      }

      temp[temp_count++] = str[(*i)++];
    }
  }

  if (!strcmp(temp, "sin")) {
    true_str[(*count)++] = CHAR_SIN;
  } else if (!strcmp(temp, "cos")) {
    true_str[(*count)++] = CHAR_COS;
  } else if (!strcmp(temp, "tan")) {
    true_str[(*count)++] = CHAR_TAN;
  } else if (!strcmp(temp, "asin")) {
    true_str[(*count)++] = CHAR_ASIN;
  } else if (!strcmp(temp, "acos")) {
    true_str[(*count)++] = CHAR_ACOS;
  } else if (!strcmp(temp, "atan")) {
    true_str[(*count)++] = CHAR_ATAN;
  } else if (!strcmp(temp, "sqrt")) {
    true_str[(*count)++] = CHAR_SQRT;
  } else if (!strcmp(temp, "ln")) {
    true_str[(*count)++] = CHAR_LN;
  } else if (!strcmp(temp, "log")) {
    true_str[(*count)++] = CHAR_LOG;
  } else if (!strcmp(temp, "mod")) {
    true_str[(*count)++] = CHAR_MOD;
  } else {
    wrong_expression = YES;
  }

  if (check(str[*i], OP_BRCK NUMBERS BEGIN_TRIGONTRC_CHARS OP_BRCK)) {
    (*i)--;
  }

  return wrong_expression;
}

/*!
 * @brief Function to add characters/strings/numbers to a string.
 * Function have three modes.
 * "mode" = STRING (0) - add a string to a string.
 * "mode" = NUMBER (1) - add a number to a string.
 * "mode" = CHAR (2) - add a char to the string (for 2 characters - TWO_CHAR, if
 * a larger number is needed, add the required number arithmetically).
 *
 * @param[out] str processed string.
 * @param[out] count counter for a string.
 * @param[in] mode mode for adding symbols
 * @param[in] parameters parameters corresponding to the specified mode.
 */
static void add_symbol(char *str, int *count, int mode, ...) {
  va_list args;
  va_start(args, mode);

  if (mode >= ONE_CHAR) {
    for (int i = 0; i <= mode - ONE_CHAR; i++) {
      char add_char = va_arg(args, int);
      str[(*count)++] = add_char;
    }
  } else if (mode == STRING) {
    char *add_string = va_arg(args, char *);

    for (size_t i = 0; i < strlen(add_string); i++) {
      str[(*count)++] = add_string[i];
    }
  } else if (mode == NUMBER) {
    double add_number = va_arg(args, double);
    char temp_str[strlen(str) + 51];
    strcpy(temp_str, str);
    char number_chars[50] = {0};
    int precision = REQUIRED_PRECISION;

    if (add_number == PI_NUMBER || add_number == EXP_NUMBER) {
      precision = DOUBLE_PRECISION;
    }

    sprintf(number_chars, "%.*lf", precision, add_number);

    if (add_number < 0) {
      sprintf(str, "%s(%s)", temp_str, number_chars);
      *count += 2;
    } else {
      sprintf(str, "%s%s", temp_str, number_chars);
    }

    *count += strlen(number_chars);
  }

  va_end(args);
}
