#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double notation(char *str);
int prior_comparison(char first, char second);
bool oper_find(char *str, int i);
double math_nums(double first, double second, char operation);
void bracket_close(double *nums, char *oper, int *n_count, int *o_count);
void math_in_condition(double *nums, char *oper, int *n_count, int *o_count);

#endif