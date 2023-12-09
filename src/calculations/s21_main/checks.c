#include "../main.h"

int check(const char first_symbol, const char *search) {
    int check = 0;
    for (size_t i = 0; i < strlen(search); i++) {
        if(first_symbol == search[i]) {
            check = 1;
        }
    }
    return check;
}

void bracket_close(double *nums, char *oper, int *n_count, int *o_count) {
    if(check(oper[*o_count], "(sctSCTQLl")) {
        trigonometry(&(nums[*n_count-1]), oper[*o_count]);
        oper[(*o_count)--] = ZERO;
    } else {
        nums[*n_count-2] = math_nums(nums[*n_count-2], nums[*n_count-1], oper[*o_count]);
        nums[*n_count-1] = 0;
        oper[(*o_count)--] = ZERO;
        (*n_count)--;
    }
}

void math_in_condition(double *nums, char *oper, int *n_count, int *o_count) {
    nums[(*n_count)--] = 0;
    oper[(*o_count)--] = ZERO;
    nums[*n_count-1] = math_nums(nums[*n_count-1], nums[*n_count], oper[*o_count]);
}
