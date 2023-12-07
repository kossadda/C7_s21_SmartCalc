#include "../main.h"

double calculation(char *str, double x) {
    char result_str[1500] = {0};
    strcpy(result_str, str);
    validation_x(result_str, x);
    validation(result_str);
    double result = notation(result_str);
    return result;
}
