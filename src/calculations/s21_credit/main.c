#include <stdio.h>
#include <math.h>

void calculate_credit(long double amount, int months, int *days_of_months, long double rate, long double (*results)[4]) {

    int all_days = 0;

    long double balance_of_debt = amount;
    long double payment_principal = amount/months;
    long double payment_interest = 0;
    long double monthly_payment = 0;
    long double full_payment_interest = 0;

    for(size_t i = 0; i < 12; i++) {
        all_days += days_of_months[i];
    }
    for(int i = 0; i < months; i++) {
        payment_interest = (balance_of_debt * rate / 100) / all_days * days_of_months[i % 12];
        full_payment_interest += payment_interest;
        monthly_payment = payment_principal + payment_interest;
        balance_of_debt -= payment_principal;
        results[i][0] = monthly_payment;
        results[i][1] = payment_principal;
        results[i][2] = payment_interest;
        results[i][3] = balance_of_debt;
    }
}
