#include "s21_calc.h"
#include <math.h>

/// @brief Calculates two numbers received as input using the specified operation
/// @param first First number
/// @param second Second number
/// @param operation Operation
/// @return Calculation result
double math_nums(double first, double second, const char operation)
{
    if(operation == CHAR_ADD) {
        first += second;
    } else if(operation == CHAR_SUB) {
        first -= second;
    } else if(operation == CHAR_DIV) {
        first /= second;
    } else if(operation == CHAR_MUL) {
        first *= second;
    } else if (operation == CHAR_EXP) {
        first = pow(first, second);
    } else if (operation == CHAR_MOD) {
        first = fmod(first, second);
        if(first < 0) {
            first = second + first;
        }
    }

    return first;
}

/// @brief Calculates the received number using the specified trigonometric function
/// @param number Number
/// @param operation Trigonometric function
void math_trigonometry(double *number, const char operation)
{
    if(operation == CHAR_SIN) {
        *number = sin(*number);
    } else if(operation == CHAR_COS) {
        *number = cos(*number);
    } else if(operation == CHAR_TAN) {
        *number = tan(*number);
    } else if(operation == CHAR_ASIN) {
        *number = asin(*number);
    } else if(operation == CHAR_ACOS) {
        *number = acos(*number);
    } else if(operation == CHAR_ATAN) {
        *number = atan(*number);
    } else if(operation == CHAR_SQRT) {
        *number = sqrt(*number);
    } else if(operation == CHAR_LOG) {
        *number = log10(*number);
    } else if(operation == CHAR_LN) {
        *number = log(*number);
    }
}
