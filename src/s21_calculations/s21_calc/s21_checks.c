#include "s21_calc.h"

/// @brief Function for checking an incoming character to match string characters
/// @param first_symbol Comparing symbol
/// @param search String characters to compare with
/// @return If there is a match - 1, otherwise - 0
int check(const char first_symbol, const char *search) {
    int check = NO;

    for (size_t i = 0; i < strlen(search); i++) {
        if(first_symbol == search[i]) {
            check = YES;
            i = strlen(search);
        }
    }

    return check;
}

/// @brief When parsing a string, if it encounters ')', it performs all operations on the top of the stack until it encounters '('
/// @param num Numeric stack
/// @param ops Operation stack
/// @param mode The function has two modes. Closing parentheses during parsing - PARS_EXPRESSION. Closing brackets after parsing - CLOSE_EXPRESSION.
void bracket_close(num_stack *num, op_stack *ops, int mode) {
    while ((mode == PARS_EXPRESSION && ops->stack[ops->count] != CHAR_OP_BRCK) ||
            (mode == CLOSE_EXPRESSION && ops->count != -1)) {

        if(check(ops->stack[ops->count], TRIGONOMETRIC_CHARS OP_BRCK)) {
            math_trigonometry(&num->stack[num->count - 1], ops->stack[ops->count]);
            clean_top_stack(num, NO, ops, YES);
        } else {
            num->stack[num->count - 2] = math_nums(num->stack[num->count - 2], num->stack[num->count - 1], ops->stack[ops->count]);
            clean_top_stack(num, YES, ops, YES);
        }

        if(mode == CLOSE_EXPRESSION) {
            if(ops->count != -1 && ops->stack[ops->count] == CHAR_OP_BRCK) {
                clean_top_stack(num, NO, ops, YES);
            }
        }
    }
}

/// @brief The function is designed to use mathematical operations if the priority of the current operation coincides/predominates over the operation at the top of the stack
/// @param num Numeric stack
/// @param ops Operation stack
/// @param current_operation Current operation
/// @param decision The function has two modes for the decision variable. If operations have the same priority - EQUAL_PRIORITY. If the current operation has a higher priority - HIGH_PRIORITY.
void math_while_parsing(num_stack *num, op_stack *ops, const char current_operation, int decision) {
    while(ops->count && prior_comparison(current_operation, ops->stack[ops->count-1]) == decision) {
        clean_top_stack(num, YES, ops, YES);
        num->stack[num->count - 1] = math_nums(num->stack[num->count - 1], num->stack[num->count], ops->stack[ops->count]);
    }
}
