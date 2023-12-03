#include "../main.h"

double math_nums(double first, double second, char operation) {
    if(operation == ADD) {
        first += second;
    } else if(operation == SUB) {
        first -= second;
    } else if(operation == DIV) {
        first /= second;
    } else if(operation == MUL) {
        first *= second;
    } else if (operation == EXP) {
        first = pow(first, second);
    } else if (operation == MOD) {
        first = fmod(first, second);
        // if(first < 0) {
        //     first = second + first;
        // }
    }

    return first;
}

void trigonometry(double *number, char operation) {
    if(operation == SIN) {
        *number = sin(*number);
    } else if(operation == COS) {
        *number = cos(*number);
    } else if(operation == TAN) {
        *number = tan(*number);
    } else if(operation == ASIN) {
        *number = asin(*number);
    } else if(operation == ACOS) {
        *number = acos(*number);
    } else if(operation == ATAN) {
        *number = atan(*number);
    } else if(operation == SQRT) {
        *number = sqrt(*number);
    } else if(operation == LOG) {
        *number = log10(*number);
    } else if(operation == LN) {
        *number = log(*number);
    }
}
