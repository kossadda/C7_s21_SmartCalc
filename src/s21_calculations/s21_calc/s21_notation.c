#include "s21_calc.h"

static void add_num_to_stack(num_stack *num, char *token);

/// @brief String parsing function to determine priority and then evaluate arithmetic expressions
/// @param str Processed string with arithmetic expression
/// @return Returns the result of calculations
double notation(char *str)
{
    op_stack ops;
    num_stack num;
    num.count = 0;
    ops.count = -1;

    char token[strlen(str) + 1];
    strcpy(token, str);
    add_num_to_stack(&num, token);

    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], ALL_OPERATIONS)) {
            if(str[i] == CHAR_CL_BRCK) {
                bracket_close(&num, &ops, PARS_EXPRESSION);
            } else {
                ops.count++;
            }

            if(str[i] == CHAR_CL_BRCK && ops.stack[ops.count] == CHAR_OP_BRCK) {
                clean_top_stack(&num, NO, &ops, YES);
                if(check(ops.stack[ops.count], TRIGONOMETRIC_CHARS)) {
                    math_trigonometry(&(num.stack[num.count - 1]), ops.stack[ops.count--]);
                }
            }

            if(num.count > 1) {
                math_while_parsing(&num, &ops, str[i], EQUAL_PRIORITY);
                math_while_parsing(&num, &ops, str[i], HIGH_PRIORITY);
            }

            if(str[i] != CHAR_CL_BRCK) {
                ops.stack[ops.count] = str[i];
            }

            if(!check(str[i+1], ALL_OPERATIONS)) {
                add_num_to_stack(&num, NULL);
            }
        }
    }

    bracket_close(&num, &ops, CLOSE_EXPRESSION);
    return num.stack[0];
}

/// @brief Function to add a number to a number stack
/// @param num Number
/// @param token Parse string
static void add_num_to_stack(num_stack *num, char *token)
{
    char *temp = NULL;
    temp = strtok(token, ALL_OPERATIONS);
    
    if(temp) {
        num->stack[num->count++] = atof(temp);
    }
}

/// @brief Function for clearing the top of stacks
/// @param num Numeric stack
/// @param num_decision Cleaning decision. YES - clean, NO - do not clean
/// @param ops Operation stack
/// @param ops_decision Cleaning decision. YES - clean, NO - do not clean
void clean_top_stack(num_stack *num, int num_decision, op_stack *ops, int ops_decision)
{
    if(num_decision == YES) {
        num->stack[num->count--] = 0;
    }

    if(ops_decision == YES) {
        ops->stack[ops->count--] = CHAR_ZERO;
    }
}