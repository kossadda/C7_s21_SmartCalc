#include "../main.h"
#include <stdio.h>

int main() {
    // printf("%lf\n", calculation(str));
    // validation(str);
    // printf("%s\n", str);   
    char str[256] = "sqrt(x*x*xx*x*x)x";
    // printf("%s\n", str);
    // validation_x(str, -13.123);
    // validation(str, -5);
    // printf("%s\n", str);
    printf("%lf\n", calculation(str, 1.51));
}
