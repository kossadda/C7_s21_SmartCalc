#include "s21_test.h"

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_1) {
    initial data;
    payments pay;

    input_initial(&data, 1000, 4, ANNUITY, 5, 06, 07, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1010.57, 1000, 10.57};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_2) {
    initial data;
    payments pay;

    input_initial(&data, 800, 12, ANNUITY, 3, 22, 02, 2016);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {812.99, 800, 12.99};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_3) {
    initial data;
    payments pay;

    input_initial(&data, 9862.12, 7, ANNUITY, 13.77, 9, 9, 2000);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {10318.04, 9862.12, 455.92};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_4) {
    initial data;
    payments pay;

    input_initial(&data, 26744.12, 15, ANNUITY, 16.111, 12, 3, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {29719.33, 26744.12, 2975.21};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_5) {
    initial data;
    payments pay;

    input_initial(&data, 38235.23, 18, ANNUITY, 9.725, 24, 04, 2014);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {41250.63, 38235.23, 3015.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_6) {
    initial data;
    payments pay;

    input_initial(&data, 49715.84, 21, ANNUITY, 19.875, 21, 07, 2019);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {59305.94, 49715.84, 9590.1};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_7) {
    initial data;
    payments pay;

    input_initial(&data, 54798.48, 25, ANNUITY, 17.121, 16, 01, 2022);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {65509.5, 54798.48, 10711.02};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_8) {
    initial data;
    payments pay;

    input_initial(&data, 64972.21, 26, ANNUITY, 14.875, 28, 02, 2024);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {76361.58, 64972.21, 11389.37};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_9) {
    initial data;
    payments pay;

    input_initial(&data, 72578.54, 28, ANNUITY, 21.254, 8, 11, 2008);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {92635.41, 72578.54, 20056.87};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_10) {
    initial data;
    payments pay;

    input_initial(&data, 81458.47, 21, ANNUITY, 16.789, 12, 12, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {94559.9, 81458.47, 13101.43};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_11) {
    initial data;
    payments pay;

    input_initial(&data, 92784.88, 29, ANNUITY, 19.987, 25, 11, 2020);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {117690.04, 92784.88, 24905.16};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_12) {
    initial data;
    payments pay;

    input_initial(&data, 99999.99, 30, ANNUITY, 19.999, 9, 9, 2009);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {127853.88, 99999.99, 27853.89};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_13) {
    initial data;
    payments pay;

    input_initial(&data, 105597.84, 32, ANNUITY, 21.847, 4, 10, 2011);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {140275.08, 105597.84, 34677.24};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_14) {
    initial data;
    payments pay;

    input_initial(&data, 114874.84, 34, ANNUITY, 22.221, 8, 8, 2008);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {155807.13, 114874.84, 40932.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_15) {
    initial data;
    payments pay;

    input_initial(&data, 120000, 12, ANNUITY, 12, 19, 12, 2023);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {127947.47, 120000, 7947.47};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_16) {
    initial data;
    payments pay;

    input_initial(&data, 122784.45, 35, ANNUITY, 24.876, 11, 12, 1989);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {173860.53, 122784.45, 51076.08};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_17) {
    initial data;
    payments pay;

    input_initial(&data, 137846.94, 37, ANNUITY, 27.182, 25, 2, 1998);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {204743.09, 137846.94, 66896.15};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_18) {
    initial data;
    payments pay;

    input_initial(&data, 143975.18, 38, ANNUITY, 1.845, 15, 9, 1945);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {148330.04, 143975.18, 4354.86};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_19) {
    initial data;
    payments pay;

    input_initial(&data, 151879.84, 40, ANNUITY, 8.971, 20, 11, 1978);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {176256.41, 151879.84, 24376.57};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_20) {
    initial data;
    payments pay;

    input_initial(&data, 158797.48, 42, ANNUITY, 45.847, 1, 1, 2001);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {320600.04, 158797.48, 161802.56};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_21) {
    initial data;
    payments pay;

    input_initial(&data, 168848.24, 43, ANNUITY, 33.333, 3, 3, 2033);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {291898.66, 168848.24, 123050.42};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_22) {
    initial data;
    payments pay;

    input_initial(&data, 177548.15, 45, ANNUITY, 30.001, 6, 7, 2028);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {297904.33, 177548.15, 120356.18};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_23) {
    initial data;
    payments pay;

    input_initial(&data, 184999.99, 47, ANNUITY, 24.919, 4, 11, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {291326.81, 184999.99, 106326.82};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_24) {
    initial data;
    payments pay;

    input_initial(&data, 199999.99, 39, ANNUITY, 9.999, 9, 9, 1999);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {235054.76, 199999.99, 35054.77};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_25) {
    initial data;
    payments pay;

    input_initial(&data, 224875.67, 48, ANNUITY, 57.487, 11, 2, 1947);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {573870.68, 224875.67, 348995.01};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_26) {
    initial data;
    payments pay;

    input_initial(&data, 249723.16, 49, ANNUITY, 43.196, 4, 9, 1967);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {534585.92, 249723.16, 284862.76};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_27) {
    initial data;
    payments pay;

    input_initial(&data, 276314.57, 50, ANNUITY, 64.878, 1, 2, 2003);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {795788.74, 276314.57, 519474.17};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_28) {
    initial data;
    payments pay;

    input_initial(&data, 300000, 51, ANNUITY, 68.778, 6, 11, 2048);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {924455.42, 300000, 624455.42};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_29) {
    initial data;
    payments pay;

    input_initial(&data, 337541.43, 52, ANNUITY, 71.381, 9, 5, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1110467.87, 337541.43, 772926.44};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_30) {
    initial data;
    payments pay;

    input_initial(&data, 374112.34, 53, ANNUITY, 74.164, 11, 12, 2013);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1275795.53, 374112.34, 901683.19};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_31) {
    initial data;
    payments pay;

    input_initial(&data, 400000, 54, ANNUITY, 45.694, 16, 1, 1982);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {945742.58, 400000, 545742.58};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_32) {
    initial data;
    payments pay;

    input_initial(&data, 442341.55, 55, ANNUITY, 26.533, 6, 11, 1987);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {768335.62, 442341.55, 325994.07};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_33) {
    initial data;
    payments pay;

    input_initial(&data, 485212.25, 56, ANNUITY, 44.444, 14, 5, 2045);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1161540.56, 485212.25, 676328.31};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_34) {
    initial data;
    payments pay;

    input_initial(&data, 542678.51, 57, ANNUITY, 34.157, 11, 6, 2033);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1104172.78, 542678.51, 561494.27};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_35) {
    initial data;
    payments pay;

    input_initial(&data, 594314.32, 58, ANNUITY, 26.441, 2, 3, 2022);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1060209.81, 594314.32, 465895.49};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_36) {
    initial data;
    payments pay;

    input_initial(&data, 642314.87, 59, ANNUITY, 79.548, 5, 4, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2560669.04, 642314.87, 1918354.17};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_37) {
    initial data;
    payments pay;

    input_initial(&data, 697431.11, 60, ANNUITY, 81.544, 11, 10, 2016);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2885566.46, 697431.11, 2188135.35};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_38) {
    initial data;
    payments pay;

    input_initial(&data, 764131.15, 61, ANNUITY, 84.517, 18, 6, 2154);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {3375016.47, 764131.15, 2610885.32};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_39) {
    initial data;
    payments pay;

    input_initial(&data, 812341.58, 62, ANNUITY, 64.115, 6, 11, 2054);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2784070.78, 812341.58, 1971729.2};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_40) {
    initial data;
    payments pay;

    input_initial(&data, 866471.88, 63, ANNUITY, 14.587, 31, 1, 2002);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1244204.61, 866471.88, 377732.73};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_41) {
    initial data;
    payments pay;

    input_initial(&data, 904131.41, 64, ANNUITY, 11.124, 5, 3, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1202915.95, 904131.41, 298784.54};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_42) {
    initial data;
    payments pay;

    input_initial(&data, 971121.54, 65, ANNUITY, 7.891, 6, 7, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1196801.19, 971121.54, 225679.65};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_43) {
    initial data;
    payments pay;

    input_initial(&data, 1000000, 66, ANNUITY, 100, 5, 12, 2027);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {5467523.02, 1000000, 4467523.02};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_44) {
    initial data;
    payments pay;

    input_initial(&data, 1087135.54, 67, ANNUITY, 51.112, 17, 7, 2041);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {3324244.94, 1087135.54, 2237109.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_45) {
    initial data;
    payments pay;

    input_initial(&data, 1175434.15, 68, ANNUITY, 14.871, 22, 3, 2141);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1747477.36, 1175434.15, 572043.21};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_46) {
    initial data;
    payments pay;

    input_initial(&data, 1317981.54, 69, ANNUITY, 21.441, 21, 6, 2084);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2303273.23, 1317981.54, 985291.69};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_47) {
    initial data;
    payments pay;

    input_initial(&data, 1498752.24, 70, ANNUITY, 24.749, 27, 1, 2051);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2842310.65, 1498752.24, 1343558.41};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_48) {
    initial data;
    payments pay;

    input_initial(&data, 1674111.57, 71, ANNUITY, 8.244, 5, 5, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2121675.22, 1674111.57, 447563.65};

    for(int i = 0; i < 2; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_49) {
    initial data;
    payments pay;

    input_initial(&data, 1847566.39, 72, ANNUITY, 14.479, 15, 7, 2029);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2776653.67, 1847566.39, 929087.28};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(annuity_50) {
    initial data;
    payments pay;

    input_initial(&data, 2000000, 73, ANNUITY, 22.222, 22, 2, 2222);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {3657198.22, 2000000, 1657198.22};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(differentiated_1) {
    initial data;
    payments pay;

    input_initial(&data, 1000, 4, DIFFERENTIATED, 5, 06, 07, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1010.54, 1000, 10.54};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_2) {
    initial data;
    payments pay;

    input_initial(&data, 800, 12, DIFFERENTIATED, 3, 22, 02, 2016);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {812.94, 800, 12.94};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_3) {
    initial data;
    payments pay;

    input_initial(&data, 9862.12, 7, DIFFERENTIATED, 13.77, 9, 9, 2000);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {10312.98, 9862.12, 450.86};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_4) {
    initial data;
    payments pay;

    input_initial(&data, 26744.12, 15, DIFFERENTIATED, 16.111, 12, 3, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {29627.64, 26744.12, 2883.52};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_5) {
    initial data;
    payments pay;

    input_initial(&data, 38235.23, 18, DIFFERENTIATED, 9.725, 24, 04, 2014);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {41182.76, 38235.23, 2947.53};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_6) {
    initial data;
    payments pay;

    input_initial(&data, 49715.84, 21, DIFFERENTIATED, 19.875, 21, 07, 2019);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {58799.98, 49715.84, 9084.14};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_7) {
    initial data;
    payments pay;

    input_initial(&data, 54798.48, 25, DIFFERENTIATED, 17.121, 16, 01, 2022);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {64943.26, 54798.48, 10144.78};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_8) {
    initial data;
    payments pay;

    input_initial(&data, 64972.21, 26, DIFFERENTIATED, 14.875, 28, 02, 2024);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {75815.12, 64972.21, 10842.91};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_9) {
    initial data;
    payments pay;

    input_initial(&data, 72578.54, 28, DIFFERENTIATED, 21.254, 8, 11, 2008);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {91187.66, 72578.54, 18609.12};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_10) {
    initial data;
    payments pay;

    input_initial(&data, 81458.47, 21, DIFFERENTIATED, 16.789, 12, 12, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {93983.55, 81458.47, 12525.08};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(differentiated_11) {
    initial data;
    payments pay;

    input_initial(&data, 92784.88, 29, DIFFERENTIATED, 19.987, 25, 11, 2020);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {115930.84, 92784.88, 23145.96};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_12) {
    initial data;
    payments pay;

    input_initial(&data, 99999.99, 30, DIFFERENTIATED, 19.999, 9, 9, 2009);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {125811.83, 99999.99, 25811.84};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_13) {
    initial data;
    payments pay;

    input_initial(&data, 105597.84, 32, DIFFERENTIATED, 21.847, 4, 10, 2011);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {137325.72, 105597.84, 31727.88};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_14) {
    initial data;
    payments pay;

    input_initial(&data, 114874.84, 34, DIFFERENTIATED, 22.221, 8, 8, 2008);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {152085.1, 114874.84, 37210.26};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_15) {
    initial data;
    payments pay;

    input_initial(&data, 120000, 12, DIFFERENTIATED, 12, 19, 12, 2023);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {127804.58, 120000, 7804.58};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_16) {
    initial data;
    payments pay;

    input_initial(&data, 122784.45, 35, DIFFERENTIATED, 24.876, 11, 12, 1989);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {168592.06, 122784.45, 45807.61};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_17) {
    initial data;
    payments pay;

    input_initial(&data, 137846.94, 37, DIFFERENTIATED, 27.182, 25, 2, 1998);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {197040, 137846.94, 59193.06};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_18) {
    initial data;
    payments pay;

    input_initial(&data, 143975.18, 38, DIFFERENTIATED, 1.845, 15, 9, 1945);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {148289.28, 143975.18, 4314.1};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_19) {
    initial data;
    payments pay;

    input_initial(&data, 151879.84, 40, DIFFERENTIATED, 8.971, 20, 11, 1978);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {175137.6, 151879.84, 23257.76};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_20) {
    initial data;
    payments pay;

    input_initial(&data, 158797.48, 42, DIFFERENTIATED, 45.847, 1, 1, 2001);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {289085.83, 158797.48, 130288.35};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(differentiated_21) {
    initial data;
    payments pay;

    input_initial(&data, 168848.24, 43, DIFFERENTIATED, 33.333, 3, 3, 2033);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {272200.89, 168848.24, 103352.65};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_22) {
    initial data;
    payments pay;

    input_initial(&data, 177548.15, 45, DIFFERENTIATED, 30.001, 6, 7, 2028);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {279688.78, 177548.15, 102140.63};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_23) {
    initial data;
    payments pay;

    input_initial(&data, 184999.99, 47, DIFFERENTIATED, 24.919, 4, 11, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {277131.45, 184999.99, 92131.46};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_24) {
    initial data;
    payments pay;

    input_initial(&data, 199999.99, 39, DIFFERENTIATED, 9.999, 9, 9, 1999);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {233312.06, 199999.99, 33312.07};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_25) {
    initial data;
    payments pay;

    input_initial(&data, 224875.67, 48, DIFFERENTIATED, 57.487, 11, 2, 1947);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {488354.28, 224875.67, 263478.61};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_26) {
    initial data;
    payments pay;

    input_initial(&data, 249723.16, 49, DIFFERENTIATED, 43.196, 4, 9, 1967);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {474344.46, 249723.16, 224621.3};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_27) {
    initial data;
    payments pay;

    input_initial(&data, 276314.57, 50, DIFFERENTIATED, 64.878, 1, 2, 2003);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {656611.77, 276314.57, 380297.2};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_28) {
    initial data;
    payments pay;

    input_initial(&data, 300000, 51, DIFFERENTIATED, 68.778, 6, 11, 2048);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {746693.89, 300000, 446693.89};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_29) {
    initial data;
    payments pay;

    input_initial(&data, 337541.43, 52, DIFFERENTIATED, 71.381, 9, 5, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {870241.02, 337541.43, 532699.59};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_30) {
    initial data;
    payments pay;

    input_initial(&data, 374112.34, 53, DIFFERENTIATED, 74.164, 11, 12, 2013);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {998288.37, 374112.34, 624176.03};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(differentiated_31) {
    initial data;
    payments pay;

    input_initial(&data, 400000, 54, DIFFERENTIATED, 45.694, 16, 1, 1982);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {818483.57, 400000, 418483.57};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_32) {
    initial data;
    payments pay;

    input_initial(&data, 442341.55, 55, DIFFERENTIATED, 26.533, 6, 11, 1987);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {716034.89, 442341.55, 273693.34};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_33) {
    initial data;
    payments pay;

    input_initial(&data, 485212.25, 56, DIFFERENTIATED, 44.444, 14, 5, 2045);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {997946.16, 485212.25, 512733.91};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_34) {
    initial data;
    payments pay;

    input_initial(&data, 542678.51, 57, DIFFERENTIATED, 34.157, 11, 6, 2033);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {990837.77, 542678.51, 448159.26};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_35) {
    initial data;
    payments pay;

    input_initial(&data, 594314.32, 58, DIFFERENTIATED, 26.441, 2, 3, 2022);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {981102.3, 594314.32, 386787.98};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_36) {
    initial data;
    payments pay;

    input_initial(&data, 642314.87, 59, DIFFERENTIATED, 79.548, 5, 4, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1919478.63, 642314.87, 1277163.76};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_37) {
    initial data;
    payments pay;

    input_initial(&data, 697431.11, 60, DIFFERENTIATED, 81.544, 11, 10, 2016);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2142613.84, 697431.11, 1445182.73};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_38) {
    initial data;
    payments pay;

    input_initial(&data, 764131.15, 61, DIFFERENTIATED, 84.517, 18, 6, 2154);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2433110.7, 764131.15, 1668979.55};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_39) {
    initial data;
    payments pay;

    input_initial(&data, 812341.58, 62, DIFFERENTIATED, 64.115, 6, 11, 2054);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2178758.18, 812341.58, 1366416.6};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_40) {
    initial data;
    payments pay;

    input_initial(&data, 866471.88, 63, DIFFERENTIATED, 14.587, 31, 1, 2002);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1203053.55, 866471.88, 336581.67};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(differentiated_41) {
    initial data;
    payments pay;

    input_initial(&data, 904131.41, 64, DIFFERENTIATED, 11.124, 5, 3, 2012);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1176608.45, 904131.41, 272477.04};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_42) {
    initial data;
    payments pay;

    input_initial(&data, 971121.54, 65, DIFFERENTIATED, 7.891, 6, 7, 2021);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1182023.94, 971121.54, 210902.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_43) {
    initial data;
    payments pay;

    input_initial(&data, 1000000, 66, DIFFERENTIATED, 100, 5, 12, 2027);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {3791435.39, 1000000, 2791435.39};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_44) {
    initial data;
    payments pay;

    input_initial(&data, 1087135.54, 67, DIFFERENTIATED, 51.112, 17, 7, 2041);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2662741.49, 1087135.54, 1575605.95};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_45) {
    initial data;
    payments pay;

    input_initial(&data, 1175434.15, 68, DIFFERENTIATED, 14.871, 22, 3, 2141);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {1678496.81, 1175434.15, 503062.66};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_46) {
    initial data;
    payments pay;

    input_initial(&data, 1317981.54, 69, DIFFERENTIATED, 21.441, 21, 6, 2084);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2142092.39, 1317981.54, 824110.85};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_47) {
    initial data;
    payments pay;

    input_initial(&data, 1498752.24, 70, DIFFERENTIATED, 24.749, 27, 1, 2051);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2595361.53, 1498752.24, 1096609.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_48) {
    initial data;
    payments pay;

    input_initial(&data, 1674111.57, 71, DIFFERENTIATED, 8.244, 5, 5, 2005);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2088511.44, 1674111.57, 414399.87};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_49) {
    initial data;
    payments pay;

    input_initial(&data, 1847566.39, 72, DIFFERENTIATED, 14.479, 15, 7, 2029);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {2661800.25, 1847566.39, 814233.86};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

START_TEST(differentiated_50) {
    initial data;
    payments pay;

    input_initial(&data, 2000000, 73, DIFFERENTIATED, 22.222, 22, 2, 2222);
    calculate_credit(&data, &pay, NULL);
    long double result_total[3] = {3368737.81, 2000000, 1368737.81};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current + 1, &pay, NULL);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(pointers_1) {
    calculate_credit(NULL, NULL, NULL);
}

START_TEST(pointers_2) {
    initial data;

    input_initial(&data, 120000, 6, DIFFERENTIATED, 10, 01, 03, 2022);

    calculate_credit(&data, NULL, NULL);

    free_memory(data.current, NULL, NULL);
}

START_TEST(pointers_3) {
    initial data;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 120000, 6, DIFFERENTIATED, 10, 01, 03, 2022);
    input_redemption(&redemption, 1, 4, 2022, 5232, REDUCE_TERM);

    calculate_credit(&data, NULL, &redemption);

    free_memory(data.current, NULL, &redemption);
}

START_TEST(pointers_4) {
    another_payments redemption;
    init_redemption(&redemption);

    input_redemption(&redemption, 1, 4, 2022, 5232, REDUCE_TERM);

    calculate_credit(NULL, NULL, &redemption);

    free_memory(0, NULL, &redemption);
}

START_TEST(pointers_5) {
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_redemption(&redemption, 1, 4, 2022, 5232, REDUCE_TERM);

    calculate_credit(NULL, &pay, &redemption);

    free_memory(0, NULL, &redemption);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(diff_redemption_term_1) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 120000, 6, DIFFERENTIATED, 10, 01, 03, 2022);
    input_redemption(&redemption, 1, 4, 2022, 5232, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {123303.99, 120000, 3303.99};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_2) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 21, 12, 2022, 25000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349401.61, 333333.33, 16068.28};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_3) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349720.58, 333333.33, 16387.25};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_4) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_TERM);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349087.51, 333333.33, 15754.18};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_5) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_TERM);
    input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_TERM);
    input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15455177.6, 12364567.22, 3090610.38};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_6) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 17, 01, 2019, 2000, REDUCE_TERM);
    input_redemption(&redemption, 18, 01, 2019, 1500, REDUCE_TERM);
    input_redemption(&redemption, 19, 01, 2019, 100000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15558777.51, 12364567.22, 3194210.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_7) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 55321523.34, 43, DIFFERENTIATED, 21.463, 03, 01, 2019);
    input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_TERM);
    input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_TERM);
    input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_TERM);
    input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {77065876.72, 55321523.34, 21744353.38};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_8) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 77777777.77, 126, DIFFERENTIATED, 8.962, 8, 4, 2002);
    input_redemption(&redemption, 16, 5, 2002, 5246521, REDUCE_TERM);
    input_redemption(&redemption, 21, 11, 2002, 3262152, REDUCE_TERM);
    input_redemption(&redemption, 22, 9, 2004, 1000000, REDUCE_TERM);
    input_redemption(&redemption, 28, 2, 2005, 2000000, REDUCE_TERM);
    input_redemption(&redemption, 29, 2, 2008, 6235667, REDUCE_TERM);
    input_redemption(&redemption, 31, 12, 2008, 1500000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {104378506.06, 77777777.77, 26600728.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_9) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, DIFFERENTIATED, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_TERM);
    input_redemption(&redemption, 21,  5, 2015, 100000000, REDUCE_TERM);
    input_redemption(&redemption, 21, 12, 2015, 231023400, REDUCE_TERM);
    input_redemption(&redemption, 31,  1, 2016, 231235620, REDUCE_TERM);
    input_redemption(&redemption,  1,  2, 2016, 123645600, REDUCE_TERM);
    input_redemption(&redemption,  6,  6, 2016, 289364410, REDUCE_TERM);
    input_redemption(&redemption, 30, 11, 2016, 201123445, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1507461575.35, 1275367531, 232094044.35};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_term_10) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, DIFFERENTIATED, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_TERM);
    input_redemption(&redemption,  8,  5, 2015, 100000000, REDUCE_TERM);
    input_redemption(&redemption,  9,  5, 2015, 231023400, REDUCE_TERM);
    input_redemption(&redemption, 10,  5, 2015, 231235620, REDUCE_TERM);
    input_redemption(&redemption, 11,  5, 2015, 123645600, REDUCE_TERM);
    input_redemption(&redemption, 12,  5, 2015, 289364410, REDUCE_TERM);
    input_redemption(&redemption, 13,  7, 2015, 201123445, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1357014203.43, 1275367531, 81646672.43};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(diff_redemption_pay_1) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 120000, 6, DIFFERENTIATED, 10, 01, 03, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {123392.28, 120000, 3392.28};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_2) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 23, 12, 2022, 25000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350245.52, 333333.33, 16912.19};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_3) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350495.97, 333333.33, 17162.64};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_4) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, DIFFERENTIATED, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_PAY);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350155.96, 333333.33, 16822.63};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_5) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_PAY);
    input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_PAY);
    input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15523983.03, 12364567.22, 3159415.81};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_6) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, DIFFERENTIATED, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 17, 01, 2019, 2000, REDUCE_PAY);
    input_redemption(&redemption, 18, 01, 2019, 1500, REDUCE_PAY);
    input_redemption(&redemption, 19, 01, 2019, 100000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15577217.53, 12364567.22, 3212650.31};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_7) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 55321523.34, 43, DIFFERENTIATED, 21.463, 03, 01, 2019);
    input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_PAY);
    input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_PAY);
    input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_PAY);
    input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {77065876.72, 55321523.34, 21744353.38};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_8) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 77777777.77, 126, DIFFERENTIATED, 8.962, 8, 4, 2002);
    input_redemption(&redemption, 16, 5, 2002, 5246521, REDUCE_PAY);
    input_redemption(&redemption, 21, 11, 2002, 3262152, REDUCE_PAY);
    input_redemption(&redemption, 22, 9, 2004, 1000000, REDUCE_PAY);
    input_redemption(&redemption, 28, 2, 2005, 2000000, REDUCE_PAY);
    input_redemption(&redemption, 29, 2, 2008, 6235667, REDUCE_PAY);
    input_redemption(&redemption, 31, 12, 2008, 1500000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {108536699.99, 77777777.77, 30758922.22};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_9) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, DIFFERENTIATED, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_PAY);
    input_redemption(&redemption, 21,  5, 2015, 100000000, REDUCE_PAY);
    input_redemption(&redemption, 21, 12, 2015, 231023400, REDUCE_PAY);
    input_redemption(&redemption, 31,  1, 2016, 231235620, REDUCE_PAY);
    input_redemption(&redemption,  1,  2, 2016, 123645600, REDUCE_PAY);
    input_redemption(&redemption,  6,  6, 2016, 289364410, REDUCE_PAY);
    input_redemption(&redemption, 30, 11, 2016, 201123445, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1512894239.55, 1275367531, 237526708.55};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(diff_redemption_pay_10) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, DIFFERENTIATED, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_PAY);
    input_redemption(&redemption,  8,  5, 2015, 100000000, REDUCE_PAY);
    input_redemption(&redemption,  9,  5, 2015, 231023400, REDUCE_PAY);
    input_redemption(&redemption, 10,  5, 2015, 231235620, REDUCE_PAY);
    input_redemption(&redemption, 11,  5, 2015, 123645600, REDUCE_PAY);
    input_redemption(&redemption, 12,  5, 2015, 289364410, REDUCE_PAY);
    input_redemption(&redemption, 13,  7, 2015, 201123445, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1357155980.3, 1275367531, 81788449.3};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_redemption_term_1) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 120000, 6, ANNUITY, 10, 01, 03, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {123325.31, 120000, 3325.31};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}


START_TEST(annuity_redemption_term_2) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 21, 12, 2022, 25000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349553.37, 333333.33, 16220.04};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_3) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349864.52, 333333.33, 16531.19};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_4) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_TERM);
    input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_TERM);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {349202.58, 333333.33, 15869.25};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_5) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, ANNUITY, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_TERM);
    input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_TERM);
    input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15632055.55, 12364567.22, 3267488.33};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_6) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, ANNUITY, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 17, 01, 2019, 2000, REDUCE_TERM);
    input_redemption(&redemption, 18, 01, 2019, 1500, REDUCE_TERM);
    input_redemption(&redemption, 19, 01, 2019, 100000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15795556.74, 12364567.22, 3430989.52};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_7) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 55321523.34, 43, ANNUITY, 21.463, 03, 01, 2019);
    input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_TERM);
    input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_TERM);
    input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_TERM);
    input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {79371094.51, 55321523.34, 24049571.17};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_8) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 77777777.77, 126, ANNUITY, 8.962, 8, 4, 2002);
    input_redemption(&redemption, 16, 5, 2002, 5246521, REDUCE_TERM);
    input_redemption(&redemption, 21, 11, 2002, 3262152, REDUCE_TERM);
    input_redemption(&redemption, 22, 9, 2004, 1000000, REDUCE_TERM);
    input_redemption(&redemption, 28, 2, 2005, 2000000, REDUCE_TERM);
    input_redemption(&redemption, 29, 2, 2008, 6235667, REDUCE_TERM);
    input_redemption(&redemption, 31, 12, 2008, 1500000, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {105665490.78, 77777777.77, 27887713.01};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_9) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, ANNUITY, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_TERM);
    input_redemption(&redemption, 21,  5, 2015, 100000000, REDUCE_TERM);
    input_redemption(&redemption, 21, 12, 2015, 231023400, REDUCE_TERM);
    input_redemption(&redemption, 31,  1, 2016, 231235620, REDUCE_TERM);
    input_redemption(&redemption,  1,  2, 2016, 123645600, REDUCE_TERM);
    input_redemption(&redemption,  6,  6, 2016, 289364410, REDUCE_TERM);
    input_redemption(&redemption, 30, 11, 2016, 201123445, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1505034239.42, 1275367531, 229666708.42};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_term_10) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, ANNUITY, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_TERM);
    input_redemption(&redemption,  8,  5, 2015, 100000000, REDUCE_TERM);
    input_redemption(&redemption,  9,  5, 2015, 231023400, REDUCE_TERM);
    input_redemption(&redemption, 10,  5, 2015, 231235620, REDUCE_TERM);
    input_redemption(&redemption, 11,  5, 2015, 123645600, REDUCE_TERM);
    input_redemption(&redemption, 12,  5, 2015, 289364410, REDUCE_TERM);
    input_redemption(&redemption, 13,  7, 2015, 201123445, REDUCE_TERM);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1357840085.12, 1275367531, 82472554.12};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

START_TEST(annuity_redemption_pay_1) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 120000, 6, ANNUITY, 10, 01, 03, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {123416.29, 120000, 3416.29};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}


START_TEST(annuity_redemption_pay_2) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 01, 04, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 21, 12, 2022, 25000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350528.01, 333333.33, 17194.68};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_3) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350705.73, 333333.33, 17372.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_4) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 333333.33, 25, ANNUITY, 5, 23, 02, 2022);
    input_redemption(&redemption, 26, 03, 2022, 5232, REDUCE_PAY);
    input_redemption(&redemption, 01, 04, 2022, 6666, REDUCE_PAY);
    input_redemption(&redemption, 10, 04, 2022, 12000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {350361.73, 333333.33, 17028.4};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_5) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, ANNUITY, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 05, 02, 2019, 51235, REDUCE_PAY);
    input_redemption(&redemption, 22, 02, 2020, 212731, REDUCE_PAY);
    input_redemption(&redemption, 30, 07, 2020, 260000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15743504.95, 12364567.22, 3378937.73};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_6) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 12364567.22, 55, ANNUITY, 11.211, 11, 01, 2019);
    input_redemption(&redemption, 17, 01, 2019, 2000, REDUCE_PAY);
    input_redemption(&redemption, 18, 01, 2019, 1500, REDUCE_PAY);
    input_redemption(&redemption, 19, 01, 2019, 100000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {15823651.02, 12364567.22, 3459083.8};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_7) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 55321523.34, 43, ANNUITY, 21.463, 03, 01, 2019);
    input_redemption(&redemption, 21, 04, 2019, 50000, REDUCE_PAY);
    input_redemption(&redemption, 30, 04, 2019, 75000, REDUCE_PAY);
    input_redemption(&redemption, 31, 12, 2019, 100000, REDUCE_PAY);
    input_redemption(&redemption, 01, 01, 2020, 200000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {79371094.51, 55321523.34, 24049571.17};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_8) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 77777777.77, 126, ANNUITY, 8.962, 8, 4, 2002);
    input_redemption(&redemption, 16, 5, 2002, 5246521, REDUCE_PAY);
    input_redemption(&redemption, 21, 11, 2002, 3262152, REDUCE_PAY);
    input_redemption(&redemption, 22, 9, 2004, 1000000, REDUCE_PAY);
    input_redemption(&redemption, 28, 2, 2005, 2000000, REDUCE_PAY);
    input_redemption(&redemption, 29, 2, 2008, 6235667, REDUCE_PAY);
    input_redemption(&redemption, 31, 12, 2008, 1500000, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {112884986.74, 77777777.77, 35107208.97};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_9) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, ANNUITY, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_PAY);
    input_redemption(&redemption, 21,  5, 2015, 100000000, REDUCE_PAY);
    input_redemption(&redemption, 21, 12, 2015, 231023400, REDUCE_PAY);
    input_redemption(&redemption, 31,  1, 2016, 231235620, REDUCE_PAY);
    input_redemption(&redemption,  1,  2, 2016, 123645600, REDUCE_PAY);
    input_redemption(&redemption,  6,  6, 2016, 289364410, REDUCE_PAY);
    input_redemption(&redemption, 30, 11, 2016, 201123445, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1522054431.25, 1275367531, 246686900.25};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

START_TEST(annuity_redemption_pay_10) {
    initial data;
    payments pay;
    another_payments redemption;
    init_redemption(&redemption);

    input_initial(&data, 1275367531, 200, ANNUITY, 17.231, 1, 1, 2015);
    input_redemption(&redemption,  7,  5, 2015, 120214620, REDUCE_PAY);
    input_redemption(&redemption,  8,  5, 2015, 100000000, REDUCE_PAY);
    input_redemption(&redemption,  9,  5, 2015, 231023400, REDUCE_PAY);
    input_redemption(&redemption, 10,  5, 2015, 231235620, REDUCE_PAY);
    input_redemption(&redemption, 11,  5, 2015, 123645600, REDUCE_PAY);
    input_redemption(&redemption, 12,  5, 2015, 289364410, REDUCE_PAY);
    input_redemption(&redemption, 13,  5, 2015, 201123445, REDUCE_PAY);

    calculate_credit(&data, &pay, &redemption);
    long double result_total[3] = {1353111213.78, 1275367531, 77743682.78};

    for(int i = 0; i < 3; i++) {
        ck_assert_double_eq_tol(pay.total[i], result_total[i], 1e-3);
    }
    free_memory(data.current, &pay, &redemption);
}

//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

Suite *s21_annuity_3(void) {
    Suite *credit = suite_create("s21_credit (annuity third cases)");

    TCase *tc_test_annuity_3 = tcase_create("test_annuity");
    tcase_add_test(tc_test_annuity_3, annuity_21);
    tcase_add_test(tc_test_annuity_3, annuity_22);
    tcase_add_test(tc_test_annuity_3, annuity_23);
    tcase_add_test(tc_test_annuity_3, annuity_24);
    tcase_add_test(tc_test_annuity_3, annuity_25);
    tcase_add_test(tc_test_annuity_3, annuity_26);
    tcase_add_test(tc_test_annuity_3, annuity_27);
    tcase_add_test(tc_test_annuity_3, annuity_28);
    tcase_add_test(tc_test_annuity_3, annuity_29);
    tcase_add_test(tc_test_annuity_3, annuity_30);
    suite_add_tcase(credit, tc_test_annuity_3);

    return credit;
}

Suite *s21_annuity_4(void) {
    Suite *credit = suite_create("s21_credit (annuity fourth cases)");

    TCase *tc_test_annuity_4 = tcase_create("test_annuity");
    tcase_add_test(tc_test_annuity_4, annuity_31);
    tcase_add_test(tc_test_annuity_4, annuity_32);
    tcase_add_test(tc_test_annuity_4, annuity_33);
    tcase_add_test(tc_test_annuity_4, annuity_34);
    tcase_add_test(tc_test_annuity_4, annuity_35);
    tcase_add_test(tc_test_annuity_4, annuity_36);
    tcase_add_test(tc_test_annuity_4, annuity_37);
    tcase_add_test(tc_test_annuity_4, annuity_38);
    tcase_add_test(tc_test_annuity_4, annuity_39);
    tcase_add_test(tc_test_annuity_4, annuity_40);
    suite_add_tcase(credit, tc_test_annuity_4);

    return credit;
}

Suite *s21_annuity_5(void) {
    Suite *credit = suite_create("s21_credit (annuity fifth cases)");

    TCase *tc_test_annuity_5 = tcase_create("test_annuity");
    tcase_add_test(tc_test_annuity_5, annuity_41);
    tcase_add_test(tc_test_annuity_5, annuity_42);
    tcase_add_test(tc_test_annuity_5, annuity_43);
    tcase_add_test(tc_test_annuity_5, annuity_44);
    tcase_add_test(tc_test_annuity_5, annuity_45);
    tcase_add_test(tc_test_annuity_5, annuity_46);
    tcase_add_test(tc_test_annuity_5, annuity_47);
    tcase_add_test(tc_test_annuity_5, annuity_48);
    tcase_add_test(tc_test_annuity_5, annuity_49);
    tcase_add_test(tc_test_annuity_5, annuity_50);
    suite_add_tcase(credit, tc_test_annuity_5);

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

Suite *s21_differentiated_3(void) {
    Suite *credit = suite_create("s21_credit (differentiated third cases)");

    TCase *tc_test_differentiated_3 = tcase_create("test_differentiated");
    tcase_add_test(tc_test_differentiated_3, differentiated_21);
    tcase_add_test(tc_test_differentiated_3, differentiated_22);
    tcase_add_test(tc_test_differentiated_3, differentiated_23);
    tcase_add_test(tc_test_differentiated_3, differentiated_24);
    tcase_add_test(tc_test_differentiated_3, differentiated_25);
    tcase_add_test(tc_test_differentiated_3, differentiated_26);
    tcase_add_test(tc_test_differentiated_3, differentiated_27);
    tcase_add_test(tc_test_differentiated_3, differentiated_28);
    tcase_add_test(tc_test_differentiated_3, differentiated_29);
    tcase_add_test(tc_test_differentiated_3, differentiated_30);
    suite_add_tcase(credit, tc_test_differentiated_3);

    return credit;
}

Suite *s21_differentiated_4(void) {
    Suite *credit = suite_create("s21_credit (differentiated fourth cases)");

    TCase *tc_test_differentiated_4 = tcase_create("test_differentiated");
    tcase_add_test(tc_test_differentiated_4, differentiated_31);
    tcase_add_test(tc_test_differentiated_4, differentiated_32);
    tcase_add_test(tc_test_differentiated_4, differentiated_33);
    tcase_add_test(tc_test_differentiated_4, differentiated_34);
    tcase_add_test(tc_test_differentiated_4, differentiated_35);
    tcase_add_test(tc_test_differentiated_4, differentiated_36);
    tcase_add_test(tc_test_differentiated_4, differentiated_37);
    tcase_add_test(tc_test_differentiated_4, differentiated_38);
    tcase_add_test(tc_test_differentiated_4, differentiated_39);
    tcase_add_test(tc_test_differentiated_4, differentiated_40);
    suite_add_tcase(credit, tc_test_differentiated_4);

    return credit;
}

Suite *s21_differentiated_5(void) {
    Suite *credit = suite_create("s21_credit (differentiated fifth cases)");

    TCase *tc_test_differentiated_5 = tcase_create("test_differentiated");
    tcase_add_test(tc_test_differentiated_5, differentiated_41);
    tcase_add_test(tc_test_differentiated_5, differentiated_42);
    tcase_add_test(tc_test_differentiated_5, differentiated_43);
    tcase_add_test(tc_test_differentiated_5, differentiated_44);
    tcase_add_test(tc_test_differentiated_5, differentiated_45);
    tcase_add_test(tc_test_differentiated_5, differentiated_46);
    tcase_add_test(tc_test_differentiated_5, differentiated_47);
    tcase_add_test(tc_test_differentiated_5, differentiated_48);
    tcase_add_test(tc_test_differentiated_5, differentiated_49);
    tcase_add_test(tc_test_differentiated_5, differentiated_50);
    suite_add_tcase(credit, tc_test_differentiated_5);

    return credit;
}

Suite *s21_pointer_test(void) {
    Suite *credit = suite_create("s21_credit (pointers tests)");

    TCase *tc_test_pointers_1 = tcase_create("test_pointers");
    tcase_add_test(tc_test_pointers_1, pointers_1);
    tcase_add_test(tc_test_pointers_1, pointers_2);
    tcase_add_test(tc_test_pointers_1, pointers_3);
    tcase_add_test(tc_test_pointers_1, pointers_4);
    tcase_add_test(tc_test_pointers_1, pointers_5);
    suite_add_tcase(credit, tc_test_pointers_1);

    return credit;
}

Suite *s21_diff_redemption_term(void) {
    Suite *credit = suite_create("s21_credit (differentiated reduce term)");

    TCase *tc_test_diff_term_1 = tcase_create("test_diff_term");
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_1);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_2);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_3);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_4);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_5);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_6);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_7);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_8);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_9);
    tcase_add_test(tc_test_diff_term_1, diff_redemption_term_10);
    
    suite_add_tcase(credit, tc_test_diff_term_1);

    return credit;
}

Suite *s21_diff_redemption_pay(void) {
    Suite *credit = suite_create("s21_credit (differentiated reduce pay)");

    TCase *tc_test_diff_pay_1 = tcase_create("test_diff_pay");
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_1);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_2);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_3);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_4);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_5);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_6);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_7);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_8);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_9);
    tcase_add_test(tc_test_diff_pay_1, diff_redemption_pay_10);

    suite_add_tcase(credit, tc_test_diff_pay_1);

    return credit;
}

Suite *s21_annuity_redepmtion_term(void) {
    Suite *credit = suite_create("s21_credit (annuity reduce term)");

    TCase *tc_test_annuity_term_1 = tcase_create("test_annuity_term");
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_1);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_2);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_3);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_4);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_5);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_6);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_7);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_8);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_9);
    tcase_add_test(tc_test_annuity_term_1, annuity_redemption_term_10);
    
    suite_add_tcase(credit, tc_test_annuity_term_1);

    return credit;
}

Suite *s21_annuity_redepmtion_pay(void) {
    Suite *credit = suite_create("s21_credit (annuity reduce pay)");

    TCase *tc_test_annuity_pay_1 = tcase_create("test_annuity_term");
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_1);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_2);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_3);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_4);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_5);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_6);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_7);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_8);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_9);
    tcase_add_test(tc_test_annuity_pay_1, annuity_redemption_pay_10);
    suite_add_tcase(credit, tc_test_annuity_pay_1);

    return credit;
}