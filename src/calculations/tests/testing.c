#include "../main.h"
#include <stdio.h>

int main() {
    // printf("%lf\n", calculation(str));
    // validation(str);
    // printf("%s\n", str);   
    char str[256] = "(2/45*5432e3 * (P/3.14)) + log(123e3 * 123 e-4)";
    // printf("%s\n", str);
    // validation(str);
    // printf("%s\n", str);
    printf("%lf\n", calculation(str));
}