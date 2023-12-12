#ifndef FUNC_TESTS_H_
#define FUNC_TESTS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALL_OPERATIONS "()^+<*/msctSCTQLlu"
#define TRIGONOMETRIC_CHARS "sctSCTQLl"
#define BRACKETS "()"
#define NUMBERS "1234567890"
#define RIGHT_ASSOCIATIVE "^"
#define PI_NUMBER 3.1415926535897932
#define EXP_NUMBER 2.7182818284590452

enum clean_decision {
    NO  = 0,
    YES = 1,
};

enum prior_decisions {
    LOW_PRIORITY   = 0,
    EQUAL_PRIORITY = 1,
    HIGH_PRIORITY  = 2,
};

enum brackets_mode {
    PARS_EXPRESSION  = 0,
    CLOSE_EXPRESSION = 1,
};

enum addition_mode {
    STRING     = 0,
    NUMBER     = 1,
    ONE_CHAR   = 2,
    TWO_CHAR   = 3,
    THREE_CHAR = 4,
};

enum substitution {
    SIN        = 's'     , COS    = 'c'     , TAN     = 't', 
    ASIN       = 'S'     , ACOS   = 'C'     , ATAN    = 'T', 
    SQRT       = 'Q'     , LOG    = 'L'     , LN      = 'l', 
    ZERO       = '\0'    , PI     = 'P'     , EXP     = '^',
    CLOSE_BRCK = ')'     , ADD    = '+'     , SUB     = '<', 
    OPEN_BRCK  = '('     , MUL    = '*'     , DIV     = '/',   
    MOD        = 'm'     , UNAR   = 'u'     , MINUS   = '-',
    VAR        = 'x'     , E      = 'e',
};

typedef struct {
    double stack[100];
    int count;
} num_stack;

typedef struct {
    char stack[50];
    int count;
} op_stack;

// main funtions
double calculation(char *str, double x);
void str_without_spaces(char *str);
void input_varibles(char *str, double x);
void func_substitution(char *str);
double notation(char *str);

// math_operations
void bracket_close(num_stack *num, op_stack *ops, int mode);
double math_nums(double first, double second, const char operation);
void trigonometry(double *number, const char operation);
void math_while_parsing(num_stack *num, op_stack *ops, const char current_operation, int decision);

// secondary functions
void clean_top_stack(num_stack *num, int num_decision, op_stack *ops, int ops_decision);
int check(const char first_symbol, const char *search);

// comparisons
int prior_comparison(const char first, const char second);
int determine_priority(const char operation);

#endif