/**
 * @file s21_calculator.h
 * @author kossadda (https://github.com/kossadda)
 * @brief Header file for all engineering calculator modules.
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef S21_C_CALC_H_
#define S21_C_CALC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI_NUMBER 3.1415926535897932
#define EXP_NUMBER 2.7182818284590452

#define INCLUDE_CHARS "()^+-*/ modsinctaqrlgePx.0123456789"
#define ALL_OPERATIONS "()^+<*/msctSCTQLlu"
#define TRIGONOMETRIC_CHARS "sctSCTQLl"
#define PREV_TRIGONTRC_CHARS "1234567890+-/*()d"
#define BEGIN_TRIGONTRC_CHARS "sctal"
#define END_TIGONTRC_CHARS "gtnsd"
#define WRONG_BEGINNING "odinqrg"
#define BINARY_OPERATIONS "+-*/"
#define RIGHT_ASSOCIATIVE "^"
#define BEGIN_ADDITION "1*"
#define NUMBERS "1234567890"
#define VARIABLE "x"
#define OP_BRCK "("
#define CL_BRCK ")"
#define MINUS "-"
#define EXP "^"
#define ADD "+"
#define SUB "<"
#define DIV "/"
#define MUL "*"
#define MOD "m"
#define DOT "."
#define PI "P"
#define E "e"

///@brief List defining replacement chars for full expression names.
enum substitution {
  CHAR_SIN = 's',      ///< Substitution symbol for sin.
  CHAR_COS = 'c',      ///< Substitution symbol for cos.
  CHAR_TAN = 't',      ///< Substitution symbol for tan.
  CHAR_ASIN = 'S',     ///< Substitution symbol for asin.
  CHAR_ACOS = 'C',     ///< Substitution symbol for acos.
  CHAR_ATAN = 'T',     ///< Substitution symbol for atan.
  CHAR_SQRT = 'Q',     ///< Substitution symbol for sqrt.
  CHAR_LOG = 'L',      ///< Substitution symbol for log.
  CHAR_LN = 'l',       ///< Substitution symbol for ln.
  CHAR_EXP = '^',      ///< Substitution symbol for exponentation.
  CHAR_MOD = 'm',      ///< Substitution symbol for mod.
  CHAR_ADD = '+',      ///< Substitution symbol for add.
  CHAR_SUB = '<',      ///< Substitution symbol for sub.
  CHAR_MUL = '*',      ///< Substitution symbol for mul.
  CHAR_DIV = '/',      ///< Substitution symbol for div.
  CHAR_UNAR = 'u',     ///< Substitution symbol for unar minus.
  CHAR_MINUS = '-',    ///< Substitution symbol for minus.
  CHAR_CL_BRCK = ')',  ///< Substitution symbol for closing parenthesis.
  CHAR_OP_BRCK = '(',  ///< Substitution symbol for opening parenthesis.
  CHAR_VAR = 'x',      ///< Substitution symbol for variable x.
  CHAR_E = 'e',        ///< Substitution symbol for Euler number/scientific.
  CHAR_PI = 'P',       ///< Substitution symbol for Pi.
  CHAR_SPACE = ' ',    ///< Substitution symbol for space.
  CHAR_ZERO = '\0',    ///< Substitution symbol for null terminated sign.
};

///@brief List defining constant statuses for functions used in the engeneer
enum calc_functions_status {
  STRING = 0,    ///< String added when adding characters to a string.
  NUMBER = 1,    ///< Number added when adding characters to a string.
  ONE_CHAR = 2,  ///< One char added when adding characters to a string.
  TWO_CHAR = 3,  ///< Two chars added when adding characters to a string.

  LOW_PRIORITY = 0,    ///< Low priority of the current parsing operation.
  EQUAL_PRIORITY = 1,  ///< Equal priority of the current parsing operation.
  HIGH_PRIORITY = 2,   ///< High priority of the current parsing operation.

  PARS_EXPRESSION = 0,   ///< Function mode during string parsing.
  CLOSE_EXPRESSION = 1,  ///< Function mode after string parsing is complete.

  DOUBLE_PRECISION = 16,   ///< Approximate accuracy for double.
  REQUIRED_PRECISION = 6,  ///< Required accuracy.

  NO = 0,   ///< Decision of any status if its not set.
  YES = 1,  ///< Decision of any status if its set.
};

///@brief Struct representing stack for numbers.
typedef struct {
  double stack[150];  ///< An array containing stack numbers.
  int count;          ///< Counter that determines number of numbers on stack.
} num_stack;

///@brief Struct representing stack for lexems.
typedef struct {
  char stack[150];  ///< An array containing stack lexems (math operations).
  int count;        ///< Counter that determines number of lexems on stack.
} lex_stack;

// Main funtions

double calculation(char *str, double x);
int str_without_spaces(char *str);
void input_varibles(char *str, double x);
int func_substitution(char *str);
double notation(char *str);

// Math_operations

void bracket_close(num_stack *num, lex_stack *lex, int mode);
double math_nums(double first, double second, const char lexem);
void math_trigonometry(double *number, const char lexem);
void math_while_parsing(num_stack *num, lex_stack *lex,
                        const char current_lexem, int decision);

// Secondary functions

void clean_top_stack(num_stack *num, int num_decision, lex_stack *lex,
                     int lex_decision);
int check(const char first_symbol, const char *search);

// Comparisons

int prior_comparison(const char first, const char second);
int determine_priority(const char lexem);

// C++ secondary functions

int number_position(char *str, int len);
int minus_position(char *str, int len);
void make_unar(char *str, char *ptr, int len, int pos_number);
void clean_unar(char *str, char *ptr, int len, int pos_minus);
char *unar_operation(char *str);

#endif
