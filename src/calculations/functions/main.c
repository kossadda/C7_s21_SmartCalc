#include "../main.h"

double calculation(char *str) {
    double result = 0;
    if(strlen(str) >= 255) {
        printf("Expression too long");
        return 0;
    } else {
        char result_str[256] = {0};
        strcpy(result_str, str);
        validation(result_str);
        result = notation(result_str);
    }
    return result;
}
