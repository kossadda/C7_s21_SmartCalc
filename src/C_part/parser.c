#include "C_funcs.h"

int main() {
    // char *example = "Q((Q(5233332.555)*Q(3876.8768))/(Q(107.578-0078.0785))-(Q((70784.78/50782.807)+Q(4321.67)))/(Q(13433.42)-((532.2253*Q(1523.5523))+5230.3255))";
    // printf("%lf\n", polish(example));
    test();
}

double polish(char *str) {
    char attachment[256] = "1*";
    const char search[] = "(sctSCTQLe";
    if (check_symobol(*str, search)) {
        strcat(attachment, str);
    } else {
        strcpy(attachment, str);
    }
    double result = notation(attachment);
    return result;
}

double notation(char *str) {
    char token[256];
    strcpy(token, str);
    char *temp = NULL;
    const char moves[] = "()^+-*/sctSCTQLe";
    int n_count = 0;
    int o_count = -1;
    double nums[20] = {0};
    char oper[20];
    temp = strtok(token, moves);
    nums[n_count++] = atof(temp);
    for(size_t i = 0; i < strlen(str); i++) {
        if(check_symobol(str[i], moves)) {
            if(str[i] != CLOSE_BRCK) {
                o_count++;
            } else {
                while(oper[o_count] != OPEN_BRCK) {
                    bracket_close(nums, oper, &n_count, &o_count);
                }
            }
            if(str[i] == CLOSE_BRCK && oper[o_count] == OPEN_BRCK) {
                oper[o_count--] = '\000';
                if(check_symobol(oper[o_count], "sctSCTQLe")) {
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
            if(str[i] != CLOSE_BRCK) {
                oper[o_count] = str[i];
            }
            if(!check_symobol(str[i+1], moves)) {
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

int check_symobol(char first_symbol, const char *search) {
    int check = 0;
    for (size_t i = 0; i < strlen(search); i++) {
        if(first_symbol == search[i]) {
            check = 1;
        }
    }
    return check;
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
    if(check_symobol(first, "()") || check_symobol(second, "()")) {
        decision = 0;
    }
    return decision;
}

int determine_priority(char operation) {
    int priority = 0;
    if(check_symobol(operation, "+-")) {
        priority = 1;
    } else if (check_symobol(operation, "*/")) {
        priority = 2;
    } else if (check_symobol(operation, "sctSCTQLe")) {
        priority = 3;
    } else if (check_symobol(operation, "()")) {
        priority = 4;
    }
    return priority;
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
    } else if(operation == SQRT) {
        *number = sqrt(*number);
    } else if(operation == LOG) {
        *number = log10(*number);
    } else if(operation == LN) {
        *number = log(*number);
    }
}

void bracket_close(double *nums, char *oper, int *n_count, int *o_count) {
    if(check_symobol(oper[*o_count], "(sctSCTQLe")) {
        trigonometry(&(nums[*n_count-1]), oper[*o_count]);
        oper[(*o_count)--] = '\000';
    } else {
        nums[*n_count-2] = math_nums(nums[*n_count-2], nums[*n_count-1], oper[*o_count]);
        nums[*n_count-1] = 0;
        oper[(*o_count)--] = '\000';
        (*n_count)--;
    }
}

void math_in_condition(double *nums, char *oper, int *n_count, int *o_count) {
    nums[(*n_count)--] = 0;
    oper[(*o_count)--] = '\000';
    nums[*n_count-1] = math_nums(nums[*n_count-1], nums[*n_count], oper[*o_count]);
}

void test() {
    int testing = 0;
    for (size_t i = 0; i < sizeof(examples)/sizeof(examples[0]); i++) {
        double one_ex = polish(examples[i]);
        double diff = one_ex - results[i];
        if((long long)(diff * 1e5) != 0) {
            testing = 1;
        }
    }
    (testing == 0) ? printf("SUCCESS\n") : printf("FAIL\n"); 
    // for (size_t i = 0; i < sizeof(examples)/sizeof(examples[0]); i++) {
    //     if(i == 39) printf("=======================+SINUS+=======================\n");
    //     if(i == 44) printf("=======================+COSINUS+=======================\n");
    //     if(i == 49) printf("=======================+TANGENS+=======================\n");
    //     if(i == 54) printf("=======================+ARCFUNCS+=======================\n");
    //     double one_ex = polish(examples[i]);
    //     printf ("%ld) %s\n", i, examples[i]);
    //     printf ("(my) %lf = %lf\n", one_ex, results[i]);
    // }
}