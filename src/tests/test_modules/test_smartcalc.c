#include "./test_include/test_smartcalc.h"

static void s21_test_print(char *expression, double my_result,
                           double true_result);

//  ============================================================================

START_TEST(arifmetic_test_1) {
  char *example =
      "(((1.123*213.5555-((217.12354))*1/2)/4/6*(5632.57-123.344)/(23.12346)/"
      "(4.213*(((653.13*(14.123*121.2345+2/(23.123+9*0.213))))/"
      "((237.12*21.8888))/(1.888+92.14)))))";
  double my_result = calculation(example, 0);
  double true_result = 134.97247948;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_2) {
  char *example = "((2*3)-(4/2))";
  double my_result = calculation(example, 0);
  double true_result = 4;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_3) {
  char *example = "324.14*(10+5)/(2*3)";
  double my_result = calculation(example, 0);
  double true_result = 810.35;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_4) {
  char *example = "(((1.5*2)/3)-((4-2)*1))";
  double my_result = calculation(example, 0);
  double true_result = -1;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_5) {
  char *example = "((6/2)+(4*2))";
  double my_result = calculation(example, 0);
  double true_result = 11;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_6) {
  char *example = "((8-2)*(3+1))/4";
  double my_result = calculation(example, 0);
  double true_result = 6;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_7) {
  char *example = "0.04230*(((12/3)*2)-5)";
  double my_result = calculation(example, 0);
  double true_result = 0.1269;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_8) {
  char *example = "(((2.5*3)/(1.5-0.5))-((4/2)+1))";
  double my_result = calculation(example, 0);
  double true_result = 4.5;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_9) {
  char *example = "((10*(2/5))+((3-1)*(8/2)))";
  double my_result = calculation(example, 0);
  double true_result = 12;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_10) {
  char *example = "((20/4)(5-(3/1.5)))";
  double my_result = calculation(example, 0);
  double true_result = 15;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(arifmetic_test_11) {
  char *example = "(((15*2)/(3+2))-(7*0.5)) - (+2)";
  double my_result = calculation(example, 0);
  double true_result = 0.5;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_12) {
  char *example = "-1*((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))";
  double my_result = calculation(example, 0);
  double true_result = -2.82017077;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_13) {
  char *example = "0.09000012*(((18.435/3.432)+2.412)*(4.8324-1.2432))";
  double my_result = calculation(example, 0);
  double true_result = 2.51429291;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_14) {
  char *example = "((9.756+(7/2.756))*(4.253-(3.142/1.523)))";
  double my_result = calculation(example, 0);
  double true_result = 26.92763754;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_15) {
  char *example = "(((12/2)+(5*1.5))/(3-1))";
  double my_result = calculation(example, 0);
  double true_result = 6.75;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_16) {
  char *example =
      "325.5324*(((2.5432*3.432)/(1342.5-10.5324))-((44325.11123/"
      "2324.234)+1.234))/(3.234-((2.7568*1.5234)+0.5324))";
  double my_result = calculation(example, 0);
  double true_result = 4410.72838720;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_17) {
  char *example =
      "((10.00032*(223.21/5.214))+((23.53-1.321)*(2123.8/2.5326)))/"
      "(1.3412+(2123.52/(3321.234-1.41142)))";
  double my_result = calculation(example, 0);
  double true_result = 9618.22208480;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_18) {
  char *example =
      "((2.2340/43.541)*(5.1325-(3.3214/14.5231)))/((31.22*31.5321)-(141.52/"
      "103.5324))";
  double my_result = calculation(example, 0);
  double true_result = 0.00025593;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_19) {
  char *example =
      "(((132.5*232.4)/(34.32+423.2))-(74.32*30.5432))*(432.4/(243.24-14.52))";
  double my_result = calculation(example, 0);
  double true_result = -4164.18755839;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_20) {
  char *example =
      "((64.57*(2774.5-165.445))/(353.4678-(276.9354/43.456)))+(57.65-(323.5/"
      "1.3425))";
  double my_result = calculation(example, 0);
  double true_result = 302.04350416;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(arifmetic_test_21) {
  char *example =
      "(((189.67/423.3)+2.34)*(46.34/6.348-1634.2))/((25.343*0.63465)+(54.371/"
      "50543.55))";
  double my_result = calculation(example, 0);
  double true_result = -281.99663138;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_22) {
  char *example =
      "235-((953.26+(763.24/432.432))*(45.66-(39.78/1978.995)))-(9792.995/"
      "(9780.5978*2789.5234))";
  double my_result = calculation(example, 0);
  double true_result = -43352.24453277;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_23) {
  char *example =
      "634*(((1234.45232/2.2354)+(5123.324*1241.2355))/"
      "(235.553-142.71))+(2346.26*(1423.525/10432.3255))";
  double my_result = calculation(example, 0);
  double true_result = 43429718.64983888;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_24) {
  char *example =
      "(((5232.555*3876.8768)/(107.578-0078.0785))-((70784.78/"
      "50782.807)+4321.67))/(13.42-((532.2253*1523.5523)+5230.3255))";
  double my_result = calculation(example, 0);
  double true_result = -0.83734470;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_25) {
  char *example =
      "((137610.432*(2234.532/5.643))+((34.23423-521.42365)*(5238.523/"
      "62.325)))/(4571.2345+(252.253/(5233.523-1523.745)))";
  double my_result = calculation(example, 0);
  double true_result = 11911.36244976;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_26) {
  char *example =
      "328*(253*(203.41/44.32)*(5.3214-(142.3/1532.5532)))/"
      "((25.23*4231.53254)-(11.2/4350.5325))";
  double my_result = calculation(example, 0);
  double true_result = 18.65233133;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_27) {
  char *example =
      "(((1432.22345*532.652)/"
      "(3.324234+423.4322))-(741.4132*0.5432))*(4324.234/(232.1234-1324.325))";
  double my_result = calculation(example, 0);
  double true_result = -5483.00538785;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_28) {
  char *example =
      "34*((631543.151*(253154.124-1532.12521))/(3235.124353-(2532.1241/"
      "452.432)))+(535.21354-(32314.123/15342.342))";
  double my_result = calculation(example, 0);
  double true_result = 1672983604.33760846;
  ck_assert_double_eq_tol(my_result, true_result, 1e-6);
}

START_TEST(arifmetic_test_29) {
  char *example = "((18235.352/3.5322)+2325/1214.41)*(434.8-321.3252)";
  double my_result = calculation(example, 0);
  double true_result = 586042.77411927;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_30) {
  char *example =
      "0.321*((9324.235+(5432.7/3254.662))*(4432.11-(423.143/"
      "1423.3245)))-(25324.5111/(324.5412*213.24))";
  double my_result = calculation(example, 0);
  double true_result = 13267141.74182536;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(arifmetic_test_31) {
  char *example =
      "(((12324.342/2342.234)+(342.4325*154.65))/"
      "(876.3-3451))+(2534.543*(1234.655/320.542))";
  double my_result = calculation(example, 0);
  double true_result = 9741.91379147;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_32) {
  char *example =
      "(((((4342.8675*5463)/(4231.4325-0.3245))-((44234.412/582)+1376))/"
      "(3654-((543.2*1345.5543)+0.5543)))*(5326543/(2645.658765-1654)))+(12563/"
      "((3654.576*2564)+(1342.56/23450.5)))";
  double my_result = calculation(example, 0);
  double true_result = -30.68889694;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_33) {
  char *example =
      "(((1630*(2234/54325))+((4233-4234321)*(823423/3452)))/(145+(234.2341/"
      "(356.4612-1543.3234))))*((454.3345-(3534.543/4321.5432))-(5432.3524/"
      "(2435*0.532442)))";
  double my_result = calculation(example, 0);
  double true_result = -3131029812.34034567;
  ck_assert_double_eq_tol(my_result, true_result, 1e-6);
}

START_TEST(arifmetic_test_34) {
  char *example =
      "(((26340/4634)*(6345-(3643/6341.6345)))/((5672*19786.55324)-(1234/"
      "7560.7565)))*(3423-((2432*13546.3425)+4320.524))";
  double my_result = calculation(example, 0);
  double true_result = -10586.27400295;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_35) {
  char *example =
      "324.5342*((((15365*3242)/(3654+2243))-(2347*43210.54435))*(57764/"
      "(243242-7561)))/(1432+(6542/(3654-1423654)))";
  double my_result = calculation(example, 0);
  double true_result = -5632720.32424436;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_36) {
  char *example =
      "(((65324*(2654.5645-6541))/(3654234-(2234/4345)))+(5747-(3534/"
      "561.5345)))*(5432-((6541/4230.4325)+(4232*1654.655)))";
  double my_result = calculation(example, 0);
  double true_result = -39682001894.71318113;
  ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_test_37) {
  char *example =
      "((((13428/3432)+76542)*(45432.8243-6341.2634))/((6432*5430.635)+(5431/"
      "5430.5435)))+(3457/(4323*4322))";
  double my_result = calculation(example, 0);
  double true_result = 85.66615852;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_38) {
  char *example =
      "(((967575+(744234/2352))*(4765-(3765/13234.5224)))-(4322.4325/"
      "(210423.5*3422)))*((6534.51+(321/(311-11.35423)))/(414.5234-(3.42342/"
      "35421.12355)))";
  double my_result = calculation(example, 0);
  double true_result = 72710793992.85143845;
  ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_test_39) {
  char *example =
      "((((134.52/23421)+(5324.78*1665.5342))/(423.4323-1323))+(236*(51.552354/"
      "0.5324)))/(54536/(14.142-11.4132))";
  double my_result = calculation(example, 0);
  double true_result = 0.65013492;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(arifmetic_test_40) {
  char *example =
      "((((134.52/23421)+(5324.78-1665.5342))/(423.4323-1323))+(236-(51.552354/"
      "0.5324)))/(54536/(14.142-11.4132))";
  double my_result = calculation(example, 0);
  double true_result = 0.00676005;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(trigonometric_test_1) {
  char *example = "sin(((1432.35*24.3)/(34/3+24/43-23))-sin(7324.35*0.5))";
  double my_result = calculation(example, 0);
  double true_result = 0.30830568;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_2) {
  char *example = "sin((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))";
  double my_result = calculation(example, 0);
  double true_result = 0.31591594;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_3) {
  char *example =
      "sin(0.09000012*((sin(18.435/3.432)+2.412)*(4.8324-sin(1.2432))))";
  double my_result = calculation(example, 0);
  double true_result = 0.53712999;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_4) {
  char *example = "sin(((12/2)+(5*sin(1.5)*24))/(3324.132-1.32523))";
  double my_result = calculation(example, 0);
  double true_result = 0.03782026;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_5) {
  char *example =
      "sin(325.5324*(((2.5432*3.432)/(1342.5-10.5324))-sin((44325.11123/"
      "2324.234)+1.234))/(3.234-((2.7568*1.5234)+0.5324)))";
  double my_result = calculation(example, 0);
  double true_result = 0.71414008;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_6) {
  char *example =
      "cos(((65324*(2654.5645-6541))/(3654234-(2234/4345)))+(5747-(cos(3534/"
      "561.5345))))*(5432-((6541/4230.4325)+(4232*1654.655)))";
  double my_result = calculation(example, 0);
  double true_result = 6613209.02036235;
  ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_test_7) {
  char *example =
      "cos((((13428/3432)+76542)*(45432.8243-6341.2634))/"
      "((6432*5430.635)+(5431/5430.5435)))+(3457/(4323*4322))";
  double my_result = calculation(example, 0);
  double true_result = -0.66506188;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_8) {
  char *example =
      "cos(((967575+(744234/2352))*(4765-(3765/13234.5224)))-(4322.4325/"
      "(210423.5*3422)))*((6534.51+(cos(321/(311-11.35423))))/"
      "(414.5234-(3.42342/35421.12355)))";
  double my_result = calculation(example, 0);
  double true_result = -10.32829952;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_9) {
  char *example =
      "cos((((134.52/23421)+(5324.78*1665.5342))/"
      "(423.4323-1323))+(236*(cos(51.552354/0.5324))))/(54536/"
      "(14.142-11.4132))";
  double my_result = calculation(example, 0);
  double true_result = 0.00004143;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_10) {
  char *example =
      "cos(((26340/4634)*(6345-(3643/6341.6345)))/((5672*19786.55324)-(1234/"
      "7560.7565)))*(3423-((2432*13546.3425)+4320.524))";
  double my_result = calculation(example, 0);
  double true_result = -32945600.78318327;
  ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

//  ============================================================================

START_TEST(trigonometric_test_11) {
  char *example = "tan(((sin(45)*cos(30))/2)-(tan(12.34)/(cos(2.55)-1.32)))";
  double my_result = calculation(example, 0);
  double true_result = -0.04151937;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_12) {
  char *example = "tan((sin(2.5*cos(30)))-(tan(2.34)*cos(1.23)))";
  double my_result = calculation(example, 0);
  double true_result = 0.87951986;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_13) {
  char *example =
      "tan(((sin(0.5)*cos(60))/(cos(45)+tan(30)))-(tan(15.5)/"
      "(cos(12.34)-sin(7.65))))";
  double my_result = calculation(example, 0);
  double true_result = -0.08189528;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_14) {
  char *example =
      "tan(((sin(1.5)*cos(75))/cos(0.5))-(tan(45.67)/(cos(2.55)-1.32)))";
  double my_result = calculation(example, 0);
  double true_result = 0.23308907;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_15) {
  char *example =
      "tan((sin(23)*cos(11.5))-(tan(34.12)*cos(1.23)))*asin(((6.213*(2.552-1."
      "312))/(3.321-(2.423/4.1123)))/3)*asin(((6.213*(2.552-1.312))/"
      "(3.321-(2.423/4.1123)))/3)";
  double my_result = calculation(example, 0);
  double true_result = -0.38600570;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_16) {
  char *example =
      "(((asin(0.54321)*acos(0.3245+321/1284))/acos((45.14123/124766+321/"
      "1545)*41.421/4327.34)+atan(35432.253))-(atan(154.5324)/(acos(142.34/"
      "10327)-asin(7.65/102))))";
  double my_result = calculation(example, 0);
  double true_result = 0.86614354;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_17) {
  char *example =
      "acos((asin(acos(0.2141)/123))/54.32)*(acos(0.375)/"
      "acos(0.5))-(atan(43245.67)/(acos(0.432455)-0.0032))";
  double my_result = calculation(example, 0);
  double true_result = 0.37737235;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_18) {
  char *example =
      "asin(0.123*(asin(0.999)*acos(0.9995)))+(atan(34.12)*acos(0.4323))";
  double my_result = calculation(example, 0);
  double true_result = 1.73819952;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_19) {
  char *example =
      "atan(acos(asin(1.43/1432.35*24.3)/(34/3+24/"
      "43-23))-asin(7324.35*0.00005))";
  double my_result = calculation(example, 0);
  double true_result = 0.87525383;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_20) {
  char *example = "asin(((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))/3)";
  double my_result = calculation(example, 0);
  double true_result = 1.22279719;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(trigonometric_test_21) {
  char *example =
      "asin((0.09000012*((asin(18.435/341.432)+2.412)*(4.8324-asin(1.2432/"
      "123+0.0532))))-1)";
  double my_result = calculation(example, 0);
  double true_result = 0.05848612;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_22) {
  char *example =
      "asin(((12/2)+(5*asin(1.5/123*0.00043)*24))/(3324.132-1.32523))";
  double my_result = calculation(example, 0);
  double true_result = 0.00180589;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_23) {
  char *example =
      "asin((325.5324*(((2.5432*3.432)/(1342.5-10.5324))-asin((44325.11123/"
      "233324.234)+0.00234))/(3.234-((2.7568*1.5234)+0.5324))/49.13278))";
  double my_result = calculation(example, 0);
  double true_result = 0.97352649;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_24) {
  char *example =
      "asin(((((((acos(6524*(264.5645-651)/1236345573.3245)/(365234-(234/"
      "435)))+(5747-(acos(353.4/561.535))))*(5432-((6541/"
      "4230.4325)+(422*164.655))))+atan(45.67*2*52))/(acos(2.55/"
      "100)-0.21332)))/100000/100000)";
  double my_result = calculation(example, 0);
  double true_result = -0.02763627;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_25) {
  char *example =
      "asin((((13428/3432)+76542)*(acos((45432.8243-6341.2634)/3274652.3214))/"
      "((6432*5430.635)+(5431/5430.5435)))+(3457/(4323*4322)))";
  double my_result = calculation(example, 0);
  double true_result = 0.00360114;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_26) {
  char *example = "sin(2*(cos(1.5*atan(0.75))))";
  double my_result = calculation(example, 0);
  double true_result = 0.90797254;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_27) {
  char *example =
      "tan((sin(0.5)*cos(1.5))-(tan(1.2)*cos(0.8)))*asin(0.2*((0.2*(1.5-0.8))/"
      "(3-(2/4)))/3)*asin(0.2*((2*(1.5-0.8))/(3-(2/4)))/3)";
  double my_result = calculation(example, 0);
  double true_result = 0.00073548;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_28) {
  char *example =
      "acos((asin(acos(0.5)/123))/54.32)*(acos(0.375)/"
      "acos(0.5))-(atan(0.4324567)/(acos(0.432455)-0.0032))";
  double my_result = calculation(example, 0);
  double true_result = 1.41510909;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_29) {
  char *example =
      "asin(0.123*(asin(0.999)*acos(0.9995)))+(atan(453341.2)*acos(0.4323))";
  double my_result = calculation(example, 0);
  double true_result = 1.77112297;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(trigonometric_test_30) {
  char *example =
      "atan(acos(asin(1.43/1432.35*24.3)/(34/3+24/"
      "43-23))-asin(7324.35*0.00005))";
  double my_result = calculation(example, 0);
  double true_result = 0.87525383;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(other_test_1) {
  char *example =
      "sqrt((sqrt(5233332.555)*sqrt(3876.8768))/"
      "(sqrt(107.578-0078.0785))-(sqrt((70784.78/50782.807)+sqrt(4321.67)))/"
      "(sqrt(13433.42)-((532.2253*sqrt(1523.5523))+5230.3255)))";
  double my_result = calculation(example, 0);
  double true_result = 161.94271729;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}
START_TEST(other_test_2) {
  char *example =
      "ln(sqrt((log((sqrt(5233332.555)*log(3876.8768))/"
      "(log(107.578-0078.0785))-(log((70784.78/(50782.807-ln(123.432)/"
      "ln(4762.213))+ln(4321.67)))/"
      "(ln(13433.42)-((532.2253*sqrt(1523.5523))+5230.3255)))*123456.12346))))";
  double my_result = calculation(example, 0);
  double true_result = 0.66053149;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_3) {
  char *example =
      "(log(3654234)-sqrt(4345)*log(2234)*65324*(ln(2654.5645)-ln(6541))+(5747-"
      "log(561.5345)/ln(3534)))/(5432-(sqrt(4230.4325)/"
      "sin(log(6541)+log(10)-4232*ln(1654.655))))";
  double my_result = calculation(example, 0);
  double true_result = 2347.50964106;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_4) {
  char *example = "14.36/463.32*(1.326/50-34+20/2)^2^2-2^(2)^(2)";
  double my_result = calculation(example, 0);
  double true_result = 10221.58960857;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_5) {
  char *example = "234.213 mod 35.4+57-56*(3-754 mod 33.51) mod 2";
  double my_result = calculation(example, 0);
  double true_result = 78.493;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_6) {
  char *example = "56*(3+754 mod 33.51) mod 2.5421 mod 2+2";
  double my_result = calculation(example, 0);
  double true_result = 3.8665;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_7) {
  char *example =
      "((asin(log((ln((6(((((((((((((5-6)*5)*3)*2)*5)*4)/2.421)/"
      "432)*324.12)*31.23)/4.123)+213.4325)-834.324))^2 mod 4))^6)))^5) mod "
      "0.023";
  double my_result = calculation(example, 0);
  double true_result = 0.00889416;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_8) {
  char *example = "(5*(-6)^3*sin(-241.1324)/213.4321*(-2))*(-5)";
  double my_result = calculation(example, 0);
  double true_result = 35.23404963;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_9) {
  char *example =
      "(-324.5342*((((15365*(-3242))/"
      "(3654+2243))-(-2347*(-43210.54435)))*(57764/(243242-7561)))/"
      "(-1432+(6542/(3654-1423654))))";
  double my_result = calculation(example, 0);
  double true_result = -5633622.49229791;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_10) {
  char *example =
      "(((-65324*(2654.5645-6541))/(3654234-(-2234/4345)))+(-5747-(-3534/"
      "561.5345)))*(5432-((-6541/4230.4325)+(-4232*1654.655)))";
  double my_result = calculation(example, 0);
  double true_result = -39743614292.13980964;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(other_test_11) {
  char *example =
      "((((-13428/3432)+(-76542))*(45432.8243-6341.2634))/"
      "((-6432*(-5430.635))+(-5431/(-5430.5435))))+(-3457/(4323*4322))";
  double my_result = calculation(example, 0);
  double true_result = -85.66615852;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_12) {
  char *example =
      "(((-967575+(-744234/2352))*(4765-(-3765/13234.5224)))-(-4322.4325/"
      "(210423.5*3422)))*((-6534.51+(321/(311-(-11.35423))))/"
      "(-414.5234-(-3.42342/35421.12355)))";
  double my_result = calculation(example, 0);
  double true_result = -72696476962.15221077;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_13) {
  char *example =
      "(((-134.52/23421)+(-5324.78*1665.5342))/"
      "(-423.4323-1323)+(-236*(51.552354/0.5324)))/(-54536/(-14.142-11.4132))";
  double my_result = calculation(example, 0);
  double true_result = -8.32867356;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_14) {
  char *example =
      "sin(-325.5324*(((2.5432*3.432)/(-1342.5+10.5324))-sin((-44325.11123/"
      "2324.234)-1.234))/(3.234-((-2.7568*1.5234)-0.5324))";
  double my_result = calculation(example, 0);
  double true_result = -0.49350345;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_15) {
  char *example =
      "cos(((-65324*(2654.5645-6541))/(-3654234-(-2234/"
      "4345)))+(-5747-(cos(-3534/561.5345))))*(-5432-((-6541/"
      "4230.4325)-(-4232*1654.655)))";
  double my_result = calculation(example, 0);
  double true_result = -5104898.25816558;
  ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_test_16) {
  char *example =
      "cos((((-13428/3432)-76542)*(45432.8243-6341.2634))/"
      "((-6432*(-5430.635))-(-5431/(-5430.5435))))+(-3457/(4323*4322))";
  double my_result = calculation(example, 0);
  double true_result = -0.66542827;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_17) {
  char *example =
      "cos(((-967575+(-744234/2352))*(4765-(-3765/13234.5224)))-(-4322.4325/"
      "(210423.5*3422)))*((6534.51+(cos(-321/(311-11.35423))))/"
      "(-414.5234-(-3.42342/35421.12355)))";
  double my_result = calculation(example, 0);
  double true_result = 9.93143235;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_18) {
  char *example =
      "cos(((-134.52/23421)+(-5324.78*1665.5342))/"
      "(-423.4323-1323))+(236*(cos(-51.552354/0.5324)))/(54536/"
      "(-14.142-11.4132))";
  double my_result = calculation(example, 0);
  double true_result = 0.34943122;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_19) {
  char *example =
      "sqrt(ln(asin(-0.15)/((sin(-52.11))^2^2/264.324)-26.432(-41.4723/"
      "(123.348/sqrt(45.354)))))";
  double my_result = calculation(example, 0);
  double true_result = 1.61395184;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_20) {
  char *example = "sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(2^2))^2)^2)^2)^2^2)";
  double my_result = calculation(example, 0);
  double true_result = 2;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(other_test_21) {
  char *example =
      "sin(cos(tan(atan(acos(asin(0.02*sqrt(2.56)/"
      "(ln(1.5)-log(4.321)))+0.14159)/sqrt(5.432)))))";
  double my_result = calculation(example, 0);
  double true_result = 0.70463403;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_22) {
  char *example =
      "ln((cos(1.2*atan(0.75)))/"
      "(log(5.4321*sqrt(3.14159))))+log((tan(0.5)-asin(0.25))/"
      "(ln(2.5)+sqrt(3.14)))";
  double my_result = calculation(example, 0);
  double true_result = -1.27864300;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_23) {
  char *example = "sqrt(1 + (cos(2.5) + sin(1.2))^2/(ln(0.5) + log(2.3))^2)";
  double my_result = calculation(example, 0);
  double true_result = 1.07516921;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_24) {
  char *example =
      "sin(2*(cos(1.5*atan(0.75)))*log(1+ln(2.5))/(sqrt(2.5)+log(3.14)))";
  double my_result = calculation(example, 0);
  double true_result = 0.15412291;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_25) {
  char *example =
      "ln(log(2.5)*cos(0.5)/(sin(1.2) + tan(0.75))) - "
      "sqrt(ln(-2.5*log(0.75)/ln(1.2)))";
  double my_result = calculation(example, 0);
  double true_result = -2.40828557;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_26) {
  char *example = "0.543(ln(cos(1.5*atan(0.75)) + log(5.4321*sqrt(3.14159))))";
  double my_result = calculation(example, 0);
  double true_result = 0.23893583;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_27) {
  char *example =
      "523(sin(2*(cos(1.5*atan(0.75)))*log(1+ln(2.5))/(sqrt(2.5)+log(3.14))))";
  double my_result = calculation(example, 0);
  double true_result = 80.60628465;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_28) {
  char *example =
      "342(acos((asin(acos(0.5)/123))/54.32)*(acos(0.375)/"
      "acos(0.5))-(atan(43245.67)/(acos(0.432455)-0.0032)))";
  double my_result = calculation(example, 0);
  double true_result = 129.07919834;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_29) {
  char *example =
      "6(((ln(cos(1.5*atan(0.75)))/"
      "(log(5.4321*sqrt(3.14159))))+log((tan(0.5)-asin(0.25))/"
      "(ln(2.5)+sqrt(3.14)))))";
  double my_result = calculation(example, 0);
  double true_result = -9.20773786;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_30) {
  char *example =
      "5.345 mod 7/(sqrt(1 + (cos(2.5) + sin(1.2))^2/(ln(0.5) + log(2.3))^2))";
  double my_result = calculation(example, 0);
  double true_result = 4.97131049;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(other_test_31) {
  char *example = "sqrt(sin(P/2.1324) + cos(3.123P))/2.53";
  double my_result = calculation(example, 0);
  double true_result = 0.10381191;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_32) {
  char *example = "log(2.5e-3) * ln(1000) / P";
  double my_result = calculation(example, 0);
  double true_result = -5.72142719;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_33) {
  char *example = "sqrt(2.234*P^2) + log(34e4) - ln(134e-5)";
  double my_result = calculation(example, 0);
  double true_result = 16.84216850;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_34) {
  char *example = "(2/45*5432e3 * (P/3.14)) + log(123e3 * 123 e-4)";
  double my_result = calculation(example, 0);
  double true_result = 241547.85488877;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_35) {
  char *example = "(1+P*P*P-P^3)^3 -1";
  double my_result = calculation(example, 0);
  double true_result = 0.0;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_36) {
  char *example =
      "x(((ln(cos(1.5*atan(1)))/(log(x*sqrt(x))))+log((tan(1)-asin(0.25))/"
      "(ln(x)+sqrt(x)))))";
  double my_result = calculation(example, 50);
  double true_result = -65.10591505;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_37) {
  char *example = "sqrt(x*x*xx*x*x)x";
  double my_result = calculation(example, 1.51);
  double true_result = 5.19885601;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_38) {
  char *example = "log(((sqrt(x*x*xx*x*x)x)^2/1.25566*15.2333)/x^2)";
  double my_result = calculation(example, -13.123);
  double true_result = 7.79212070;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_39) {
  char *example =
      "log(((sqrt(sqrt(x*x*xx*x*x)x)/(ln(42)*5.123))^2/1.25566*15.2333)/x^2)";
  double my_result = calculation(example, 23.213);
  double true_result = 1.25113394;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_40) {
  char *example =
      "e * e - "
      "(log(3654234)-sqrt(4345)*log(2234)*65324*(ln(2654.5645)-ln(6541))+(5747-"
      "log(561.5345)/ln(3534)))/(5432-(sqrt(4230.4325)/"
      "sin(log(6541)+log(10)-4232*ln(1654.655))))";
  double my_result = calculation(example, 0);
  double true_result = -2340.12058496;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(other_test_41) {
  char *example = "eeeeeee";
  double my_result = calculation(example, 0);
  double true_result = 1096.63315842;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_42) {
  char *example = "eePeePeee";
  double my_result = calculation(example, 0);
  double true_result = 10823.33544680;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_43) {
  char *example = "eePeePeee314/(P212)";
  double my_result = calculation(example, 0);
  double true_result = 5102.75871556;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_44) {
  char *example = "5";
  double my_result = calculation(example, 0);
  double true_result = 5;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_45) {
  char *example = "sqrt(e*P*34.123x*1.11*5.22)x";
  double my_result = calculation(example, 2);
  double true_result = 116.22177789;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_46) {
  char *example = "sin(cos(tan(sin(cos(tan(5.112))))))";
  double my_result = calculation(example, 50);
  double true_result = 0.65811820;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_47) {
  char *example =
      "sqrt(sqrt(sqrt(2.33)/sqrt(2.1324)) + sqrt(sqrt(3.123P)))/sqrt(2.53)";
  double my_result = calculation(example, 0);
  double true_result = 1.05054622;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_48) {
  char *example =
      "tan(cos(sin(tan(cos(sin(tan(cos(sin(sqrt(ln(100000000))))))))))";
  double my_result = calculation(example, 0);
  double true_result = 0.76870729;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_49) {
  char *example =
      "ln(log(2.5)*cos(0.5)/"
      "(523(sin(2*(cos(1.5*atan(0.75)))*log(1+ln(2.5))))))";
  double my_result = calculation(example, 0);
  double true_result = -6.15975441;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(other_test_50) {
  char *example =
      "((((-138/32)+(-76542))*(452.83-61.24))/((-32*(-540.65))+(-5431/"
      "(-5430.5435))))+(-3457/(4323*4322))/(((-967575+(-744234/"
      "2352))*(4765-(-375/134.54)))-(-42.45/(210423.5*3422)))*((-6534.51+(321/"
      "(311-(-11.35423))))/(-414.5234-(-3.42342/35421.12355)))";
  double my_result = calculation(example, 0);
  double true_result = -1732.46542939;
  s21_test_print(example, my_result, true_result);
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(wrong_expression_1) {
  double my_result = calculation(NULL, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_2) {
  char *example = "log(((sqrt(x*x*xx*x*x)x)^2/1.25566*15.2333)z/x^2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_3) {
  char *example = "log(((sqt(x*x*xx*x*x)x)^2/1.25566*15.2333)/x^2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_4) {
  char *example = "2 mid (2/45*5432e3 * (P/3.14)) + log(123e3 * 123 e-4)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_5) {
  char *example = "x + y";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_6) {
  char *example = "x_mod_2";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_7) {
  char *example =
      "san(2*(cos(1.5*atan(0.75)))*lg(1+ln(2.5))/(sqrt(2.5)+log(3.14)))";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_8) {
  char *example = "324.2 mod 33.324 mod 54.432 modd 6.532";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_9) {
  char *example = "sin(1^2^z)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_10) {
  char *example = "sqtr(sin(2^2^3))";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

START_TEST(wrong_expression_11) {
  char *example = "";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_12) {
  char *example = "sqrt(sin(2^2^3))*sin(4)/s";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_13) {
  char *example = "sqrt(sin(2^2^3))*sin(4)/sin";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_14) {
  char *example = "qrt(sin(2^2^3))*sin(4)/sin(1)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_15) {
  char *example = "srt(sin(2^2^3))*sin(4)/sin(2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_16) {
  char *example = "sqrt(in(2^2^3))*sin(4)/sin(2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_17) {
  char *example = "sqrt(sin(2^2^3))*os(4)/sin(2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_18) {
  char *example = "og(sin(2^2^3))*cos(4)/sin(2)";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_19) {
  char *example =
      "sin(2*(cos(1.5*atan(0.75)))*n(1+ln(2.5))/(sqrt(2.5)+log(3.14)))";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

START_TEST(wrong_expression_20) {
  char *example =
      "sin(2*(cos(1.5*taan(0.75)))*ln(1+ln(2.5))/(sqrt(2.5)+log(3.14)))";
  double my_result = calculation(example, 0);
  double true_result = __DBL_MAX__;
  ck_assert_double_eq_tol(my_result, true_result, 1e-7);
}

//  ============================================================================

Suite *arifmetic_1(void) {
  Suite *calc = suite_create("smartcalc (easy expressions)\n");

  TCase *tc_test_arifmetic_1 = tcase_create("\ntest_arifmetic");
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_1);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_2);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_3);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_4);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_5);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_6);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_7);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_8);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_9);
  tcase_add_test(tc_test_arifmetic_1, arifmetic_test_10);
  suite_add_tcase(calc, tc_test_arifmetic_1);

  return calc;
}

Suite *arifmetic_2(void) {
  Suite *calc = suite_create("smartcalc (arifmetic medium expressions)\n");

  TCase *tc_test_arifmetic_2 = tcase_create("\ntest_arifmetic");
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_11);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_12);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_13);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_14);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_15);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_16);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_17);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_18);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_19);
  tcase_add_test(tc_test_arifmetic_2, arifmetic_test_20);
  suite_add_tcase(calc, tc_test_arifmetic_2);

  return calc;
}

Suite *arifmetic_3(void) {
  Suite *calc = suite_create("smartcalc (arifmetic hard expressions)\n");

  TCase *tc_test_arifmetic_3 = tcase_create("\ntest_arifmetic");
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_21);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_22);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_23);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_24);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_25);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_26);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_27);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_28);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_29);
  tcase_add_test(tc_test_arifmetic_3, arifmetic_test_30);
  suite_add_tcase(calc, tc_test_arifmetic_3);

  return calc;
}

Suite *arifmetic_4(void) {
  Suite *calc = suite_create("smartcalc (arifmetic too hard expressions)\n");

  TCase *tc_test_arifmetic_4 = tcase_create("\ntest_arifmetic");
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_31);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_32);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_33);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_34);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_35);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_36);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_37);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_38);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_39);
  tcase_add_test(tc_test_arifmetic_4, arifmetic_test_40);
  suite_add_tcase(calc, tc_test_arifmetic_4);

  return calc;
}

Suite *trigonometric_1(void) {
  Suite *calc = suite_create("smartcalc (trigonometric medium expressions)\n");

  TCase *tc_test_trigonometric_1 = tcase_create("\ntest_trigonometric");
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_1);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_2);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_3);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_4);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_5);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_6);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_7);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_8);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_9);
  tcase_add_test(tc_test_trigonometric_1, trigonometric_test_10);
  suite_add_tcase(calc, tc_test_trigonometric_1);

  return calc;
}

Suite *trigonometric_2(void) {
  Suite *calc = suite_create("smartcalc (trigonometric hard expressions)\n");

  TCase *tc_test_trigonometric_2 = tcase_create("\ntest_trigonometric");
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_11);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_12);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_13);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_14);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_15);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_16);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_17);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_18);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_19);
  tcase_add_test(tc_test_trigonometric_2, trigonometric_test_20);
  suite_add_tcase(calc, tc_test_trigonometric_2);

  return calc;
}

Suite *trigonometric_3(void) {
  Suite *calc =
      suite_create("smartcalc (trigonometric too hard expressions)\n");

  TCase *tc_test_trigonometric_3 = tcase_create("\ntest_trigonometric");
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_21);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_22);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_23);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_24);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_25);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_26);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_27);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_28);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_29);
  tcase_add_test(tc_test_trigonometric_3, trigonometric_test_30);
  suite_add_tcase(calc, tc_test_trigonometric_3);

  return calc;
}

Suite *other_1(void) {
  Suite *calc = suite_create("smartcalc (other hardest expressions)\n");

  TCase *tc_test_other_1 = tcase_create("\ntest_other");
  tcase_add_test(tc_test_other_1, other_test_1);
  tcase_add_test(tc_test_other_1, other_test_2);
  tcase_add_test(tc_test_other_1, other_test_3);
  tcase_add_test(tc_test_other_1, other_test_4);
  tcase_add_test(tc_test_other_1, other_test_5);
  tcase_add_test(tc_test_other_1, other_test_6);
  tcase_add_test(tc_test_other_1, other_test_7);
  tcase_add_test(tc_test_other_1, other_test_8);
  tcase_add_test(tc_test_other_1, other_test_9);
  tcase_add_test(tc_test_other_1, other_test_10);
  suite_add_tcase(calc, tc_test_other_1);

  return calc;
}

Suite *other_2(void) {
  Suite *calc = suite_create("smartcalc (other hardest unusual expressions)\n");

  TCase *tc_test_other_2 = tcase_create("\ntest_other");
  tcase_add_test(tc_test_other_2, other_test_11);
  tcase_add_test(tc_test_other_2, other_test_12);
  tcase_add_test(tc_test_other_2, other_test_13);
  tcase_add_test(tc_test_other_2, other_test_14);
  tcase_add_test(tc_test_other_2, other_test_15);
  tcase_add_test(tc_test_other_2, other_test_16);
  tcase_add_test(tc_test_other_2, other_test_17);
  tcase_add_test(tc_test_other_2, other_test_18);
  tcase_add_test(tc_test_other_2, other_test_19);
  tcase_add_test(tc_test_other_2, other_test_20);
  suite_add_tcase(calc, tc_test_other_2);

  return calc;
}

Suite *other_3(void) {
  Suite *calc = suite_create("smartcalc (other hard unusual expressions)\n");

  TCase *tc_test_other_3 = tcase_create("\ntest_other");
  tcase_add_test(tc_test_other_3, other_test_21);
  tcase_add_test(tc_test_other_3, other_test_22);
  tcase_add_test(tc_test_other_3, other_test_23);
  tcase_add_test(tc_test_other_3, other_test_24);
  tcase_add_test(tc_test_other_3, other_test_25);
  tcase_add_test(tc_test_other_3, other_test_26);
  tcase_add_test(tc_test_other_3, other_test_27);
  tcase_add_test(tc_test_other_3, other_test_28);
  tcase_add_test(tc_test_other_3, other_test_29);
  tcase_add_test(tc_test_other_3, other_test_30);
  suite_add_tcase(calc, tc_test_other_3);

  return calc;
}

Suite *other_4(void) {
  Suite *calc = suite_create("smartcalc (other medium unusual expressions)\n");

  TCase *tc_test_other_4 = tcase_create("\ntest_other");
  tcase_add_test(tc_test_other_4, other_test_31);
  tcase_add_test(tc_test_other_4, other_test_32);
  tcase_add_test(tc_test_other_4, other_test_33);
  tcase_add_test(tc_test_other_4, other_test_34);
  tcase_add_test(tc_test_other_4, other_test_35);
  tcase_add_test(tc_test_other_4, other_test_36);
  tcase_add_test(tc_test_other_4, other_test_37);
  tcase_add_test(tc_test_other_4, other_test_38);
  tcase_add_test(tc_test_other_4, other_test_39);
  tcase_add_test(tc_test_other_4, other_test_40);
  suite_add_tcase(calc, tc_test_other_4);

  return calc;
}

Suite *other_5(void) {
  Suite *calc = suite_create("smartcalc (other easy unusual expressions)\n");

  TCase *tc_test_other_5 = tcase_create("\ntest_other");
  tcase_add_test(tc_test_other_5, other_test_41);
  tcase_add_test(tc_test_other_5, other_test_42);
  tcase_add_test(tc_test_other_5, other_test_43);
  tcase_add_test(tc_test_other_5, other_test_44);
  tcase_add_test(tc_test_other_5, other_test_45);
  tcase_add_test(tc_test_other_5, other_test_46);
  tcase_add_test(tc_test_other_5, other_test_47);
  tcase_add_test(tc_test_other_5, other_test_48);
  tcase_add_test(tc_test_other_5, other_test_49);
  tcase_add_test(tc_test_other_5, other_test_50);
  suite_add_tcase(calc, tc_test_other_5);

  return calc;
}

Suite *wrong_expressions_1(void) {
  Suite *calc = suite_create("smartcalc (wrong experssions first cases)\n");

  TCase *tc_expressions_1 = tcase_create("\ntest_expressions");
  tcase_add_test(tc_expressions_1, wrong_expression_1);
  tcase_add_test(tc_expressions_1, wrong_expression_2);
  tcase_add_test(tc_expressions_1, wrong_expression_3);
  tcase_add_test(tc_expressions_1, wrong_expression_4);
  tcase_add_test(tc_expressions_1, wrong_expression_5);
  tcase_add_test(tc_expressions_1, wrong_expression_6);
  tcase_add_test(tc_expressions_1, wrong_expression_7);
  tcase_add_test(tc_expressions_1, wrong_expression_8);
  tcase_add_test(tc_expressions_1, wrong_expression_9);
  tcase_add_test(tc_expressions_1, wrong_expression_10);
  suite_add_tcase(calc, tc_expressions_1);

  return calc;
}

Suite *wrong_expressions_2(void) {
  Suite *calc = suite_create("smartcalc (wrong experssions second cases)\n");

  TCase *tc_expressions_2 = tcase_create("\ntest_expressions");
  tcase_add_test(tc_expressions_2, wrong_expression_11);
  tcase_add_test(tc_expressions_2, wrong_expression_12);
  tcase_add_test(tc_expressions_2, wrong_expression_13);
  tcase_add_test(tc_expressions_2, wrong_expression_14);
  tcase_add_test(tc_expressions_2, wrong_expression_15);
  tcase_add_test(tc_expressions_2, wrong_expression_16);
  tcase_add_test(tc_expressions_2, wrong_expression_17);
  tcase_add_test(tc_expressions_2, wrong_expression_18);
  tcase_add_test(tc_expressions_2, wrong_expression_19);
  tcase_add_test(tc_expressions_2, wrong_expression_20);
  suite_add_tcase(calc, tc_expressions_2);

  return calc;
}

/**
 * @brief Function for printing the obtained results.
 *
 * @param[in] expression mathematical expression.
 * @param[in] my_result result of calculating the implementation function.
 * @param[in] true_result result of calculating the original result.
 */
static void s21_test_print(char *expression, double my_result,
                           double true_result) {
  printf("expression: %s\n\n", expression);
  printf("mysmartcalc = %lf\n", my_result);
  printf("true result = %lf\n", true_result);
  printf(
      "\033[0;33m--------------------------------------------------------------"
      "--------------------------\033[0m\n");
}