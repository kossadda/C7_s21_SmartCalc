#include "../main.h"
#include <stdio.h>

int main() {
    initial data;
    payments pay;
    data.debt = 120000;
    data.months = 12;
    data.payment_type = ANNUITY;
    data.rate = 12;
    data.date.day = 19;
    data.date.month = 12;
    data.date.year = 2023;

    calculate_credit(&data, &pay);
}
