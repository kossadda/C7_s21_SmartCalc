#include "../main.h"

static void check_trigonometric(char *true_str, int *count, const char *str, size_t *i);

void validation(char *attachment) {
    char str[300] = "1*";
    char true_str[1500] = {0};
    int count = 0;
    if (check(*attachment, "(sctasl")) {
        strcat(str, attachment);
    } else if (check(*attachment, "-")) {
        strcat(str, "(");
        strcat(str, attachment);
    } else {
        strcpy(str, attachment);
    }
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], "sctasl") && check(str[i-1], "+-/*( ")) {
            check_trigonometric(true_str, &count, str, &i);
        } else if(check(str[i], "0123456789)") && check(str[i+1], "(")) {
            true_str[count++] = str[i];
            true_str[count++] = MUL;
        } else if (str[i] == PI) {
            if(check(str[i-1], NUMBERS)) {
                true_str[count++] = MUL;
            }
            strcat(true_str, "3.14159265358979323846");
            count += 22;
        } else if(!check(str[i], "o d")) {
            true_str[count++] = str[i];
        }
        if(str[i] == '(' && check(str[i+1], "+-")) {
            if(str[i+1] == '-') {
                true_str[count++] = UNAR;
            }
            i++;
        }
    }
    for(size_t i = 0; i < strlen(true_str); i++) {
        if(true_str[i] == '-' && true_str[i-1] != 'e') {
            true_str[i] = SUB;
        } else if(true_str[i] == UNAR) {
            true_str[i] = '-';
        }
    }
    strcpy(attachment, true_str);
}

void validation_x(char *str, double x) {
    char true_str[1500] = {0};
    int count = 0;
    for(size_t i = 0; i < strlen(str); i++) {
        if(str[i] == 'x') {
            if(i && check(str[i-1], "0123456789)ePx")) {
                true_str[count++] = MUL;
            }
            char temp_str[30] = {0};
            int temp_count = 0;
            if(x < 0) {
                temp_count = sprintf(temp_str, "(%lf)", x);
            } else { 
                temp_count = sprintf(temp_str, "%lf", x);
            }
            strcat(true_str, temp_str);
            count += temp_count;
            if(check(str[i+1], "0123456789(eP")) {
                true_str[count++] = MUL;
            }
        } else {
            true_str[count++] = str[i];
        }
    }
    strcpy(str, true_str);
}

static void check_trigonometric(char *true_str, int *count, const char *str, size_t *i) {
    char temp[10] = {0};
    int temp_count = 0;
    while(str[*i] != '(') {
        temp[temp_count++] = str[(*i)++];
    }
    if(!strcmp(temp, "sin")) {
        true_str[(*count)++] = SIN;
    } else if(!strcmp(temp, "cos")) {
        true_str[(*count)++] = COS;
    } else if(!strcmp(temp, "tan")) {
        true_str[(*count)++] = TAN;
    } else if(!strcmp(temp, "asin")) {
        true_str[(*count)++] = ASIN;
    } else if(!strcmp(temp, "acos")) {
        true_str[(*count)++] = ACOS;
    } else if(!strcmp(temp, "atan")) {
        true_str[(*count)++] = ATAN;
    } else if(!strcmp(temp, "sqrt")) {
        true_str[(*count)++] = SQRT;
    } else if(!strcmp(temp, "ln")) {
        true_str[(*count)++] = LN;
    } else if(!strcmp(temp, "log")) {
        true_str[(*count)++] = LOG;
    }
    if(str[*i] == '(') {
        (*i)--;
    }
}
