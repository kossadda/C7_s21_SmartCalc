#include "../main.h"
#include <stdio.h>

int main() {
    char *example = "Q((Q(5233332.555)*Q(3876.8768))/(Q(107.578-0078.0785))-(Q((70784.78/50782.807)+Q(4321.67)))/(Q(13433.42)-((532.2253*Q(1523.5523))+5230.3255))";
    printf("%lf\n", calculation(example));
}