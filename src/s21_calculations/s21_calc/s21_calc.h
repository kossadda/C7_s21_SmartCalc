#ifndef S21_C_CALC_H_
#define S21_C_CALC_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PI_NUMBER 3.1415926535897932
#define EXP_NUMBER 2.7182818284590452

#define INCLUDE_CHARS "()^+-*/ modsinctaqrlgePx.0123456789"
#define ALL_OPERATIONS "()^+<*/msctSCTQLlu"
#define TRIGONOMETRIC_CHARS "sctSCTQLl"
#define PREV_TRIGONTRC_CHARS "+-/*()d"
#define BEGIN_TRIGONTRC_CHARS "sctal"
#define WRONG_BEGINNING "odinqrg"
#define RIGHT_ASSOCIATIVE "^"
#define BEGIN_ADDITION "1*("
#define NUMBERS "1234567890"
#define VARIABLE "x"
#define OP_BRCK "("
#define CL_BRCK ")"
#define MINUS "-"
#define EXP "^"
#define ADD "+"
#define MIN "<"
#define DIV "/"
#define MUL "*"
#define MOD "m"
#define PI "P"
#define E "e"

typedef struct {
    double stack[100];
    int count;
} num_stack;

typedef struct {
    char stack[50];
    int count;
} op_stack;

enum substitution {
    CHAR_SIN      =   's',    CHAR_COS    =   'c',    CHAR_TAN     =   't', 
    CHAR_ASIN     =   'S',    CHAR_ACOS   =   'C',    CHAR_ATAN    =   'T', 
    CHAR_SQRT     =   'Q',    CHAR_LOG    =   'L',    CHAR_LN      =   'l', 
    CHAR_ZERO     =   '\0',   CHAR_PI     =   'P',    CHAR_EXP     =   '^',
    CHAR_CL_BRCK  =   ')',    CHAR_ADD    =   '+',    CHAR_SUB     =   '<', 
    CHAR_OP_BRCK  =   '(',    CHAR_MUL    =   '*',    CHAR_DIV     =   '/',   
    CHAR_MOD      =   'm',    CHAR_UNAR   =   'u',    CHAR_MINUS   =   '-',
    CHAR_VAR      =   'x',    CHAR_E      =   'e',    CHAR_SPACE   =   ' ',
};

enum calc_functions_status {
//  brackets closing mode
    PARS_EXPRESSION  = 0, CLOSE_EXPRESSION = 1,
//  types of priorities
    LOW_PRIORITY   = 0, EQUAL_PRIORITY = 1, HIGH_PRIORITY  = 2,
//  type of elements added when adding characters to a string
    STRING     = 0, NUMBER     = 1, ONE_CHAR   = 2, TWO_CHAR   = 3,
//  decisions
    NO  = 0, YES = 1,
};

// main funtions

double calculation(char *str, double x);
int str_without_spaces(char *str);
void input_varibles(char *str, double x);
int func_substitution(char *str);
double notation(char *str);

// math_operations

void bracket_close(num_stack *num, op_stack *ops, int mode);
double math_nums(double first, double second, const char operation);
void math_trigonometry(double *number, const char operation);
void math_while_parsing(num_stack *num, op_stack *ops, const char current_operation, int decision);

// secondary functions

void clean_top_stack(num_stack *num, int num_decision, op_stack *ops, int ops_decision);
int check(const char first_symbol, const char *search);

// comparisons

int prior_comparison(const char first, const char second);
int determine_priority(const char operation);

// C++ secondary functions

int number_position(char *str, int len);
int minus_position(char *str, int len);
void make_unar(char *str, char *ptr, int len, int pos_number);
void clean_unar(char *str, char *ptr, int len, int pos_minus);
char *unar_operation(char *str);

#endif