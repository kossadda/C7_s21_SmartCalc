#include "../../main.h"

char *unar_operation(char *str) {
    char ptr[256] = {0};
    int len = strlen(str) - 1;
    if(str[len] == ')' && check(str[len-1], NUMBERS)) {
        int num = number_position(str, len - 1);
        int pos_minus = minus_position(str, len);
        if(num == pos_minus && !check(str[num - 2], "gtnsd")) {
            clean_unar(str, ptr, len, pos_minus);
            strcpy(str, ptr);
        }
    } else if(check(str[len], NUMBERS)) {
        int pos_number = number_position(str, len);
        make_unar(str, ptr, len, pos_number);
        strcpy(str, ptr);
    }
    return str;
}

int number_position(char *str, int len) {
    int pos_number = 0;
    for(int i = len; i >= 0; i--) {
        if(!check(str[i], "1234567890.")) {
           pos_number = i;
           i = -1; 
        }
    }
    return pos_number;
}

int minus_position(char *str, int len) {
    int pos_minus = 0;
    for (int i = len; i >= 0; i--) {
        if(str[i] == '-' && str[i-1] == '(' && str[len] == ')') {
            pos_minus = i;
            i = -1;
        }
    }
    return pos_minus;
}

void make_unar(char *str, char *ptr, int len, int pos_number) {
    int count = 0;
    if(pos_number == 0) {
        pos_number = -1;
    }
    for(int i = 0; i < len + 1; i++) {
        if(i == pos_number + 1) {
            strcat(ptr, "(-");
            count += 2;
        }
        ptr[count++] = str[i];
        if(i == len) {
            ptr[count++] = ')';
        }
    }
}

void clean_unar(char *str, char *ptr, int len, int pos_minus) {
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(i != pos_minus - 1 && i != pos_minus) {
            ptr[count++] = str[i];
        }
    }
}
