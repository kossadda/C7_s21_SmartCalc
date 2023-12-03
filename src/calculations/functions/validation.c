#include "../main.h"

void validation(char *str) {
    char true_str[256];
    for(int i = 0, j = 0; i < 256; i++) {
        if(!check(str[i], " ")) {
            true_str[j] = str[i];
        }
    }
    printf("%s", true_str);
}