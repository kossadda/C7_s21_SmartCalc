#include "../main.h"
#include <stdio.h>

int main() {
    char str[] = "sin(21/3.23)/23*(-231.23)/sqrt(log(13232))";
    // printf("1*(((u65324*(2654.5645-6541))/(u3654234-(u2234/4345)))+(u5747-(c(u3534/561.5345))))*(u5432-((u6541/4230.4325)-(u4232*1654.655)))\n");
    printf("%lf\n", calculation(str));
    validation(str);
    printf("%s\n", str);
}