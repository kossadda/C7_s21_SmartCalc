#include "../main.h"

double calculation(char *str, double x) {
    char result_str[1500] = {0};
    strcpy(result_str, str);
    str_without_spaces(result_str);
    input_varibles(result_str, x);
    func_substitution(result_str);
    double result = notation(result_str);
    return result;
}
