/**
 * @file s21_calc_payments.c
 * @author kossadda (https://github.com/kossadda)
 * @brief The module contains all functionality for calculating standard
 * payments
 * @version 1.0
 * @date 2024-01-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "./../include/s21_credit.h"

static int calculate_annuity_month(credit_init *data, payments *pay,
                                   time_data next_month,
                                   long double paid_percent);
static int check_calc_redemption(credit_init *data, payments *pay,
                                 early_pay *redemption, time_data *next_month,
                                 long double *paid_percent);
static int calculate_diff_month(credit_init *data, payments *pay,
                                time_data next_month, long double paid_percent);

/*!
 * @brief Calculates monthly payments for an annuity payment type.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[out] redemption structure containing data on early repayments.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
int calculate_payments(credit_init *data, payments *pay,
                       early_pay *redemption) {
  int error_code = ALLOCATED;
  int const_day = data->date.day;

  data->date.leap = check_leap(data->date.year);
  time_data next_month = data->date;

  if (data->payment_type == ANNUITY) {
    double monthly_percent = data->rate / (100.0 * YEAR);
    pay->monthly =
        round_value(data->debt * monthly_percent /
                    (1 - pow((1.0 + monthly_percent), data->months * (-1))));
  } else if (data->payment_type == DIFFERENTIATED) {
    pay->main = round_value(data->debt / data->months);
    pay->const_main = pay->main;
  }

  for (data->current = -1; data->debt != 0;) {
    long double paid_percent = 0;
    add_one_period(&(data->date), &next_month, next_month, CREDIT_MONTH,
                   const_day);

    error_code = check_calc_redemption(data, pay, redemption, &next_month,
                                       &paid_percent);
    if (error_code == ALLOCATED) {
      if (data->payment_type == ANNUITY) {
        error_code =
            calculate_annuity_month(data, pay, next_month, paid_percent);
      } else if (data->payment_type == DIFFERENTIATED) {
        error_code = calculate_diff_month(data, pay, next_month, paid_percent);
      }
    }

    data->date = next_month;
    data->debt = (error_code == ALLOCATED) ? data->debt : 0;
  }

  return error_code;
}

/*!
 * @brief Function for calculating one month payments.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[in] next_month structure containing the payment end date for the
 * current month.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
static int calculate_annuity_month(credit_init *data, payments *pay,
                                   time_data next_month,
                                   long double paid_percent) {
  int error_code = ALLOCATED;
  static long double rest = 0;

  data->current++;
  error_code = allocate_row(&pay->result, data->current, CREDIT_COLUMNS);

  if (error_code == ALLOCATED) {
    long double first_part_month = percent_formula(
        data->debt, data->rate, data->date.leap, data->date.month_days);
    long double second_part_month = percent_formula(
        data->debt, data->rate, next_month.leap, next_month.month_days);
    pay->percent =
        round_value(first_part_month + second_part_month) - paid_percent;

    if (rest) {
      pay->percent += rest;
      rest = 0;
    }

    if (pay->percent > pay->monthly) {
      rest = pay->percent - pay->monthly;
      pay->percent = pay->monthly;
      pay->main = 0;
    } else {
      if (data->debt >= pay->monthly) {
        pay->main = pay->monthly - pay->percent;
      } else if (data->debt < pay->monthly &&
                 data->debt + pay->percent > pay->monthly) {
        pay->main = pay->monthly - pay->percent;
      } else {
        pay->main = data->debt;
        pay->monthly = pay->main + pay->percent;
      }
    }

    data->debt -= pay->main;

    remember_result(data, pay);
  }

  return error_code;
}

/*!
 * @brief Function for calculating one month payments.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[in] next_month structure containing the payment end date for the
 * current month.
 * @param[in] paid_percent the amount deducted from the monthly interest in case
 * of early repayment.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
static int calculate_diff_month(credit_init *data, payments *pay,
                                time_data next_month,
                                long double paid_percent) {
  int error_code = ALLOCATED;

  data->current++;
  error_code = allocate_row(&pay->result, data->current, CREDIT_COLUMNS);

  if (error_code == ALLOCATED) {
    if (data->debt < pay->main) {
      pay->main = data->debt;
    }

    long double first_part_month = percent_formula(
        data->debt, data->rate, data->date.leap, data->date.month_days);
    long double second_part_month = percent_formula(
        data->debt, data->rate, next_month.leap, next_month.month_days);
    pay->percent =
        round_value(first_part_month + second_part_month) - paid_percent;
    pay->monthly = pay->main + pay->percent;
    data->debt -= pay->main;

    remember_result(data, pay);
  }

  return error_code;
}

/*!
 * @brief Determines whether the current early repayment is within the current
 * month and calculates it.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 * @param[out] redemption structure containing data on early repayments.
 * @param[out] next_month structure containing the payment end date for the
 * current month.
 * @param[out] paid_percent the amount deducted from the monthly interest in
 * case of early repayment.
 *
 * @return int - error code.
 * @retval ALLOCATED = 0 - if memory is allocated.
 * @retval NOT_ALLOCATED = 1 - if memory isn't allocated.
 */
static int check_calc_redemption(credit_init *data, payments *pay,
                                 early_pay *redemption, time_data *next_month,
                                 long double *paid_percent) {
  int error_code = ALLOCATED;
  int change = DEBT_NOT_CHANGED;

  if (redemption && redemption->sum &&
      redemption->current < redemption->count) {
    while (compare_date_with_month(data->date,
                                   &(redemption->date[redemption->current]),
                                   *next_month) == DATE_BETWEEN) {
      error_code = redemp_payment(data, pay, redemption, next_month,
                                  paid_percent, &change);

      if (redemption->current == redemption->count) {
        break;
      }
    }
  }

  return error_code;
}

/*!
 * @brief A function that writes the result of each month to an array.
 *
 * @param[out] data structure containing input parameters for calculation.
 * @param[out] pay structure containing buffer variables for monthly results and
 * general payment data arrays.
 */
void remember_result(credit_init *data, payments *pay) {
  pay->result[data->current][0] = pay->monthly;
  pay->total[0] += pay->monthly;
  pay->result[data->current][1] = pay->main;
  pay->total[1] += pay->main;
  pay->result[data->current][2] = pay->percent;
  pay->total[2] += pay->percent;
  pay->result[data->current][3] = data->debt;
}