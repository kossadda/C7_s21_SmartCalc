#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

enum {  SIN = 115, COS = 99, TAN = 116, ASIN = 83, ACOS = 67, ATAN = 84, SQRT = 81, LOG = 76, LN = 108, ZERO = 0, PI = 80,
        OPEN_BRCK = 40, CLOSE_BRCK = 41, ADD = 43, SUB = 60, MUL = 42, DIV = 47, EXP = 94, MOD = 109, UNAR = 117  };

#define TRIG_CHARS "sctSCTQLl"
#define BRACKETS "()"
#define NUMBERS "1234567890"

double calculation(char *str);
void validation(char *str);
void check_trigonometric(char *true_str, int *count, char *str, size_t *i);
double notation(char *str);
int check(char first_symbol, const char *search);
int prior_comparison(char first, char second);
int determine_priority(char operation);
double math_nums(double first, double second, char operation);
void trigonometry(double *number, char operation);
void bracket_close(double *nums, char *oper, int *n_count, int *o_count);
void math_in_condition(double *nums, char *oper, int *n_count, int *o_count);

void clean_unar(char *str, char *ptr, int len, int pos_minus);
void make_unar(char *str, char *ptr, int len, int pos_number);
int number_position(char *str, int len);
int minus_position(char *str, int len);
char *unar_operation(char *str);

#endif