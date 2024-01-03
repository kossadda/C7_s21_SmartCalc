#include "s21_calculator.h"

/**
 * @brief Main function of result calculation.
 * 
 * @param[in] str pointer to char coming from C++.
 * @param x value of variable x.
 * 
 * @return Result of the calculation.
 * @retval True result of calculation - if all code segments completed without errors.
 * @retval __DBL_MAX__ - if at least one code segment ends with an error (this number cannot be obtained during calculations).
*/
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
