#include "s21_test.h"

int main(void) {
    int failed_count = 0;

    Suite *(*smartcalc[])(void) = {
        s21_arifmetic_1        ,
        s21_arifmetic_2        ,
        s21_arifmetic_3        ,
        s21_arifmetic_4        ,
        s21_trigonometric_1    ,
        s21_trigonometric_2    ,
        s21_trigonometric_3    ,
        s21_other_1            ,
        s21_other_2            ,
        s21_other_3            ,
        s21_other_4            ,
        s21_other_5            ,
        s21_wrong_expressions_1,
        s21_wrong_expressions_2,
    };

    Suite *(*credit[])(void) = {
        s21_pointer_test                 ,
        s21_annuity_1                    ,
        s21_annuity_2                    ,
        s21_annuity_3                    ,
        s21_annuity_4                    ,
        s21_annuity_5                    ,
        s21_differentiated_1             ,
        s21_differentiated_2             ,
        s21_differentiated_3             ,
        s21_differentiated_4             ,
        s21_differentiated_5             ,
        s21_diff_redemption_term         ,
        s21_diff_redemption_pay          ,
        s21_annuity_redepmtion_term      ,
        s21_annuity_redepmtion_pay       ,
        s21_diff_redepmtion_combinated   ,
        s21_annuity_redepmtion_combinated,
    };

    Suite *(*deposit[])(void) = {
        s21_deposit_by_day     ,
        s21_deposit_by_week    ,
        s21_deposit_by_month   ,
        s21_deposit_by_quarter ,
        s21_deposit_by_halfyear,
        s21_deposit_by_year    ,
    };

    printf("\n\n=========================================================================\n");
    printf("=================== WELCOME! LET'S CHECK ALL TESTS! =====================\n");
    printf("=========================================================================\n");


    printf("\n\n=========================================================================\n");
    printf("============================ SMARTCALC TESTS ============================\n");
    printf("=========================================================================\n\n\n");
    for(size_t i = 0; i < sizeof(smartcalc)/sizeof(smartcalc[0]); i++) {
        printf("*************************************************************************\n");
        failed_count = test_suite(smartcalc[i]());
        if (failed_count) {
            i = sizeof(smartcalc)/sizeof(smartcalc[0]);
        }
    }
    printf("*************************************************************************\n");

    printf("\n\n=========================================================================\n");
    printf("============================= CREDIT TESTS ==============================\n");
    printf("=========================================================================\n\n\n");
    for(size_t i = 0; i < sizeof(credit)/sizeof(credit[0]); i++) {
        printf("*************************************************************************\n");
        failed_count = test_suite(credit[i]());
        if (failed_count) {
            i = sizeof(credit)/sizeof(credit[0]);
        }
    }
    printf("*************************************************************************\n");

    printf("\n\n=========================================================================\n");
    printf("============================ DEPOSIT TESTS ==============================\n");
    printf("=========================================================================\n\n\n");
    for(size_t i = 0; i < sizeof(deposit)/sizeof(deposit[0]); i++) {
        printf("*************************************************************************\n");
        failed_count = test_suite(deposit[i]());
        if (failed_count) {
            i = sizeof(deposit)/sizeof(deposit[0]);
        }
    }
    printf("*************************************************************************\n\n");

    return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

