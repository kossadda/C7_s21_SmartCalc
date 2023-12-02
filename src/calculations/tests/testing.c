#include "../main.h"
#include <stdio.h>

int main() {
    char *example = "(log(3654234)-log(4345)*log(2234)*65324*(log(2654.5645)-log(6541))+(5747-log(561.5345)/log(3534)))";
    printf("%lf\n", calculation(example));
}