#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIN 115
#define COS 99
#define TAN 116
#define ASIN 83
#define ACOS 67
#define ATAN 84
#define SQRT 81
#define LOG 76
#define LN 101
#define OPEN_BRCK 40
#define CLOSE_BRCK 41
#define ADD 43
#define SUB 45
#define MUL 42
#define DIV 47

double calculation(char *str);
double notation(char *str);
int check_symobol(char first_symbol, const char *search);
int prior_comparison(char first, char second);
int determine_priority(char operation);
double math_nums(double first, double second, char operation);
void trigonometry(double *number, char operation);
void bracket_close(double *nums, char *oper, int *n_count, int *o_count);
void math_in_condition(double *nums, char *oper, int *n_count, int *o_count);

#endif