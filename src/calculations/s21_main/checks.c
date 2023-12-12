#include "../main.h"

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

void math_while_parsing(num_stack *num, op_stack *ops, const char current_operation, int decision) {
    while(ops->count && prior_comparison(current_operation, ops->stack[ops->count-1]) == decision) {

        clean_top_stack(num, YES, ops, YES);
        num->stack[num->count - 1] = math_nums(num->stack[num->count - 1], num->stack[num->count], ops->stack[ops->count]);
    }
}
