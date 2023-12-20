#include "s21_test.h"

START_TEST(annuity_1) {
    initial data;
    payments pay;

    input_initial(&data, 1000, 4, ANNUITY, 5, 06, 07, 2021);
    calculate_credit(&data, &pay);
    long double result_total[3] = {1010.57, 1000, 10.57};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_1) {
    initial data;
    payments pay;

    input_initial(&data, 1000, 4, DIFFERENTIATED, 5, 06, 07, 2021);
    calculate_credit(&data, &pay);
    long double result_total[3] = {1010.54, 1000, 10.54};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_2) {
    initial data;
    payments pay;

    input_initial(&data, 800, 12, ANNUITY, 3, 22, 02, 2016);
    calculate_credit(&data, &pay);
    long double result_total[3] = {812.99, 800, 12.99};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_2) {
    initial data;
    payments pay;

    input_initial(&data, 800, 12, DIFFERENTIATED, 3, 22, 02, 2016);
    calculate_credit(&data, &pay);
    long double result_total[3] = {812.94, 800, 12.94};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_3) {
    initial data;
    payments pay;

    input_initial(&data, 9862.12, 7, ANNUITY, 13.77, 9, 9, 2000);
    calculate_credit(&data, &pay);
    long double result_total[3] = {10318.04, 9862.12, 455.92};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_3) {
    initial data;
    payments pay;

    input_initial(&data, 9862.12, 7, DIFFERENTIATED, 13.77, 9, 9, 2000);
    calculate_credit(&data, &pay);
    long double result_total[3] = {10312.98, 9862.12, 450.86};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_4) {
    initial data;
    payments pay;

    input_initial(&data, 26744.12, 15, ANNUITY, 16.111, 12, 3, 2005);
    calculate_credit(&data, &pay);
    long double result_total[3] = {29719.33, 26744.12, 2975.21};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_4) {
    initial data;
    payments pay;

    input_initial(&data, 26744.12, 15, DIFFERENTIATED, 16.111, 12, 3, 2005);
    calculate_credit(&data, &pay);
    long double result_total[3] = {29627.64, 26744.12, 2883.52};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_5) {
    initial data;
    payments pay;

    input_initial(&data, 38235.23, 18, ANNUITY, 9.725, 24, 04, 2014);
    calculate_credit(&data, &pay);
    long double result_total[3] = {41250.63, 38235.23, 3015.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_5) {
    initial data;
    payments pay;

    input_initial(&data, 38235.23, 18, DIFFERENTIATED, 9.725, 24, 04, 2014);
    calculate_credit(&data, &pay);
    long double result_total[3] = {41182.76, 38235.23, 2947.53};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_6) {
    initial data;
    payments pay;

    input_initial(&data, 49715.84, 21, ANNUITY, 19.875, 21, 07, 2019);
    calculate_credit(&data, &pay);
    long double result_total[3] = {59305.94, 49715.84, 9590.1};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_6) {
    initial data;
    payments pay;

    input_initial(&data, 49715.84, 21, DIFFERENTIATED, 19.875, 21, 07, 2019);
    calculate_credit(&data, &pay);
    long double result_total[3] = {58799.98, 49715.84, 9084.14};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_7) {
    initial data;
    payments pay;

    input_initial(&data, 54798.48, 25, ANNUITY, 17.121, 16, 01, 2022);
    calculate_credit(&data, &pay);
    long double result_total[3] = {65509.5, 54798.48, 10711.02};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_7) {
    initial data;
    payments pay;

    input_initial(&data, 54798.48, 25, DIFFERENTIATED, 17.121, 16, 01, 2022);
    calculate_credit(&data, &pay);
    long double result_total[3] = {64943.26, 54798.48, 10144.78};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_8) {
    initial data;
    payments pay;

    input_initial(&data, 64972.21, 26, ANNUITY, 14.875, 28, 02, 2024);
    calculate_credit(&data, &pay);
    long double result_total[3] = {76361.58, 64972.21, 11389.37};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_8) {
    initial data;
    payments pay;

    input_initial(&data, 64972.21, 26, DIFFERENTIATED, 14.875, 28, 02, 2024);
    calculate_credit(&data, &pay);
    long double result_total[3] = {75815.12, 64972.21, 10842.91};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_9) {
    initial data;
    payments pay;

    input_initial(&data, 72578.54, 28, ANNUITY, 21.254, 8, 11, 2008);
    calculate_credit(&data, &pay);
    long double result_total[3] = {92635.41, 72578.54, 20056.87};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_9) {
    initial data;
    payments pay;

    input_initial(&data, 72578.54, 28, DIFFERENTIATED, 21.254, 8, 11, 2008);
    calculate_credit(&data, &pay);
    long double result_total[3] = {91187.66, 72578.54, 18609.12};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_10) {
    initial data;
    payments pay;

    input_initial(&data, 81458.47, 21, ANNUITY, 16.789, 12, 12, 2012);
    calculate_credit(&data, &pay);
    long double result_total[3] = {94559.9, 81458.47, 13101.43};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_10) {
    initial data;
    payments pay;

    input_initial(&data, 81458.47, 21, DIFFERENTIATED, 16.789, 12, 12, 2012);
    calculate_credit(&data, &pay);
    long double result_total[3] = {93983.55, 81458.47, 12525.08};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_11) {
    initial data;
    payments pay;

    input_initial(&data, 92784.88, 29, ANNUITY, 19.987, 25, 11, 2020);
    calculate_credit(&data, &pay);
    long double result_total[3] = {117690.04, 92784.88, 24905.16};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_11) {
    initial data;
    payments pay;

    input_initial(&data, 92784.88, 29, DIFFERENTIATED, 19.987, 25, 11, 2020);
    calculate_credit(&data, &pay);
    long double result_total[3] = {115930.84, 92784.88, 23145.96};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_12) {
    initial data;
    payments pay;

    input_initial(&data, 99999.99, 30, ANNUITY, 19.999, 9, 9, 2009);
    calculate_credit(&data, &pay);
    long double result_total[3] = {127853.88, 99999.99, 27853.89};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_12) {
    initial data;
    payments pay;

    input_initial(&data, 99999.99, 30, DIFFERENTIATED, 19.999, 9, 9, 2009);
    calculate_credit(&data, &pay);
    long double result_total[3] = {125811.83, 99999.99, 25811.84};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_13) {
    initial data;
    payments pay;

    input_initial(&data, 105597.84, 32, ANNUITY, 21.847, 4, 10, 2011);
    calculate_credit(&data, &pay);
    long double result_total[3] = {140275.08, 105597.84, 34677.24};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_13) {
    initial data;
    payments pay;

    input_initial(&data, 105597.84, 32, DIFFERENTIATED, 21.847, 4, 10, 2011);
    calculate_credit(&data, &pay);
    long double result_total[3] = {137325.72, 105597.84, 31727.88};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_14) {
    initial data;
    payments pay;

    input_initial(&data, 114874.84, 34, ANNUITY, 22.221, 8, 8, 2008);
    calculate_credit(&data, &pay);
    long double result_total[3] = {155807.13, 114874.84, 40932.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_14) {
    initial data;
    payments pay;

    input_initial(&data, 114874.84, 34, DIFFERENTIATED, 22.221, 8, 8, 2008);
    calculate_credit(&data, &pay);
    long double result_total[3] = {152085.1, 114874.84, 37210.26};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_15) {
    initial data;
    payments pay;

    input_initial(&data, 120000, 12, ANNUITY, 12, 19, 12, 2023);
    calculate_credit(&data, &pay);
    long double result_total[3] = {127947.47, 120000, 7947.47};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_15) {
    initial data;
    payments pay;

    input_initial(&data, 120000, 12, DIFFERENTIATED, 12, 19, 12, 2023);
    calculate_credit(&data, &pay);
    long double result_total[3] = {127804.58, 120000, 7804.58};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_16) {
    initial data;
    payments pay;

    input_initial(&data, 122784.45, 35, ANNUITY, 24.876, 11, 12, 1989);
    calculate_credit(&data, &pay);
    long double result_total[3] = {173860.53, 122784.45, 51076.08};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_16) {
    initial data;
    payments pay;

    input_initial(&data, 122784.45, 35, DIFFERENTIATED, 24.876, 11, 12, 1989);
    calculate_credit(&data, &pay);
    long double result_total[3] = {168592.06, 122784.45, 45807.61};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_17) {
    initial data;
    payments pay;

    input_initial(&data, 137846.94, 37, ANNUITY, 27.182, 25, 2, 1998);
    calculate_credit(&data, &pay);
    long double result_total[3] = {204743.09, 137846.94, 66896.15};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_17) {
    initial data;
    payments pay;

    input_initial(&data, 137846.94, 37, DIFFERENTIATED, 27.182, 25, 2, 1998);
    calculate_credit(&data, &pay);
    long double result_total[3] = {197040, 137846.94, 59193.06};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_18) {
    initial data;
    payments pay;

    input_initial(&data, 143975.18, 38, ANNUITY, 1.845, 15, 9, 1945);
    calculate_credit(&data, &pay);
    long double result_total[3] = {148330.04, 143975.18, 4354.86};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_18) {
    initial data;
    payments pay;

    input_initial(&data, 143975.18, 38, DIFFERENTIATED, 1.845, 15, 9, 1945);
    calculate_credit(&data, &pay);
    long double result_total[3] = {148289.28, 143975.18, 4314.1};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_19) {
    initial data;
    payments pay;

    input_initial(&data, 151879.84, 40, ANNUITY, 8.971, 20, 11, 1978);
    calculate_credit(&data, &pay);
    long double result_total[3] = {176256.41, 151879.84, 24376.57};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_19) {
    initial data;
    payments pay;

    input_initial(&data, 151879.84, 40, DIFFERENTIATED, 8.971, 20, 11, 1978);
    calculate_credit(&data, &pay);
    long double result_total[3] = {175137.6, 151879.84, 23257.76};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(annuity_20) {
    initial data;
    payments pay;

    input_initial(&data, 158797.48, 42, ANNUITY, 45.847, 1, 1, 2001);
    calculate_credit(&data, &pay);
    long double result_total[3] = {320600.04, 158797.48, 161802.56};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}

START_TEST(differentiated_20) {
    initial data;
    payments pay;

    input_initial(&data, 158797.48, 42, DIFFERENTIATED, 45.847, 1, 1, 2001);
    calculate_credit(&data, &pay);
    long double result_total[3] = {289085.83, 158797.48, 130288.35};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay);
}








Suite *s21_annuity_1(void) {
    Suite *credit = suite_create("s21_credit (annuity first cases)");

    TCase *tc_test_annuity_1 = tcase_create("test_annuity");
    tcase_add_test(tc_test_annuity_1, annuity_1);
    tcase_add_test(tc_test_annuity_1, annuity_2);
    tcase_add_test(tc_test_annuity_1, annuity_3);
    tcase_add_test(tc_test_annuity_1, annuity_4);
    tcase_add_test(tc_test_annuity_1, annuity_5);
    tcase_add_test(tc_test_annuity_1, annuity_6);
    tcase_add_test(tc_test_annuity_1, annuity_7);
    tcase_add_test(tc_test_annuity_1, annuity_8);
    tcase_add_test(tc_test_annuity_1, annuity_9);
    tcase_add_test(tc_test_annuity_1, annuity_10);
    suite_add_tcase(credit, tc_test_annuity_1);

    return credit;
}

Suite *s21_differentiated_1(void) {
    Suite *credit = suite_create("s21_credit (differentiated first cases)");

    TCase *tc_test_differentiated_1 = tcase_create("test_differentiated");
    tcase_add_test(tc_test_differentiated_1, differentiated_1);
    tcase_add_test(tc_test_differentiated_1, differentiated_2);
    tcase_add_test(tc_test_differentiated_1, differentiated_3);
    tcase_add_test(tc_test_differentiated_1, differentiated_4);
    tcase_add_test(tc_test_differentiated_1, differentiated_5);
    tcase_add_test(tc_test_differentiated_1, differentiated_6);
    tcase_add_test(tc_test_differentiated_1, differentiated_7);
    tcase_add_test(tc_test_differentiated_1, differentiated_8);
    tcase_add_test(tc_test_differentiated_1, differentiated_9);
    tcase_add_test(tc_test_differentiated_1, differentiated_10);
    suite_add_tcase(credit, tc_test_differentiated_1);

    return credit;
}

Suite *s21_annuity_2(void) {
    Suite *credit = suite_create("s21_credit (annuity second cases)");

    TCase *tc_test_annuity_2 = tcase_create("test_annuity");
    tcase_add_test(tc_test_annuity_2, annuity_11);
    tcase_add_test(tc_test_annuity_2, annuity_12);
    tcase_add_test(tc_test_annuity_2, annuity_13);
    tcase_add_test(tc_test_annuity_2, annuity_14);
    tcase_add_test(tc_test_annuity_2, annuity_15);
    tcase_add_test(tc_test_annuity_2, annuity_16);
    tcase_add_test(tc_test_annuity_2, annuity_17);
    tcase_add_test(tc_test_annuity_2, annuity_18);
    tcase_add_test(tc_test_annuity_2, annuity_19);
    tcase_add_test(tc_test_annuity_2, annuity_20);
    suite_add_tcase(credit, tc_test_annuity_2);

    return credit;
}

Suite *s21_differentiated_2(void) {
    Suite *credit = suite_create("s21_credit (differentiated second cases)");

    TCase *tc_test_differentiated_2 = tcase_create("test_differentiated");
    tcase_add_test(tc_test_differentiated_2, differentiated_11);
    tcase_add_test(tc_test_differentiated_2, differentiated_12);
    tcase_add_test(tc_test_differentiated_2, differentiated_13);
    tcase_add_test(tc_test_differentiated_2, differentiated_14);
    tcase_add_test(tc_test_differentiated_2, differentiated_15);
    tcase_add_test(tc_test_differentiated_2, differentiated_16);
    tcase_add_test(tc_test_differentiated_2, differentiated_17);
    tcase_add_test(tc_test_differentiated_2, differentiated_18);
    tcase_add_test(tc_test_differentiated_2, differentiated_19);
    tcase_add_test(tc_test_differentiated_2, differentiated_20);
    suite_add_tcase(credit, tc_test_differentiated_2);

    return credit;
}