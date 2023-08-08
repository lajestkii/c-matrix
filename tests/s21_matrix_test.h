#include <check.h>

#include "../s21_matrix.h"

#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

Suite *s21_matrix_create_suite(void);
Suite *s21_matrix_eq_suite(void);
Suite *s21_matrix_sum_suite(void);
Suite *s21_matrix_sub_suite(void);
Suite *s21_matrix_multnum_suite(void);
Suite *s21_matrix_mult_suite(void);
Suite *s21_matrix_transpose_suite(void);
Suite *s21_matrix_determinant_suite(void);
Suite *s21_matrix_calc_components_suite(void);
Suite *s21_matrix_inverse_suite(void);

void s21_test_one_suite(Suite *current_suit, int *sum_of_errors);

#endif