#include "C_funcs.h"

int main() {
    char *example = "(((1.123*213.5555-(217.12354)*1/2)/4/6*5632.57-123.344/(4.213*(((653.13*(14.123*121.2345+2/(23.123+9*0.213))))/((237.12*21.8888))/(1.888+92.14)))))";
    printf("%lf\n", polish(example));
}

double polish(char *str) {
    char attachment[256] = "1*";
    if (*str == '(') {
        strcat(attachment, str);
    }
    double result = notation((*str == '(') ? attachment : str);
    return result;
}

double notation(char *str) {
    char token[256];
    strcpy(token, str);
    char *temp = NULL;
    char moves[] = "()^+-*/";
    int n_count = 0;
    int o_count = -1;
    double nums[100] = {0};
    char oper[100];
    temp = strtok(token, moves);
    nums[n_count++] = atof(temp);
    for(size_t i = 0; i < strlen(str); i++) {
        if(oper_find(str, i)) {
            if(str[i] != ')') {
                o_count++;
            } else {
                while(oper[o_count] != '(') {
                    bracket_close(nums, oper, &n_count, &o_count);
                }
            }
            if(str[i] == ')' && oper[o_count] == '(') {
                oper[o_count--] = '\000';
            }
            if(n_count > 1) {
                if(prior_comparison(str[i], oper[o_count-1]) == 1) {
                    math_in_condition(nums, oper, &n_count, &o_count);
                }
                if(prior_comparison(str[i], oper[o_count-1]) == 2) {
                    math_in_condition(nums, oper, &n_count, &o_count);
                }
            }
            if(str[i] != ')') {
                oper[o_count] = str[i];
            }
            if(!oper_find(str, i + 1)) {
                temp = strtok(NULL, moves);
                if(temp != NULL) nums[n_count++] = atof(temp);
            }
        }
        if(i == strlen(str) - 1) {
            while(o_count != -1) {
                bracket_close(nums, oper, &n_count, &o_count);
                if(oper[o_count] == '(') {
                    oper[o_count--] = '\000';
                }
            }
        }
    }
    return nums[0];
}

int prior_comparison(char first, char second) {
    int first_priority = 0;
    int second_priority = 0;
    int priority = 0;
    if(first == '+' || first == '-') {
        first_priority = 1;
    } else if (first == '*' || first == '/') {
        first_priority = 2;
    } else if (first == '(' || first == ')') {
        first_priority = 4;
    }
    if(second == '+' || second == '-') {
        second_priority = 1;
    } else if (second == '*' || second == '/') {
        second_priority = 2;
    } else if (second == '(' || second == ')') {
        second_priority = 4;
    }
    if(first_priority < second_priority) {
        priority = 1;
    } else if(first_priority == second_priority) {
        priority = 2;
    }
    if(first == '(' || first == ')' || second == '(' || second == ')') {
        priority = 0;
    }
    return priority;
}

bool oper_find(char *str, int i) {
    bool oper_trig = false;
    char operations[] = "()^+-*/";
    for(size_t j = 0; j < strlen(operations); j++) {
        if(str[i] == operations[j]) {
            oper_trig = true;
        }
    }
    return oper_trig;
}

double math_nums(double first, double second, char operation) {
    if(operation == '+') {
        first += second;
    } else if(operation == '-') {
        first -= second;
    } else if(operation == '/') {
        first /= second;
    } else if(operation == '*') {
        first *= second;
    }
    return first;
}

void bracket_close(double *nums, char *oper, int *n_count, int *o_count) {
    nums[*n_count-2] = math_nums(nums[*n_count-2], nums[*n_count-1], oper[*o_count]);
    nums[*n_count-1] = 0;
    oper[(*o_count)--] = '\000';
    (*n_count)--;
}

void math_in_condition(double *nums, char *oper, int *n_count, int *o_count) {
    nums[(*n_count)--] = 0;
    oper[(*o_count)--] = '\000';
    nums[*n_count-1] = math_nums(nums[*n_count-1], nums[*n_count], oper[*o_count]);
}
