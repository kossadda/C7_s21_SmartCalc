#include "../main.h"
#include <stdio.h>

int main() {
    char str[] = "4(1 + 2) - 3 * 4 / 5 ^ 6   mod 7 + 3248 - cos(9532) + sin(132508-3275) - tan(11) / acos(0.12) + asin(0.13) - atan(0.14) * sqrt(16) - ln(15) + log(17)+7(2*4)";
    printf("%lf\n", calculation(str));
}