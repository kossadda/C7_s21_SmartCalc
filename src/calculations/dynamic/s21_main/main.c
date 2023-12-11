#include "../main.h"

double calculation(char *str, double x) {
    (void)x;
    int str_size = strlen(str) + 1;
    char *result_str = (char *)calloc(str_size, sizeof(char));
    strcpy(result_str, str);
    validation_x(&result_str, x);
    validation(&result_str);
    double result = notation(result_str);
    free(result_str);
    return result;
}
