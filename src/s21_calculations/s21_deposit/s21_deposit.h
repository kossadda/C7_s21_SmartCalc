#ifndef S21_C_DEPOSIT_H
#define S21_C_DEPOSIT_H

// #include <math.h>
// #include <stdlib.h>

// #define CHECK_NULL(ptr) (ptr == NULL)

// enum constants {
// //  days constants
//     JAN = 31, FEB = 28, MAR = 31, APR = 30, LEAP_FEB = 29,
//     MAY = 31, JUN = 30, JUL = 31, AUG = 31,
//     SEP = 30, OCT = 31, NOV = 30, DEC = 31,
// //  another constants
//     QUADRICENTENARY = 400, 
//     CENTURY         = 100,
//     LEAP_INTERVAL   =   4, 
//     YEAR            = 365,
//     LEAP_YEAR       = 366,
// };

// enum credit_functions_status {
// //  year status
//     YEAR_NOT_LEAP = 0, YEAR_IS_LEAP = 1,
// //  allocate memory
//     ALLOCATED = 0, NOT_ALLOCATED = 1,
// //  changing of debt
//     DEBT_NOT_CHANGED = 0, DEBT_CHANGED = 1,
// //  date between two dates
//     DATE_BESIDE = 0, DATE_BETWEEN = 1,
// //  type of main payments
//     ANNUITY = 0, DIFFERENTIATED = 1, NOT_CHOSEN = 2,
// //  type of early payments
//     REDUCE_TERM = 0, REDUCE_PAY = 1,
// };

// typedef struct time_data {
//     int day;
//     int month;
//     int year;
//     int leap;
//     int month_days;
// } time_data;

// typedef struct payments {
//     long double main;
//     long double percent;
//     long double monthly;
//     long double const_main;
//     long double *total;
//     long double **result;
// } payments;

// typedef struct initial {
//     int payment_type;
//     long double debt;
//     long double rate;
//     int months;
//     int current;
//     time_data date;
// } initial;

// typedef struct another_payments {
//     time_data *date;
//     long double *sum;
//     int *type;
//     int count;
//     int current;
// } another_payments;

// typedef struct deposit_initial
// {
//     long double amount;
// } deposit_initial;


#endif