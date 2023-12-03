#include "../main.h"

void validation(char *attachment) {
    char str[256] = "1*";
    char true_str[256] = {0};
    int count = 0;
    if (check(*attachment, "(sctasl")) {
        strcat(str, attachment);
    } else {
        strcpy(str, attachment);
    }
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], "sctasl") && check(str[i-1], "+-/*( ")) {
            check_trigonometric(true_str, &count, str, &i);
        } else if(str[i] == '(' && str[i+1] == '-') {
            i++;
            while(str[i] != ')') {
                if(str[i] == '-') {
                    true_str[count++] = UNAR;
                    i++;
                }
                true_str[count++] = str[i++];
            }
        } else if(check(str[i], "0123456789") && check(str[i+1], "(")) {
            true_str[count++] = str[i];
            true_str[count++] = MUL;
        } else if(!check(str[i], "o d")) {
            true_str[count++] = str[i];
        }
    }
    strcpy(attachment, true_str);
}

void check_trigonometric(char *true_str, int *count, char *str, size_t *i) {
    char temp[5] = {0};
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
