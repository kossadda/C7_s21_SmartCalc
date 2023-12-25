#include "s21_calc.h"

/// @brief Main function of result calculation
/// @param str Pointer to char coming from C++
/// @param x Value of variable x
/// @return If successful, returns the result of the calculation, failure - the maximum number of double (this number cannot be obtained during calculations)
double calculation(char *str, double x)
{
    int wrong_expression = NO;
    char result_str[1500] = {0};
    double result = 0;

    if(str) {
        strcpy(result_str, str);
        wrong_expression = str_without_spaces(result_str);
        if(!wrong_expression) {
            input_varibles(result_str, x);
            wrong_expression = func_substitution(result_str);
            if(!wrong_expression) {
                result = notation(result_str);
            }
        }
    } else {
        wrong_expression = YES;
    }
    
    return (wrong_expression) ? __DBL_MAX__ : result;
}
