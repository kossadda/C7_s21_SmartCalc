#include "../main.h"

static void add_symbols(char **true_str, int *count, char symbol);
static void add_number(char **true_str, int *count, double x);
static void check_str(char **true_str, char **str);
static void save_str(char **str, char **true_str, int count);
static void check_begin_symbol(char **str, int *negative_begin);
static void change_unars(char **true_str);

void validation(char **str) {
    int negative_begin = 0;
    int count = 0;
    char *true_str = (char *)malloc(1 * sizeof(char));
    check_str(&true_str, str);
    check_begin_symbol(str, &negative_begin);
    for(size_t i = 0; i < strlen(*str); i++) {
        if(check((*str)[i], "sctasl") && check((*str)[i-1], "+- /*(")) {
            check_trigonometric(&true_str, &count, *str, &i);
        } else if(check((*str)[i], NUMBERS ")") && check((*str)[i+1], "(")) {
            add_symbols(&true_str, &count, (*str)[i]);
            add_symbols(&true_str, &count, MUL);
        } else if ((*str)[i] == PI) {
            if(check((*str)[i-1], NUMBERS)) {
                add_symbols(&true_str, &count, MUL);
            }
            add_number(&true_str, &count, PI_NUM);
        } else if(!check((*str)[i], "o d")) {
            add_symbols(&true_str, &count, (*str)[i]);
        }
        if((*str)[i] == OPEN_BRCK && check((*str)[i+1], "+-")) {
            if((*str)[i+1] == '-') {
                add_symbols(&true_str, &count, UNAR);
            }
            i++;
        }
    }
    if(negative_begin) {
        add_symbols(&true_str, &count, CLOSE_BRCK);
    }
    add_symbols(&true_str, &count, ZERO);
    change_unars(&true_str);
    save_str(str, &true_str, count);
}

void validation_x(char **str, double x) {
    int count = 0;
    char *true_str = (char *)malloc(1 * sizeof(char));
    check_str(&true_str, str);
    for (size_t i = 0; i < strlen(*str); i++) {
        if ((*str)[i] == VAR) {
            if (i && check((*str)[i-1], NUMBERS ")ePx")) {
                add_symbols(&true_str, &count, MUL);
            }
            add_number(&true_str, &count, x);
            if (check((*str)[i+1], NUMBERS "(eP")) {
                add_symbols(&true_str, &count, MUL);
            }
        } else {
            add_symbols(&true_str, &count, (*str)[i]);
        }
    }
    add_symbols(&true_str, &count, ZERO);
    save_str(str, &true_str, count);
}

static void check_begin_symbol(char **str, int *negative_begin) {
    if (check(**str, "-(sctasl")) {
        int orig_length = strlen(*str) + 1 + ((**str == MINUS) ? 3 : 2);
        char addition[orig_length];
        if(**str == MINUS) {
            sprintf(addition, "%s", "1*(");
            *negative_begin = 1;
        } else {
            sprintf(addition, "%s", "1*");
        }
        strcat(addition, *str);
        *str = (char *)realloc(*str, orig_length);
        strcpy(*str, addition);
    }
}

void check_trigonometric(char **true_str, int *count, char *str, size_t *i) {
    char temp[5] = {0};
    int temp_count = 0;
    for(int j = 0; str[*i] != OPEN_BRCK; j++) {
        temp[temp_count++] = str[(*i)++];
        if(j > 4) {
            break;
        }
    }
    if(!strcmp(temp, "sin")) {
        add_symbols(true_str, count, SIN);
    } else if(!strcmp(temp, "cos")) {
        add_symbols(true_str, count, COS);
    } else if(!strcmp(temp, "tan")) {
        add_symbols(true_str, count, TAN);
    } else if(!strcmp(temp, "asin")) {
        add_symbols(true_str, count, ASIN);
    } else if(!strcmp(temp, "acos")) {
        add_symbols(true_str, count, ACOS);
    } else if(!strcmp(temp, "atan")) {
        add_symbols(true_str, count, ATAN);
    } else if(!strcmp(temp, "sqrt")) {
        add_symbols(true_str, count, SQRT);
    } else if(!strcmp(temp, "ln")) {
        add_symbols(true_str, count, LN);
    } else if(!strcmp(temp, "log")) {
        add_symbols(true_str, count, LOG);
    }
    if(str[*i] == OPEN_BRCK) {
        (*i)--;
    }
}

static void change_unars(char **true_str) {
    for(size_t i = 0; i < strlen(*true_str); i++) {
        if((*true_str)[i] == MINUS && (*true_str)[i-1] != E) {
            (*true_str)[i] = SUB;
        } else if((*true_str)[i] == UNAR) {
            (*true_str)[i] = MINUS;
        }
    }
}

static void save_str(char **str, char **true_str, int count) {
    *str = (char *)realloc(*str, count);
    if (!(*str)) {
        if(true_str) {
            free(*true_str);
        }
        fprintf(stderr, "Ошибка при выделении памяти\n");
        exit(1);
    }
    strncpy(*str, *true_str, strlen(*true_str) + 1);
    free(*true_str);
}

static void check_str(char **true_str, char **str) {
    if(!true_str || !str) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        if(!true_str) {
            free(*true_str);
        }
        exit(1);
    }
}

static void add_symbols(char **true_str, int *count, char symbol) {
    *true_str = (char *)realloc(*true_str, *count + 1);
    if (!true_str) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        exit(1);
    } else {
        (*true_str)[(*count)++] = symbol;
    }
}

static void add_number(char **true_str, int *count, double x) {
    char number[50] = {0};
    int num_count = 0;
    int precision = 6;
    if(x == PI_NUM) {
        precision = 16;
    }
    if (x < 0) {
        num_count = sprintf(number, "(%.*lf)", precision, x);
    } else {
        num_count = sprintf(number, "%.*lf", precision, x);
    }
    add_symbols(true_str, count, ZERO);
    *true_str = (char *)realloc(*true_str, *count + num_count);
    if (!true_str) {
        fprintf(stderr, "Ошибка при выделении памяти\n");
        exit(1);
    } else {
        strcat(*true_str, number);
        *count += num_count - 1;
    }
}