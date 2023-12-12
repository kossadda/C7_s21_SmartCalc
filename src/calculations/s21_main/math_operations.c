#include "../main.h"
#include <math.h>

double math_nums(double first, double second, const char operation) {
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

void math_trigonometry(double *number, const char operation) {
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
