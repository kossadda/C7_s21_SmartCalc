/**
 * @file tests.c
 * @author kossadda (https://github.com/kossadda)
 * @brief Module for assembling all test modules.
 * @version 1.0
 * @date 2024-01-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./tests.h"

#include <stdio.h>
#include <string.h>

static void test_function(Suite *(**array)(void), size_t size, char *name,
                          int *passed_count, int *failed_count);
static void conclusion(int passed_count, int failed_count);
static void function_declaration(char *function);
static int test_suite(Suite *test, int *passed_count);
static void greetings();
static void line();

/**
 * @brief Function to start testing modules.
 *
 * @return int - error code.
 * @retval EXIT_SUCCESS = 0 - if the tests pass successfully.
 * @retval EXIT_FAILURE = 1 - if the tests pass unsuccessful.
 */
int main(void) {
  int failed_count = 0;
  int passed_count = 0;

  greetings();

#define SMARTCALC_TEST
#ifdef SMARTCALC_TEST
  Suite *(*smartcalc[])(void) = {
      arifmetic_1,
      arifmetic_2,
      arifmetic_3,
      arifmetic_4,
      trigonometric_1,
      trigonometric_2,
      trigonometric_3,
      other_1,
      other_2,
      other_3,
      other_4,
      other_5,
      wrong_expressions_1,
      wrong_expressions_2,
  };
  test_function(smartcalc, sizeof(smartcalc) / sizeof(smartcalc[0]),
                "SMARTCALC", &passed_count, &failed_count);
#endif

#define CREDIT_TEST
#ifdef CREDIT_TEST
  Suite *(*credit[])(void) = {
      pointer_test,
      annuity_1,
      annuity_2,
      annuity_3,
      annuity_4,
      annuity_5,
      differentiated_1,
      differentiated_2,
      differentiated_3,
      differentiated_4,
      differentiated_5,
      diff_redemption_term,
      diff_redemption_pay,
      annuity_redepmtion_term,
      annuity_redepmtion_pay,
      diff_redepmtion_combinated,
      annuity_redepmtion_combinated,
  };
  test_function(credit, sizeof(credit) / sizeof(credit[0]), "CREDIT",
                &passed_count, &failed_count);
#endif

#define DEPOSIT_TEST
#ifdef DEPOSIT_TEST
  Suite *(*deposit[])(void) = {
      deposit_by_end_term,
      deposit_by_day,
      deposit_by_week,
      deposit_by_month,
      deposit_by_quarter,
      deposit_by_halfyear,
      deposit_by_year,
      deposit_refill_by_day,
      deposit_refill_by_week,
      deposit_refill_by_month,
      deposit_refill_by_quarter,
      deposit_refill_by_halfyear,
      deposit_refill_by_year,
      deposit_refill_by_end_term,
      deposit_withdrawals_by_day,
      deposit_withdrawals_by_week,
      deposit_withdrawals_by_month,
      deposit_withdrawals_by_quarter,
      deposit_withdrawals_by_halfyear,
      deposit_withdrawals_by_year,
      deposit_withdrawals_by_end_term,
      deposit_combined_with_taxes,
  };
  test_function(deposit, sizeof(deposit) / sizeof(deposit[0]), "DEPOSIT",
                &passed_count, &failed_count);
#endif

  conclusion(passed_count, failed_count);

  return (failed_count) ? EXIT_FAILURE : EXIT_SUCCESS;
}

/**
 * @brief Function for testing the specified Suite.
 *
 * @param[out] test input Suite test.
 * @param[out] passed_count counter of successfully passed tests.
 *
 * @return int - error code.
 * @retval EXIT_SUCCESS = 0 - if the tests pass successfully.
 * @retval EXIT_FAILURE = 1 - if the tests pass unsuccessful.
 */
static int test_suite(Suite *test, int *passed_count) {
  SRunner *suite_runner = srunner_create(test);

  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  *passed_count += srunner_ntests_run(suite_runner) - failed_count;
  srunner_free(suite_runner);

  return failed_count;
}

/**
 * @brief Prints greeting message.
 */
static void greetings() {
  printf(
      "\033[0;33m __          __  _                            _          _    "
      "        _   _             \n");
  printf(
      " \\ \\        / / | |                          | |        | |          "
      "| | (_)            \n");
  printf(
      "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_ ___  "
      "___| |_ _ _ __   __ _ \n");
  printf(
      "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | __/ _ "
      "\\/ __| __| | '_ \\ / _` |\n");
  printf(
      "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | ||  __/\\__ "
      "\\ |_| | | | | (_| |\n");
  printf(
      "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/   "
      "\\__\\___||___/\\__|_|_| |_|\\__, |\n");
  printf(
      "                                                                        "
      "           __/ |\n");
  printf(
      "                                                                        "
      "          |___/ \n");

  printf(
      "                                    _                                   "
      "                  \n");
  printf(
      "                                   | |                                  "
      "                  \n");
  printf(
      "                                   | |__  _   _                         "
      "                  \n");
  printf(
      "                                   | '_ \\| | | |                       "
      "                   \n");
  printf(
      "                                   | |_) | |_| |                        "
      "                  \n");
  printf(
      "                                   |_.__/ \\__, |                       "
      "                   \n");
  printf(
      "                       _                   __/ |   _     _              "
      "     \n");
  printf(
      "                      | |                 |___/   | |   | |             "
      "     \n");
  printf(
      "                      | | _____  ___ ___  __ _  __| | __| | __ _        "
      "     \n");
  printf(
      "                      | |/ / _ \\/ __/ __|/ _` |/ _` |/ _` |/ _` |      "
      "      \n");
  printf(
      "                      |   < (_) \\__ \\__ \\ (_| | (_| | (_| | (_| |    "
      "        \n");
  printf(
      "                      |_|\\_\\___/|___/___/\\__,_|\\__,_|\\__,_|\\__,_| "
      "           \n");
}

/**
 * @brief Collects all functions for testing into a single block.
 *
 * @param array array of function under test.
 * @param size array size.
 * @param name name of the function being tested.
 * @param passed_count number of tests passed.
 * @param failed_count number of failed tests.
 */
static void test_function(Suite *(**array)(void), size_t size, char *name,
                          int *passed_count, int *failed_count) {
  function_declaration(name);
  for (size_t i = 0; i < size; i++) {
    line();
    *failed_count += test_suite(array[i](), passed_count);
  }
  line();
}

/**
 * @brief Prints function declaration message.
 *
 * @param[in] function name of testing function.
 */
static void function_declaration(char *function) {
  char space[5] = {0};
  int str_len = strlen(function);
  if (str_len == 6) {
    strcpy(space, "   ");
  } else if (str_len == 7) {
    strcpy(space, "  ");
  }
  printf(
      "\033[0;33m\n\n "
      "________________________________________________________________________"
      "______________\n");
  printf(
      "|                                                                       "
      "               |\n");
  printf(
      "|                                  %s TESTS %s                          "
      "          |\n",
      function, space);
  printf(
      "|_______________________________________________________________________"
      "_______________|\n\n\n\033[0m");
}

/**
 * @brief Prints the dividing line.
 */
static void line() {
  printf(
      "\033[0;33m**************************************************************"
      "**************************\n\033[0m");
}

/**
 * @brief Prints test results.
 *
 * @param[in] passed_count number of tests passed.
 * @param[in] failed_count number of failed tests.
 */
static void conclusion(int passed_count, int failed_count) {
  printf(
      "\033[0;33m\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TOTAL RESULTS "
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~\n");
  printf(
      "                                                                        "
      " \n");
  printf(
      "                               PASSED %d tests from %d                  "
      "      \n",
      passed_count, passed_count + failed_count);
  printf(
      "                                                                        "
      " \n");
  printf(
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
      "~~~~~~~~~~~~~~~~\n\033[0m\n");
}