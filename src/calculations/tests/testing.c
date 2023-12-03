#include "../main.h"
#include <stdio.h>

int main() {
    char *example = "56*(3+754m33.51)m2.5421m2+2";
    // char *example = "7m2*3";
    // char *example = "(1-6)m2";
    printf("                                %lf\n", calculation(example));
}