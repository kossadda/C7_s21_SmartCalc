#include "../main.h"

double calculation(char *str) {
    char result_str[1500] = {0};
    strcpy(result_str, str);
    validation(result_str);
    double result = notation(result_str);
    return result;
}
