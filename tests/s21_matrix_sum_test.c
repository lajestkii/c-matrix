#include "s21_matrix_test.h"

START_TEST(s21_matrix_sum_1) {
  int rows = 2;
  int colmns = 2;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  matrix.matrix[0][0] = 1.543;
  matrix.matrix[0][1] = 2.3456;
  matrix.matrix[1][0] = 16;
  matrix.matrix[1][1] = 14;

  matrix_1.matrix[0][0] = 28.457;
  matrix_1.matrix[0][1] = 27.6544;
  matrix_1.matrix[1][0] = 14;
  matrix_1.matrix[1][1] = 16;

  int res = s21_sum_matrix(&matrix, &matrix_1, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], 30.0, 1e-6);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
}
END_TEST

START_TEST(s21_matrix_sum_2) {
  int rows = 2;
  int colmns = 3;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};
  matrix_t result = {0};

  double etalon[2][3] = {{2.777, 6.79, 2.4686}, {27.01, 28.14, 30.16}};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  matrix.matrix[0][0] = 1.543;
  matrix.matrix[0][1] = 2.3456;
  matrix.matrix[0][2] = 2.3456;
  matrix.matrix[1][0] = 16;
  matrix.matrix[1][1] = 14;
  matrix.matrix[1][2] = 14;

  matrix_1.matrix[0][0] = 1.234;
  matrix_1.matrix[0][1] = 4.4444;
  matrix_1.matrix[0][2] = 0.123;
  matrix_1.matrix[1][0] = 11.01;
  matrix_1.matrix[1][1] = 14.14;
  matrix_1.matrix[1][2] = 16.16;

  int res = s21_sum_matrix(&matrix, &matrix_1, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
}
END_TEST

START_TEST(s21_matrix_sum_3) {
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};
  matrix_t result = {0};

  s21_create_matrix(2, 3, &matrix);
  s21_create_matrix(3, 2, &matrix_1);

  int res = s21_sum_matrix(&matrix, &matrix_1, &result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(MATH_ERROR, res);
}
END_TEST

START_TEST(s21_matrix_sum_4) {
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 2, &matrix_1);

  int res = s21_sum_matrix(&matrix, &matrix_1, &result);

  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(INCORRECT_MATRIX, res);
}
END_TEST

START_TEST(s21_matrix_sum_5) {
  int rows = 1;
  int colmns = 1;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  matrix.matrix[0][0] = 1.543;

  matrix_1.matrix[0][0] = 1.234;

  int res = s21_sum_matrix(&matrix, &matrix_1, &result);

  ck_assert_double_eq_tol(result.matrix[0][0], 2.777, 1e-6);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
}
END_TEST

Suite *s21_matrix_sum_suite(void) {
  Suite *s = suite_create("suite_sum");
  TCase *tc = tcase_create("case_sum");

  tcase_add_test(tc, s21_matrix_sum_1);
  tcase_add_test(tc, s21_matrix_sum_2);
  tcase_add_test(tc, s21_matrix_sum_3);
  tcase_add_test(tc, s21_matrix_sum_4);
  tcase_add_test(tc, s21_matrix_sum_5);

  suite_add_tcase(s, tc);
  return s;
}
