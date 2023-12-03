#include "../main.h"
#include <stdio.h>

void valid_func(char *true_str, int *count, char *str, size_t *i) {
    char temp[5] = {0};
    int temp_count = 0;
    while(str[*i] != '(') {
        temp[temp_count++] = str[(*i)++];
    }
    if(!strcmp(temp, "sin")) {
        true_str[(*count)++] = SIN;
    } else if(!strcmp(temp, "cos")) {
        true_str[(*count)++] = COS;
    } else if(!strcmp(temp, "tan")) {
        true_str[(*count)++] = TAN;
    } else if(!strcmp(temp, "asin")) {
        true_str[(*count)++] = ASIN;
    } else if(!strcmp(temp, "acos")) {
        true_str[(*count)++] = ACOS;
    } else if(!strcmp(temp, "atan")) {
        true_str[(*count)++] = ATAN;
    } else if(!strcmp(temp, "sqrt")) {
        true_str[(*count)++] = SQRT;
    } else if(!strcmp(temp, "ln")) {
        true_str[(*count)++] = LN;
    } else if(!strcmp(temp, "log")) {
        true_str[(*count)++] = LOG;
    }
    if(str[*i] == '(') {
        (*i)--;
    }
}

// int main() {
//     char str[] = "4(1 + 2) - 3 * 4 / 5 ^ (-6)  mod 7 + (-3248) - cos(9532) + sin(132508-3275) - tan(-11) / acos(12) + asin(13) - atan(14) * sqrt(15) - ln(16) + log(17)+7(2*4)";
//     char true_str[129] = {0};
//     int count = 0;
//     // int unar = 0;
//     for(size_t i = 0; i < strlen(str); i++) {
//         if(check(str[i], "sctasl") && check(str[i-1], "+-/*( ")) {
//             valid_func(true_str, &count, str, &i);
//         } else if(str[i] == '(' && str[i+1] == '-') {
//             i++;
//             while(str[i] != ')') {
//                 if(str[i] == '-') {
//                     true_str[count++] = UNAR;
//                     i++;
//                 }
//                 true_str[count++] = str[i++];
//             }
//         } else if(check(str[i], "0123456789") && check(str[i+1], "(")) {
//             true_str[count++] = str[i];
//             true_str[count++] = MUL;
//         } else if(!check(str[i], " od")) {
//             true_str[count++] = str[i];
//         }
//     }
//     printf("%s\n", true_str);
// }

int main() {
    char str[] = "4*(1+2)-3*4/5^6m7+3248-c(9532)+s(132508-3275)-t(11)/C(0.12)+S(0.13)-T(0.14)*Q(16)-l(15)+L(17)+7*(2*4)";
    printf("%lf", calculation(str));
}