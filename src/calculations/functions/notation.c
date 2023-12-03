#include "../main.h"

double notation(char *str) {
    char token[256] = {0};
    strcpy(token, str);
    char *temp = NULL;
    const char moves[] = "()^+-*/msctSCTQLl";
    int n_count = 0;
    int o_count = -1;
    double nums[20] = {0};
    char oper[20] = {0};
    temp = strtok(token, moves);
    nums[n_count++] = atof(temp);
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], moves)) {
            if(str[i] != CLOSE_BRCK) {
                o_count++;
            } else {
                while(oper[o_count] != OPEN_BRCK) {
                    bracket_close(nums, oper, &n_count, &o_count);
                }
            }
            if(str[i] == CLOSE_BRCK && oper[o_count] == OPEN_BRCK) {
                oper[o_count--] = '\000';
                if(check(oper[o_count], "sctSCTQLl")) {
                    trigonometry(&(nums[n_count - 1]), oper[o_count--]);
                }
            }
            if(n_count > 1) {
                while(prior_comparison(str[i], oper[o_count-1]) == 1) {
                    math_in_condition(nums, oper, &n_count, &o_count);
                }
                while(prior_comparison(str[i], oper[o_count-1]) == 2) {
                    math_in_condition(nums, oper, &n_count, &o_count);
                }
            }
            if(str[i] != CLOSE_BRCK) {
                oper[o_count] = str[i];
            }
            if(!check(str[i+1], moves)) {
                temp = strtok(NULL, moves);
                if(temp != NULL) nums[n_count++] = atof(temp);
            }
        }
        if(i == strlen(str) - 1) {
            while(o_count != -1) {
                bracket_close(nums, oper, &n_count, &o_count);
                if(oper[o_count] == OPEN_BRCK) {
                    oper[o_count--] = '\000';
                }
            }
        }
    }
    return nums[0];
}