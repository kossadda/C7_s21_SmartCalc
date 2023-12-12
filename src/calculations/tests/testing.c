#include "../main.h"
#include <stdio.h>

int main() {
    // printf("%lf\n", calculation(str));
    // validation(str);
    // printf("%s\n", str);   
    char str[] = "(((1.123*213.5555-((217.12354))*1/2)/4/6*(5632.57-123.344)/(23.12346)/(4.213*(((653.13*(14.123*121.2345+2/(23.123+9*0.213))))/((237.12*21.8888))/(1.888+92.14)))))";
    // printf("%s\n", str);
    // validation_x(str, -13.123);
    // validation(str, -5);
    // printf("%s\n", str);
    printf("\n\n%lf\n\n\n", calculation(str, 1.51));
}
