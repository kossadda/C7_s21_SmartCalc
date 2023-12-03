#include "../main.h"

double calculation(char *str) {
    double result = 0;
    if(strlen(str) < 255) {
        char result_str[256] = {0};
        strcpy(result_str, str);
        validation(result_str);
        // printf("%s\n", result_str);
        result = notation(result_str);
    }
    return result;
}
