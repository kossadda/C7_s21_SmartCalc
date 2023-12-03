#include "../main.h"

double calculation(char *str) {
    char attachment[256] = "1*";
    const char search[] = "(sctSCTQLl";
    if (check(*str, search)) {
        strcat(attachment, str);
    } else {
        strcpy(attachment, str);
    }
    double result = notation(attachment);
    return result;
}