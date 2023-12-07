#include "../main.h"
#include <check.h>

START_TEST(arifmetic_1) {
    char *example = "(((1.123*213.5555-((217.12354))*1/2)/4/6*(5632.57-123.344)/(23.12346)/(4.213*(((653.13*(14.123*121.2345+2/(23.123+9*0.213))))/((237.12*21.8888))/(1.888+92.14)))))";
    double my_result = calculation(example, 0);
    double true_result = 134.9724794;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_2) {
    char *example = "((2*3)-(4/2))";
    double my_result = calculation(example, 0);
    double true_result = 4;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_3) {
    char *example = "324.14*(10+5)/(2*3)";
    double my_result = calculation(example, 0);
    double true_result = 810.35;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_4) {
    char *example = "(((1.5*2)/3)-((4-2)*1))";
    double my_result = calculation(example, 0);
    double true_result = -1;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_5) {
    char *example = "((6/2)+(4*2))";
    double my_result = calculation(example, 0);
    double true_result = 11;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_6) {
    char *example = "((8-2)*(3+1))/4";
    double my_result = calculation(example, 0);
    double true_result = 6;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_7) {
    char *example = "0.04230*(((12/3)*2)-5)";
    double my_result = calculation(example, 0);
    double true_result = 0.1269;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_8) {
    char *example = "(((2.5*3)/(1.5-0.5))-((4/2)+1))";
    double my_result = calculation(example, 0);
    double true_result = 4.5;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_9) {
    char *example = "((10*(2/5))+((3-1)*(8/2)))";
    double my_result = calculation(example, 0);
    double true_result = 12;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_10) {
    char *example = "((20/4)(5-(3/1.5)))";
    double my_result = calculation(example, 0);
    double true_result = 15;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_11) {
    char *example = "(((15*2)/(3+2))-(7*0.5)) - (+2)";
    double my_result = calculation(example, 0);
    double true_result = 0.5;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_12) {
    char *example = "-1*((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))";
    double my_result = calculation(example, 0);
    double true_result = -2.8201707;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_13) {
    char *example = "0.09000012*(((18.435/3.432)+2.412)*(4.8324-1.2432))";
    double my_result = calculation(example, 0);
    double true_result = 2.5142929;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_14) {
    char *example = "((9.756+(7/2.756))*(4.253-(3.142/1.523)))";
    double my_result = calculation(example, 0);
    double true_result = 26.9276375;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_15) {
    char *example = "(((12/2)+(5*1.5))/(3-1))";
    double my_result = calculation(example, 0);
    double true_result = 6.75;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_16) {
    char *example = "325.5324*(((2.5432*3.432)/(1342.5-10.5324))-((44325.11123/2324.234)+1.234))/(3.234-((2.7568*1.5234)+0.5324))";
    double my_result = calculation(example, 0);
    double true_result = 4410.7283872;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_17) {
    char *example = "((10.00032*(223.21/5.214))+((23.53-1.321)*(2123.8/2.5326)))/(1.3412+(2123.52/(3321.234-1.41142)))";
    double my_result = calculation(example, 0);
    double true_result = 9618.2220848;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_18) {
    char *example = "((2.2340/43.541)*(5.1325-(3.3214/14.5231)))/((31.22*31.5321)-(141.52/103.5324))";
    double my_result = calculation(example, 0);
    double true_result = 0.0002559;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_19) {
    char *example = "(((132.5*232.4)/(34.32+423.2))-(74.32*30.5432))*(432.4/(243.24-14.52))";
    double my_result = calculation(example, 0);
    double true_result = -4164.1875583;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_20) {
    char *example = "((64.57*(2774.5-165.445))/(353.4678-(276.9354/43.456)))+(57.65-(323.5/1.3425))";
    double my_result = calculation(example, 0);
    double true_result = 302.0435041;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_21) {
    char *example = "(((189.67/423.3)+2.34)*(46.34/6.348-1634.2))/((25.343*0.63465)+(54.371/50543.55))";
    double my_result = calculation(example, 0);
    double true_result = -281.9966313;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_22) {
    char *example = "235-((953.26+(763.24/432.432))*(45.66-(39.78/1978.995)))-(9792.995/(9780.5978*2789.5234))";
    double my_result = calculation(example, 0);
    double true_result = -43352.2445327;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_23) {
    char *example = "634*(((1234.45232/2.2354)+(5123.324*1241.2355))/(235.553-142.71))+(2346.26*(1423.525/10432.3255))";
    double my_result = calculation(example, 0);
    double true_result = 43429718.6498388;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_24) {
    char *example = "(((5232.555*3876.8768)/(107.578-0078.0785))-((70784.78/50782.807)+4321.67))/(13.42-((532.2253*1523.5523)+5230.3255))";
    double my_result = calculation(example, 0);
    double true_result = -0.8373447;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_25) {
    char *example = "((137610.432*(2234.532/5.643))+((34.23423-521.42365)*(5238.523/62.325)))/(4571.2345+(252.253/(5233.523-1523.745)))";
    double my_result = calculation(example, 0);
    double true_result = 11911.3624497;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_26) {
    char *example = "328*(253*(203.41/44.32)*(5.3214-(142.3/1532.5532)))/((25.23*4231.53254)-(11.2/4350.5325))";
    double my_result = calculation(example, 0);
    double true_result = 18.6523313;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_27) {
    char *example = "(((1432.22345*532.652)/(3.324234+423.4322))-(741.4132*0.5432))*(4324.234/(232.1234-1324.325))";
    double my_result = calculation(example, 0);
    double true_result = -5483.0053878;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_28) {
    char *example = "34*((631543.151*(253154.124-1532.12521))/(3235.124353-(2532.1241/452.432)))+(535.21354-(32314.123/15342.342))";
    double my_result = calculation(example, 0);
    double true_result = 1672983604.3376084;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_29) {
    char *example = "((18235.352/3.5322)+2325/1214.41)*(434.8-321.3252)";
    double my_result = calculation(example, 0);
    double true_result = 586042.7741192;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_30) {
    char *example = "0.321*((9324.235+(5432.7/3254.662))*(4432.11-(423.143/1423.3245)))-(25324.5111/(324.5412*213.24))";
    double my_result = calculation(example, 0);
    double true_result = 13267141.7418253;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_31) {
    char *example = "(((12324.342/2342.234)+(342.4325*154.65))/(876.3-3451))+(2534.543*(1234.655/320.542))";
    double my_result = calculation(example, 0);
    double true_result = 9741.9137914;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_32) {
    char *example = "(((((4342.8675*5463)/(4231.4325-0.3245))-((44234.412/582)+1376))/(3654-((543.2*1345.5543)+0.5543)))*(5326543/(2645.658765-1654)))+(12563/((3654.576*2564)+(1342.56/23450.5)))";
    double my_result = calculation(example, 0);
    double true_result = -30.6888969;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_33) {
    char *example = "(((1630*(2234/54325))+((4233-4234321)*(823423/3452)))/(145+(234.2341/(356.4612-1543.3234))))*((454.3345-(3534.543/4321.5432))-(5432.3524/(2435*0.532442)))";
    double my_result = calculation(example, 0);
    double true_result = -3131029812.3403456;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_34) {
    char *example = "(((26340/4634)*(6345-(3643/6341.6345)))/((5672*19786.55324)-(1234/7560.7565)))*(3423-((2432*13546.3425)+4320.524))";
    double my_result = calculation(example, 0);
    double true_result = -10586.2740029;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_35) {
    char *example = "324.5342*((((15365*3242)/(3654+2243))-(2347*43210.54435))*(57764/(243242-7561)))/(1432+(6542/(3654-1423654)))";
    double my_result = calculation(example, 0);
    double true_result = -5632720.3242443;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_36) {
    char *example = "(((65324*(2654.5645-6541))/(3654234-(2234/4345)))+(5747-(3534/561.5345)))*(5432-((6541/4230.4325)+(4232*1654.655)))";
    double my_result = calculation(example, 0);
    double true_result = -39682001894.7131811;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_37) {
    char *example = "((((13428/3432)+76542)*(45432.8243-6341.2634))/((6432*5430.635)+(5431/5430.5435)))+(3457/(4323*4322))";
    double my_result = calculation(example, 0);
    double true_result = 85.6661585;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_38) {
    char *example = "(((967575+(744234/2352))*(4765-(3765/13234.5224)))-(4322.4325/(210423.5*3422)))*((6534.51+(321/(311-11.35423)))/(414.5234-(3.42342/35421.12355)))";
    double my_result = calculation(example, 0);
    double true_result = 72710793992.8514384;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_39) {
    char *example = "((((134.52/23421)+(5324.78*1665.5342))/(423.4323-1323))+(236*(51.552354/0.5324)))/(54536/(14.142-11.4132))";
    double my_result = calculation(example, 0);
    double true_result = 0.6501349;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(arifmetic_40) {
    char *example = "((((134.52/23421)+(5324.78-1665.5342))/(423.4323-1323))+(236-(51.552354/0.5324)))/(54536/(14.142-11.4132))";
    double my_result = calculation(example, 0);
    double true_result = 0.0067600;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_1) {
    char *example = "sin(((1432.35*24.3)/(34/3+24/43-23))-sin(7324.35*0.5))";
    double my_result = calculation(example, 0);
    double true_result = 0.3083056;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_2) {
    char *example = "sin((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))";
    double my_result = calculation(example, 0);
    double true_result = 0.3159159;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_3) {
    char *example = "sin(0.09000012*((sin(18.435/3.432)+2.412)*(4.8324-sin(1.2432))))";
    double my_result = calculation(example, 0);
    double true_result = 0.5371299;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_4) {
    char *example = "sin(((12/2)+(5*sin(1.5)*24))/(3324.132-1.32523))";
    double my_result = calculation(example, 0);
    double true_result = 0.0378202;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_5) {
    char *example = "sin(325.5324*(((2.5432*3.432)/(1342.5-10.5324))-sin((44325.11123/2324.234)+1.234))/(3.234-((2.7568*1.5234)+0.5324))";
    double my_result = calculation(example, 0);
    double true_result = 0.7141400;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}


START_TEST(trigonometric_6) {
    char *example = "cos(((65324*(2654.5645-6541))/(3654234-(2234/4345)))+(5747-(cos(3534/561.5345))))*(5432-((6541/4230.4325)+(4232*1654.655)))";
    double my_result = calculation(example, 0);
    double true_result = 6613209.0203623;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_7) {
    char *example = "cos((((13428/3432)+76542)*(45432.8243-6341.2634))/((6432*5430.635)+(5431/5430.5435)))+(3457/(4323*4322))";
    double my_result = calculation(example, 0);
    double true_result = -0.6650618;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_8) {
    char *example = "cos(((967575+(744234/2352))*(4765-(3765/13234.5224)))-(4322.4325/(210423.5*3422)))*((6534.51+(cos(321/(311-11.35423))))/(414.5234-(3.42342/35421.12355)))";
    double my_result = calculation(example, 0);
    double true_result = -10.3282995;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_9) {
    char *example = "cos((((134.52/23421)+(5324.78*1665.5342))/(423.4323-1323))+(236*(cos(51.552354/0.5324))))/(54536/(14.142-11.4132))";
    double my_result = calculation(example, 0);
    double true_result = 0.0000414;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_10) {
    char *example = "cos(((26340/4634)*(6345-(3643/6341.6345)))/((5672*19786.55324)-(1234/7560.7565)))*(3423-((2432*13546.3425)+4320.524))";
    double my_result = calculation(example, 0);
    double true_result = -32945600.7831832;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_11) {
    char *example = "tan(((sin(45)*cos(30))/2)-(tan(12.34)/(cos(2.55)-1.32)))";
    double my_result = calculation(example, 0);
    double true_result = -0.0415193;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_12) {
    char *example = "tan((sin(2.5*cos(30)))-(tan(2.34)*cos(1.23)))";
    double my_result = calculation(example, 0);
    double true_result = 0.8795198;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_13) {
    char *example = "tan(((sin(0.5)*cos(60))/(cos(45)+tan(30)))-(tan(15.5)/(cos(12.34)-sin(7.65))))";
    double my_result = calculation(example, 0);
    double true_result = -0.0818952;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_14) {
    char *example = "tan(((sin(1.5)*cos(75))/cos(0.5))-(tan(45.67)/(cos(2.55)-1.32)))";
    double my_result = calculation(example, 0);
    double true_result = 0.2330890;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_15) {
    char *example = "tan((sin(23)*cos(11.5))-(tan(34.12)*cos(1.23)))*asin(((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))/3)*asin(((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))/3)";
    double my_result = calculation(example, 0);
    double true_result = -0.3860057;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_16) {
    char *example = "(((asin(0.54321)*acos(0.3245+321/1284))/acos((45.14123/124766+321/1545)*41.421/4327.34)+atan(35432.253))-(atan(154.5324)/(acos(142.34/10327)-asin(7.65/102))))";
    double my_result = calculation(example, 0);
    double true_result = 0.8661435;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_17) {
    char *example = "acos((asin(acos(0.2141)/123))/54.32)*(acos(0.375)/acos(0.5))-(atan(43245.67)/(acos(0.432455)-0.0032))";
    double my_result = calculation(example, 0);
    double true_result = 0.3773723;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_18) {
    char *example = "asin(0.123*(asin(0.999)*acos(0.9995)))+(atan(34.12)*acos(0.4323))";
    double my_result = calculation(example, 0);
    double true_result = 1.7381995;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_19) {
    char *example = "atan(acos(asin(1.43/1432.35*24.3)/(34/3+24/43-23))-asin(7324.35*0.00005))";
    double my_result = calculation(example, 0);
    double true_result = 0.8752538;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_20) {
    char *example = "asin(((6.213*(2.552-1.312))/(3.321-(2.423/4.1123)))/3)";
    double my_result = calculation(example, 0);
    double true_result = 1.2227971;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_21) {
    char *example = "asin((0.09000012*((asin(18.435/341.432)+2.412)*(4.8324-asin(1.2432/123+0.0532))))-1)";
    double my_result = calculation(example, 0);
    double true_result = 0.0584861;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_22) {
    char *example = "asin(((12/2)+(5*asin(1.5/123*0.00043)*24))/(3324.132-1.32523))";
    double my_result = calculation(example, 0);
    double true_result = 0.0018058;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_23) {
    char *example = "asin((325.5324*(((2.5432*3.432)/(1342.5-10.5324))-asin((44325.11123/233324.234)+0.00234))/(3.234-((2.7568*1.5234)+0.5324))/49.13278)";
    double my_result = calculation(example, 0);
    double true_result = 0.9735264;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_24) {
    char *example = "asin(((((((acos(6524*(264.5645-651)/1236345573.3245)/(365234-(234/435)))+(5747-(acos(353.4/561.535))))*(5432-((6541/4230.4325)+(422*164.655))))+atan(45.67*2*52))/(acos(2.55/100)-0.21332)))/100000/100000)";
    double my_result = calculation(example, 0);
    double true_result = -0.027636;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_25) {
    char *example = "asin((((13428/3432)+76542)*(acos((45432.8243-6341.2634)/3274652.3214))/((6432*5430.635)+(5431/5430.5435)))+(3457/(4323*4322)))";
    double my_result = calculation(example, 0);
    double true_result = 0.0036011;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_26) {
    char *example = "sin(2*(cos(1.5*atan(0.75))))";
    double my_result = calculation(example, 0);
    double true_result = 0.9079725;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_27) {
    char *example = "tan((sin(0.5)*cos(1.5))-(tan(1.2)*cos(0.8)))*asin(0.2*((0.2*(1.5-0.8))/(3-(2/4)))/3)*asin(0.2*((2*(1.5-0.8))/(3-(2/4)))/3)";
    double my_result = calculation(example, 0);
    double true_result = 0.0007354;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_28) {
    char *example = "acos((asin(acos(0.5)/123))/54.32)*(acos(0.375)/acos(0.5))-(atan(0.4324567)/(acos(0.432455)-0.0032))";
    double my_result = calculation(example, 0);
    double true_result = 1.4151090;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_29) {
    char *example = "asin(0.123*(asin(0.999)*acos(0.9995)))+(atan(453341.2)*acos(0.4323))";
    double my_result = calculation(example, 0);
    double true_result = 1.7711229;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(trigonometric_30) {
    char *example = "atan(acos(asin(1.43/1432.35*24.3)/(34/3+24/43-23))-asin(7324.35*0.00005))";
    double my_result = calculation(example, 0);
    double true_result = 0.8752538;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_1) {
    char *example = "sqrt((sqrt(5233332.555)*sqrt(3876.8768))/(sqrt(107.578-0078.0785))-(sqrt((70784.78/50782.807)+sqrt(4321.67)))/(sqrt(13433.42)-((532.2253*sqrt(1523.5523))+5230.3255))";
    double my_result = calculation(example, 0);
    double true_result = 161.9427172;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}
START_TEST(other_2) {
    char *example = "ln(sqrt((log((sqrt(5233332.555)*log(3876.8768))/(log(107.578-0078.0785))-(log((70784.78/(50782.807-ln(123.432)/ln(4762.213))+ln(4321.67)))/(ln(13433.42)-((532.2253*sqrt(1523.5523))+5230.3255)))*123456.12346))";
    double my_result = calculation(example, 0);
    double true_result = 0.6605314;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_3) {
    char *example = "(log(3654234)-sqrt(4345)*log(2234)*65324*(ln(2654.5645)-ln(6541))+(5747-log(561.5345)/ln(3534)))/(5432-(sqrt(4230.4325)/sin(log(6541)+log(10)-4232*ln(1654.655))))";
    double my_result = calculation(example, 0);
    double true_result = 2347.5096410;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_4) {
    char *example = "14.36/463.32*(1.326/50-34+20/2)^2^2-2^(2)^(2)";
    double my_result = calculation(example, 0);
    double true_result = 10221.5896085;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_5) {
    char *example = "234.213m35.4+57-56*(3-754m33.51)m2";
    double my_result = calculation(example, 0);
    double true_result = 66.493;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_6) {
    char *example = "56*(3+754m33.51)m2.5421m2+2";
    double my_result = calculation(example, 0);
    double true_result = 16.8064;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_7) {
    char *example = "((asin(log((ln((6(((((((((((((5-6)*5)*3)*2)*5)*4)/2.421)/432)*324.12)*31.23)/4.123)+213.4325)-834.324))^2 mod 4))^6)))^5) mod 0.023";
    double my_result = calculation(example, 0);
    double true_result = 0.0088941;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_8) {
    char *example = "(5*(-6)^3*sin(-241.1324)/213.4321*(-2))*(-5)";
    double my_result = calculation(example, 0);
    double true_result = 35.2340496;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_9) {
    char *example = "(-324.5342*((((15365*(-3242))/(3654+2243))-(-2347*(-43210.54435)))*(57764/(243242-7561)))/(-1432+(6542/(3654-1423654))))";
    double my_result = calculation(example, 0);
    double true_result = -5633622.4922979;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_10) {
    char *example = "(((-65324*(2654.5645-6541))/(3654234-(-2234/4345)))+(-5747-(-3534/561.5345)))*(5432-((-6541/4230.4325)+(-4232*1654.655)))";
    double my_result = calculation(example, 0);
    double true_result = -39743614292.1398096;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_11) {
    char *example = "((((-13428/3432)+(-76542))*(45432.8243-6341.2634))/((-6432*(-5430.635))+(-5431/(-5430.5435))))+(-3457/(4323*4322))";
    double my_result = calculation(example, 0);
    double true_result = -85.6661585;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_12) {
    char *example = "(((-967575+(-744234/2352))*(4765-(-3765/13234.5224)))-(-4322.4325/(210423.5*3422)))*((-6534.51+(321/(311-(-11.35423))))/(-414.5234-(-3.42342/35421.12355)))";
    double my_result = calculation(example, 0);
    double true_result = -72696476962.1522107;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_13) {
    char *example = "(((-134.52/23421)+(-5324.78*1665.5342))/(-423.4323-1323)+(-236*(51.552354/0.5324)))/(-54536/(-14.142-11.4132))";
    double my_result = calculation(example, 0);
    double true_result = -8.3286735;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_14) {
    char *example = "sin(-325.5324*(((2.5432*3.432)/(-1342.5+10.5324))-sin((-44325.11123/2324.234)-1.234))/(3.234-((-2.7568*1.5234)-0.5324))";
    double my_result = calculation(example, 0);
    double true_result = -0.4935034;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_15) {
    char *example = "cos(((-65324*(2654.5645-6541))/(-3654234-(-2234/4345)))+(-5747-(cos(-3534/561.5345))))*(-5432-((-6541/4230.4325)-(-4232*1654.655)))";
    double my_result = calculation(example, 0);
    double true_result = -5104898.2581655;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_16) {
    char *example = "cos((((-13428/3432)-76542)*(45432.8243-6341.2634))/((-6432*(-5430.635))-(-5431/(-5430.5435))))+(-3457/(4323*4322))";
    double my_result = calculation(example, 0);
    double true_result = -0.6654282;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_17) {
    char *example = "cos(((-967575+(-744234/2352))*(4765-(-3765/13234.5224)))-(-4322.4325/(210423.5*3422)))*((6534.51+(cos(-321/(311-11.35423))))/(-414.5234-(-3.42342/35421.12355)))";
    double my_result = calculation(example, 0);
    double true_result = 9.9314323;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_18) {
    char *example = "cos(((-134.52/23421)+(-5324.78*1665.5342))/(-423.4323-1323))+(236*(cos(-51.552354/0.5324)))/(54536/(-14.142-11.4132))";
    double my_result = calculation(example, 0);
    double true_result = 0.3494312;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_19) {
    char *example = "sqrt(ln(asin(-0.15)/((sin(-52.11))^2^2/264.324)-26.432(-41.4723/(123.348/sqrt(45.354)))))";
    double my_result = calculation(example, 0);
    double true_result = 1.6139518;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_20) {
    char *example = "sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(2^2))^2)^2)^2)^2^2)";
    double my_result = calculation(example, 0);
    double true_result = 2;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_21) {
    char *example = "sin(cos(tan(atan(acos(asin(0.02*sqrt(2.56)/(ln(1.5)-log(4.321)))+0.14159)/sqrt(5.432)))))";
    double my_result = calculation(example, 0);
    double true_result = 0.7046340;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_22) {
    char *example = "ln((cos(1.2*atan(0.75)))/(log(5.4321*sqrt(3.14159))))+log((tan(0.5)-asin(0.25))/(ln(2.5)+sqrt(3.14)))";
    double my_result = calculation(example, 0);
    double true_result = -1.2786430;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_23) {
    char *example = "sqrt(1 + (cos(2.5) + sin(1.2))^2/(ln(0.5) + log(2.3))^2)";
    double my_result = calculation(example, 0);
    double true_result = 1.0751692;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_24) {
    char *example = "sin(2*(cos(1.5*atan(0.75)))*log(1+ln(2.5))/(sqrt(2.5)+log(3.14)))";
    double my_result = calculation(example, 0);
    double true_result = 0.1541229;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_25) {
    char *example = "ln(log(2.5)*cos(0.5)/(sin(1.2) + tan(0.75))) - sqrt(ln(-2.5*log(0.75)/ln(1.2)))";
    double my_result = calculation(example, 0);
    double true_result = -2.40828557;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_26) {
    char *example = "0.543(ln(cos(1.5*atan(0.75)) + log(5.4321*sqrt(3.14159))))";
    double my_result = calculation(example, 0);
    double true_result = 0.2389358;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_27) {
    char *example = "523(sin(2*(cos(1.5*atan(0.75)))*log(1+ln(2.5))/(sqrt(2.5)+log(3.14))))";
    double my_result = calculation(example, 0);
    double true_result = 80.6062846;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_28) {
    char *example = "342(acos((asin(acos(0.5)/123))/54.32)*(acos(0.375)/acos(0.5))-(atan(43245.67)/(acos(0.432455)-0.0032)))";
    double my_result = calculation(example, 0);
    double true_result = 129.0791983;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_29) {
    char *example = "6(((ln(cos(1.5*atan(0.75)))/(log(5.4321*sqrt(3.14159))))+log((tan(0.5)-asin(0.25))/(ln(2.5)+sqrt(3.14)))))";
    double my_result = calculation(example, 0);
    double true_result = -9.2077378;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_30) {
    char *example = "5.345 mod 7/(sqrt(1 + (cos(2.5) + sin(1.2))^2/(ln(0.5) + log(2.3))^2))";
    double my_result = calculation(example, 0);
    double true_result = 4.9713104;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_31) {
    char *example = "sqrt(sin(P/2.1324) + cos(3.123P))/2.53";
    double my_result = calculation(example, 0);
    double true_result = 0.1038119;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_32) {
    char *example = "log(2.5e-3) * ln(1000) / P";
    double my_result = calculation(example, 0);
    double true_result = -5.7214271;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_33) {
    char *example = "sqrt(2.234*P^2) + log(34e4) - ln(134e-5)";
    double my_result = calculation(example, 0);
    double true_result = 16.8421685;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_34) {
    char *example = "(2/45*5432e3 * (P/3.14)) + log(123e3 * 123 e-4)";
    double my_result = calculation(example, 0);
    double true_result = 241547.8548887;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

START_TEST(other_35) {
    char *example = "(1+P*P*P-P^3)^3 -1";
    double my_result = calculation(example, 0);
    double true_result = 0.0;
    ck_assert_double_eq_tol(my_result, true_result, 1e-5);
}

Suite *s21_smartcalc(void) {
    Suite *calc = suite_create("s21_smartcalc");

    TCase *tc_test_arifmetic = tcase_create("test_arifmetic");
    tcase_add_test(tc_test_arifmetic, arifmetic_1);
    tcase_add_test(tc_test_arifmetic, arifmetic_2);
    tcase_add_test(tc_test_arifmetic, arifmetic_3);
    tcase_add_test(tc_test_arifmetic, arifmetic_4);
    tcase_add_test(tc_test_arifmetic, arifmetic_5);
    tcase_add_test(tc_test_arifmetic, arifmetic_6);
    tcase_add_test(tc_test_arifmetic, arifmetic_7);
    tcase_add_test(tc_test_arifmetic, arifmetic_8);
    tcase_add_test(tc_test_arifmetic, arifmetic_9);
    tcase_add_test(tc_test_arifmetic, arifmetic_10);
    tcase_add_test(tc_test_arifmetic, arifmetic_11);
    tcase_add_test(tc_test_arifmetic, arifmetic_12);
    tcase_add_test(tc_test_arifmetic, arifmetic_13);
    tcase_add_test(tc_test_arifmetic, arifmetic_14);
    tcase_add_test(tc_test_arifmetic, arifmetic_15);
    tcase_add_test(tc_test_arifmetic, arifmetic_16);
    tcase_add_test(tc_test_arifmetic, arifmetic_17);
    tcase_add_test(tc_test_arifmetic, arifmetic_18);
    tcase_add_test(tc_test_arifmetic, arifmetic_19);
    tcase_add_test(tc_test_arifmetic, arifmetic_20);
    tcase_add_test(tc_test_arifmetic, arifmetic_21);
    tcase_add_test(tc_test_arifmetic, arifmetic_22);
    tcase_add_test(tc_test_arifmetic, arifmetic_23);
    tcase_add_test(tc_test_arifmetic, arifmetic_24);
    tcase_add_test(tc_test_arifmetic, arifmetic_25);
    tcase_add_test(tc_test_arifmetic, arifmetic_26);
    tcase_add_test(tc_test_arifmetic, arifmetic_27);
    tcase_add_test(tc_test_arifmetic, arifmetic_28);
    tcase_add_test(tc_test_arifmetic, arifmetic_29);
    tcase_add_test(tc_test_arifmetic, arifmetic_30);
    tcase_add_test(tc_test_arifmetic, arifmetic_31);
    tcase_add_test(tc_test_arifmetic, arifmetic_32);
    tcase_add_test(tc_test_arifmetic, arifmetic_33);
    tcase_add_test(tc_test_arifmetic, arifmetic_34);
    tcase_add_test(tc_test_arifmetic, arifmetic_35);
    tcase_add_test(tc_test_arifmetic, arifmetic_36);
    tcase_add_test(tc_test_arifmetic, arifmetic_37);
    tcase_add_test(tc_test_arifmetic, arifmetic_38);
    tcase_add_test(tc_test_arifmetic, arifmetic_39);
    tcase_add_test(tc_test_arifmetic, arifmetic_40);
    suite_add_tcase(calc, tc_test_arifmetic);

    TCase *tc_test_trigonometric = tcase_create("test_trigonometric");
    tcase_add_test(tc_test_arifmetic, trigonometric_1);
    tcase_add_test(tc_test_arifmetic, trigonometric_2);
    tcase_add_test(tc_test_arifmetic, trigonometric_3);
    tcase_add_test(tc_test_arifmetic, trigonometric_4);
    tcase_add_test(tc_test_arifmetic, trigonometric_5);
    tcase_add_test(tc_test_arifmetic, trigonometric_6);
    tcase_add_test(tc_test_arifmetic, trigonometric_7);
    tcase_add_test(tc_test_arifmetic, trigonometric_8);
    tcase_add_test(tc_test_arifmetic, trigonometric_9);
    tcase_add_test(tc_test_arifmetic, trigonometric_10);
    tcase_add_test(tc_test_arifmetic, trigonometric_11);
    tcase_add_test(tc_test_arifmetic, trigonometric_12);
    tcase_add_test(tc_test_arifmetic, trigonometric_13);
    tcase_add_test(tc_test_arifmetic, trigonometric_14);
    tcase_add_test(tc_test_arifmetic, trigonometric_15);
    tcase_add_test(tc_test_arifmetic, trigonometric_16);
    tcase_add_test(tc_test_arifmetic, trigonometric_17);
    tcase_add_test(tc_test_arifmetic, trigonometric_18);
    tcase_add_test(tc_test_arifmetic, trigonometric_19);
    tcase_add_test(tc_test_arifmetic, trigonometric_20);
    tcase_add_test(tc_test_arifmetic, trigonometric_21);
    tcase_add_test(tc_test_arifmetic, trigonometric_22);
    tcase_add_test(tc_test_arifmetic, trigonometric_23);
    tcase_add_test(tc_test_arifmetic, trigonometric_24);
    tcase_add_test(tc_test_arifmetic, trigonometric_25);
    tcase_add_test(tc_test_arifmetic, trigonometric_26);
    tcase_add_test(tc_test_arifmetic, trigonometric_27);
    tcase_add_test(tc_test_arifmetic, trigonometric_28);
    tcase_add_test(tc_test_arifmetic, trigonometric_29);
    tcase_add_test(tc_test_arifmetic, trigonometric_30);
    suite_add_tcase(calc, tc_test_trigonometric);

    TCase *tc_test_square = tcase_create("test_square");
    tcase_add_test(tc_test_arifmetic, other_1);
    tcase_add_test(tc_test_arifmetic, other_2);
    tcase_add_test(tc_test_arifmetic, other_3);
    tcase_add_test(tc_test_arifmetic, other_4);
    tcase_add_test(tc_test_arifmetic, other_5);
    tcase_add_test(tc_test_arifmetic, other_6);
    tcase_add_test(tc_test_arifmetic, other_7);
    tcase_add_test(tc_test_arifmetic, other_8);
    tcase_add_test(tc_test_arifmetic, other_9);
    tcase_add_test(tc_test_arifmetic, other_10);
    tcase_add_test(tc_test_arifmetic, other_11);
    tcase_add_test(tc_test_arifmetic, other_12);
    tcase_add_test(tc_test_arifmetic, other_13);
    tcase_add_test(tc_test_arifmetic, other_14);
    tcase_add_test(tc_test_arifmetic, other_15);
    tcase_add_test(tc_test_arifmetic, other_16);
    tcase_add_test(tc_test_arifmetic, other_17);
    tcase_add_test(tc_test_arifmetic, other_18);
    tcase_add_test(tc_test_arifmetic, other_19);
    tcase_add_test(tc_test_arifmetic, other_20);
    tcase_add_test(tc_test_arifmetic, other_21);
    tcase_add_test(tc_test_arifmetic, other_22);
    tcase_add_test(tc_test_arifmetic, other_23);
    tcase_add_test(tc_test_arifmetic, other_24);
    tcase_add_test(tc_test_arifmetic, other_25);
    tcase_add_test(tc_test_arifmetic, other_26);
    tcase_add_test(tc_test_arifmetic, other_27);
    tcase_add_test(tc_test_arifmetic, other_28);
    tcase_add_test(tc_test_arifmetic, other_29);
    tcase_add_test(tc_test_arifmetic, other_30);
    tcase_add_test(tc_test_arifmetic, other_31);
    tcase_add_test(tc_test_arifmetic, other_32);
    tcase_add_test(tc_test_arifmetic, other_33);
    tcase_add_test(tc_test_arifmetic, other_34);
    tcase_add_test(tc_test_arifmetic, other_35);
    suite_add_tcase(calc, tc_test_square);

    return calc;
}

int main(void) {
    Suite *suite = s21_smartcalc();
    SRunner *suite_runner = srunner_create(suite);
    srunner_run_all(suite_runner, CK_NORMAL);
    int failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);
    if (failed_count != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}