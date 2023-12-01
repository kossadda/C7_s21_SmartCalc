#include "C_funcs.h"

#define SIN 115
#define COS 99
#define TAN 116
#define ASIN 83
#define ACOS 67
#define ATAN 84
#define SQRT 81
#define LOG 76
#define LN 101
#define OPEN_BRCK 40
#define CLOSE_BRCK 41
#define ADD 43
#define SUB 45
#define MUL 42
#define DIV 47

int main() {
    char *example = "(((1.123*213.5555-((217.12354))*1/2)/4/6*(5632.57-123.344)/(23.12346)/(4.213*(((653.13*(14.123*121.2345+2/(23.123+9*0.213))))/((237.12*21.8888))/(1.888+92.14)))))";
    // char *example = "s(5+(t(1.123*2))/c(1+2+213.52)/12.323)";
    printf("%lf\n", polish(example));
}

double polish(char *str) {
    char attachment[256] = "1*";
    if (*str == '(' || *str == 's' || *str == 'c' || *str == 't' || *str == 'S' || *str == 'C' || *str == 'T') {
        strcat(attachment, str);
    }
    double result = notation((*str == '(' || *str == 's' || *str == 'c' || *str == 't' || *str == 'S' || *str == 'C' || *str == 'T') ? attachment : str);
    return result;
}

double notation(char *str) {
    char token[256];
    strcpy(token, str);
    char *temp = NULL;
    char moves[] = "()^+-*/sctSCT";
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
                if(oper[o_count] == SIN || oper[o_count] == COS || oper[o_count] == TAN || oper[o_count] == ASIN || oper[o_count] == ACOS || oper[o_count] == ATAN) {
                    trigonometry(&(nums[n_count - 1]), oper[o_count--]);
                }
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
    int decision = 0;
    int priority_1 = determine_priority(first);
    int priority_2 = determine_priority(second);
    if(priority_1 < priority_2) {
        decision = 1;
    } else if(priority_1 == priority_2) {
        decision = 2;
    }
    if(first == 40 || first == 41 || second == 40 || second == 41) {
        decision = 0;
    }
    return decision;
}

int determine_priority(char operation) {
    int priority = 0;
    if(operation == 43 || operation == 45) {
        priority = 1;
    } else if (operation == 42 || operation == 47) {
        priority = 2;
    } else if (operation == SIN || operation == COS || operation == TAN || operation == ASIN || operation == ACOS || operation == ATAN) {
        priority = 3;
    } else if (operation == 40 || operation == 41) {
        priority = 4;
    }
    return priority;
}

bool oper_find(char *str, int i) {
    bool oper_trig = false;
    char operations[] = "()^+-*/sctSCT";
    for(size_t j = 0; j < strlen(operations); j++) {
        if(str[i] == operations[j]) {
            oper_trig = true;
        }
    }
    return oper_trig;
}

double math_nums(double first, double second, char operation) {
    if(operation == ADD) {
        first += second;
    } else if(operation == SUB) {
        first -= second;
    } else if(operation == DIV) {
        first /= second;
    } else if(operation == MUL) {
        first *= second;
    }
    return first;
}

void trigonometry(double *number, char operation) {
    if(operation == SIN) {
        *number = sin(*number);
    } else if(operation == COS) {
        *number = cos(*number);
    } else if(operation == TAN) {
        *number = tan(*number);
    } else if(operation == ASIN) {
        *number = asin(*number);
    } else if(operation == ACOS) {
        *number = acos(*number);
    } else if(operation == ATAN) {
        *number = atan(*number);
    }
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
