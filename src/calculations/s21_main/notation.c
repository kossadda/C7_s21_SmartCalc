#include "../main.h"

void add_num_to_stack(num_stack *num, char *token);

double notation(char *str) {
    op_stack ops = {0};
    num_stack num = {0};
    ops.count = -1;
    char token[strlen(str) + 1];
    strcpy(token, str);
    add_num_to_stack(&num, token);
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], ALL_OPERATIONS)) {
            if(str[i] == CLOSE_BRCK) {
                bracket_close(&num, &ops, PARS_EXPRESSION);
            } else {
                ops.count++;
            }
            if(str[i] == CLOSE_BRCK && ops.stack[ops.count] == OPEN_BRCK) {
                clean_top_stack(&num, NO, &ops, YES);
                if(check(ops.stack[ops.count], TRIGONOMETRIC_CHARS)) {
                    trigonometry(&(num.stack[num.count - 1]), ops.stack[ops.count--]);
                }
            }
            if(num.count > 1) {
                math_while_parsing(&num, &ops, str[i], EQUAL_PRIORITY);
                math_while_parsing(&num, &ops, str[i], HIGH_PRIORITY);
            }
            if(str[i] != CLOSE_BRCK) {
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

void add_num_to_stack(num_stack *num, char *token) {
    char *temp = NULL;
    temp = strtok(token, ALL_OPERATIONS);
    if(temp) {
        num->stack[num->count++] = atof(temp);
    }
}

void clean_top_stack(num_stack *num, int num_decision, op_stack *ops, int ops_decision) {
    if(num_decision) {
        num->stack[num->count--] = 0;
    }
    if(ops_decision) {
        ops->stack[ops->count--] = ZERO;
    }
}