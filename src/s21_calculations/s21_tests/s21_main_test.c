#include "s21_test.h"

int main(void) {
    int failed_count = 0;
    Suite *(*smartcalc[])(void) = {
        s21_arifmetic_1          , s21_arifmetic_2         , s21_arifmetic_3      , s21_arifmetic_4 ,
        s21_trigonometric_1      , s21_trigonometric_2     , s21_trigonometric_3  ,
        s21_other_1              , s21_other_2             , s21_other_3          , s21_other_4     , s21_other_5,
        s21_wrong_expressions_1  , s21_wrong_expressions_2 ,
    };
    Suite *(*credit[])(void) = {
        s21_annuity_1         , s21_annuity_2         , s21_annuity_3         , s21_annuity_4         , s21_annuity_5         ,
        s21_differentiated_1  , s21_differentiated_2  , s21_differentiated_3  , s21_differentiated_4  , s21_differentiated_5  ,
    };

    printf("\n================== SMARTCALC TESTS ==================\n\n");
    for(size_t i = 0; i < sizeof(smartcalc)/sizeof(smartcalc[0]); i++) {
        printf("-----------------------------------------------------\n");
        failed_count = test_suite(smartcalc[i]());
        if (failed_count) {
            i = sizeof(smartcalc)/sizeof(smartcalc[0]);
        }
    }
    printf("-----------------------------------------------------\n");
    printf("\n\n=================== CREDIT TESTS ====================\n\n");
    for(size_t i = 0; i < sizeof(credit)/sizeof(credit[0]); i++) {
        printf("-----------------------------------------------------\n");
        failed_count = test_suite(credit[i]());
        if (failed_count) {
            i = sizeof(credit)/sizeof(credit[0]);
        }
    }
    printf("-----------------------------------------------------\n\n");

    return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

