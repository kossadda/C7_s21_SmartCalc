#include "../main.h"
#include <stdarg.h>

static void check_trigonometric(char *true_str, int *count, const char *str, size_t *i);
static void add_symbol(char *str, int *count, int mode, ...);

void str_without_spaces(char *str) {
    char temp_str[strlen(str) + 1];
    int count = 0;
    for(size_t i = 0; i < strlen(str); i++) {
        if(str[i] != ' ') {
            temp_str[count++] = str[i];
        }
    }
    temp_str[count] = ZERO;
    strcpy(str, temp_str);
}

void input_varibles(char *str, double var) {
    char true_str[1500] = {0};
    int count = 0;
    add_symbol(true_str, &count, STRING, "1*(");
    if(*str == E) {
        add_symbol(true_str, &count, NUMBER, EXP_NUMBER);
    }
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], "xP")) {
            if(i && check(str[i-1], NUMBERS ")ePx")) {
                add_symbol(true_str, &count, ONE_CHAR, MUL);
            }
            if(str[i] == VAR) {
                add_symbol(true_str, &count, NUMBER, var);
            } else if(str[i] == PI) {
                add_symbol(true_str, &count, NUMBER, PI_NUMBER);
            } 
            if(check(str[i+1], NUMBERS "(eP")) {
                add_symbol(true_str, &count, ONE_CHAR, MUL);
            }
        } else if(str[i] == E && i && !(check(str[i-1], NUMBERS) && check(str[i+1], NUMBERS "-"))) {
            add_symbol(true_str, &count, NUMBER, EXP_NUMBER);
        } else {
            add_symbol(true_str, &count, ONE_CHAR, str[i]);
        }
    }
    add_symbol(true_str, &count, ONE_CHAR, ')');
    strcpy(str, true_str);
}

void func_substitution(char *str) {
    char true_str[1500] = {0};
    int count = 0;
    for(size_t i = 0; i < strlen(str); i++) {
        if(check(str[i], "sctasl") && check(str[i-1], "+-/*( ")) {
            check_trigonometric(true_str, &count, str, &i);
        } else if(check(str[i], "0123456789)") && check(str[i+1], "(")) {
            true_str[count++] = str[i];
            true_str[count++] = MUL;
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

static void add_symbol(char *str, int *count, int mode, ...) {
    va_list args;
    va_start(args, mode);
    if(mode >= ONE_CHAR) {
        for(int i = 0; i <= mode - ONE_CHAR; i++) {
            char add_char = va_arg(args, int);
            str[(*count)++] = add_char;
        }
    } else if(mode == STRING) {
        char *add_string = va_arg(args, char *);
        for(size_t i = 0; i < strlen(add_string); i++) {
            str[(*count)++] = add_string[i];
        }
    } else if(mode == NUMBER) {
        double add_number = va_arg(args, double);
        char temp_str[strlen(str) + 51];
        strcpy(temp_str, str);
        char number_chars[50] = {0};
        int precision = 6;
        if(add_number == PI_NUMBER || add_number == EXP_NUMBER) {
            precision = 16;
        }
        sprintf(number_chars, "%.*lf", precision, add_number);
        if(add_number < 0) {
            sprintf(str, "%s(%s)", temp_str, number_chars);
            *count += 2;
        } else {
            sprintf(str, "%s%s", temp_str, number_chars);
        }
        *count += strlen(number_chars);
    }
    va_end(args);
}