#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIN 115
#define COS 99
#define TAN 116
#define ASIN 83
#define ACOS 67
#define ATAN 84
#define SQRT 81
#define LOG 76
#define LN 108
#define OPEN_BRCK 40
#define CLOSE_BRCK 41
#define ADD 43
#define SUB 45
#define MUL 42
#define DIV 47
#define EXP 94
#define MOD 109
#define UNAR 117

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