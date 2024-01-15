/// \file
#include "s21_calculator.h"
#include <math.h>

/*!
 * @brief Calculates two numbers received as input using the specified lexem.
 * 
 * @param[in] first first number.
 * @param[in] second second number.
 * @param[in] lexem lexem.
 * 
 * @return Result of calculation.
*/
double math_nums(double first, double second, const char lexem)
{
    if(lexem == CHAR_ADD) {
        first += second;
    } else if(lexem == CHAR_SUB) {
        first -= second;
    } else if(lexem == CHAR_DIV) {
        first /= second;
    } else if(lexem == CHAR_MUL) {
        first *= second;
    } else if (lexem == CHAR_EXP) {
        first = pow(first, second);
    } else if (lexem == CHAR_MOD) {
        first = fmod(first, second);
        if(first < 0) {
            first = second + first;
        }
    }

    return first;
}

/*!
 * @brief Calculates the received number using the specified trigonometric function.
 * 
 * @param[out] number calculating number.
 * @param[in] lexem trigonometric or logarithmic function.
*/
void math_trigonometry(double *number, const char lexem)
{
    if(lexem == CHAR_SIN) {
        *number = sin(*number);
    } else if(lexem == CHAR_COS) {
        *number = cos(*number);
    } else if(lexem == CHAR_TAN) {
        *number = tan(*number);
    } else if(lexem == CHAR_ASIN) {
        *number = asin(*number);
    } else if(lexem == CHAR_ACOS) {
        *number = acos(*number);
    } else if(lexem == CHAR_ATAN) {
        *number = atan(*number);
    } else if(lexem == CHAR_SQRT) {
        *number = sqrt(*number);
    } else if(lexem == CHAR_LOG) {
        *number = log10(*number);
    } else if(lexem == CHAR_LN) {
        *number = log(*number);
    }
}
