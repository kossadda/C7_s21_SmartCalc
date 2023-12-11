#include "../main.h"
#include <stdio.h>

int main() { 
    char *str = malloc(163);
    sprintf(str, "%s", "(2/45*5432e3 * (P/3.14)) + log(123e3 * 123 e-4)");
    validation(&str);
    printf("%s", str);
    // printf("\n\n%lf\n\n\n", calculation(str, 0));
    free(str);
}
