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

/**
 * @brief List defining replacement chars for full expression names.
*/
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

/**
 * @brief List defining constant statuses for functions used in the credit calculator.
*/
enum calc_functions_status {
//  Type of elements added when adding characters to a string.
    STRING = 0, NUMBER = 1, ONE_CHAR = 2, TWO_CHAR  = 3,
//  Types of priorities.
    LOW_PRIORITY = 0, EQUAL_PRIORITY = 1, HIGH_PRIORITY = 2,
//  Brackets closing mode.
    PARS_EXPRESSION = 0, CLOSE_EXPRESSION = 1,
//  Decisions of any status.
    NO = 0, YES = 1,
};

/**
 * @brief Struct representing stack for numbers.
*/
typedef struct num_stack {
    double stack[150];              /** An array containing stack numbers.                            */
    int count;                      /** A counter that determines the number of numbers on the stack. */
} num_stack;

/**
 * @brief Struct representing stack for lexems.
*/
typedef struct lex_stack {
    char stack[150];                 /** An array containing stack lexems (math operations).          */
    int count;                      /** A counter that determines the number of lexems on the stack. */
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
void math_while_parsing(num_stack *num, lex_stack *lex, const char current_lexem, int decision);

// Secondary functions

void clean_top_stack(num_stack *num, int num_decision, lex_stack *lex, int lex_decision);
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
