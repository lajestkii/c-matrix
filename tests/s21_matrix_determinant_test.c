#include "s21_matrix_test.h"

START_TEST(s21_matrix_determinant_1) {
  int rows = 3;
  int colmns = 3;
  double res = 0.0;
  matrix_t matrix = {0};

  s21_create_matrix(rows, colmns, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = -2;
  matrix.matrix[0][2] = 3;

  matrix.matrix[1][0] = 4;
  matrix.matrix[1][1] = 0;
  matrix.matrix[1][2] = 6;

  matrix.matrix[2][0] = -7;
  matrix.matrix[2][1] = 8;
  matrix.matrix[2][2] = 9;

  int res_ret = s21_determinant(&matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(OK, res_ret);
  ck_assert_double_eq_tol(res, 204.0, 1e-6);
}
END_TEST

START_TEST(s21_matrix_determinant_2) {
  int rows = 4;
  int colmns = 4;
  double res = 0.0;
  matrix_t matrix = {0};

  s21_create_matrix(rows, colmns, &matrix);

  matrix.matrix[0][0] = 11.43;
  matrix.matrix[0][1] = -2.11;
  matrix.matrix[0][2] = 154.1;
  matrix.matrix[0][3] = 1;

  matrix.matrix[1][0] = 0.2;
  matrix.matrix[1][1] = 0;
  matrix.matrix[1][2] = 6.666;
  matrix.matrix[1][3] = 111;

  matrix.matrix[2][0] = 38.123;
  matrix.matrix[2][1] = 3.15;
  matrix.matrix[2][2] = 0.75;
  matrix.matrix[2][3] = 1;

  matrix.matrix[3][0] = 1000;
  matrix.matrix[3][1] = 176.555;
  matrix.matrix[3][2] = 2.123;
  matrix.matrix[3][3] = 13.4;

  int res_ret = s21_determinant(&matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(OK, res_ret);
  ck_assert_double_eq_tol(res, 60922966.0956196, 1e-6);
}
END_TEST

START_TEST(s21_matrix_determinant_3) {
  int rows = 5;
  int colmns = 5;
  double res = 0.0;
  matrix_t matrix = {0};

  s21_create_matrix(rows, colmns, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 2;
  matrix.matrix[0][2] = 3;
  matrix.matrix[0][3] = 4;
  matrix.matrix[0][4] = 5;

  matrix.matrix[1][0] = 11;
  matrix.matrix[1][1] = 12;
  matrix.matrix[1][2] = 13;
  matrix.matrix[1][3] = 14;
  matrix.matrix[1][4] = 15;

  matrix.matrix[2][0] = 21;
  matrix.matrix[2][1] = 22;
  matrix.matrix[2][2] = 23;
  matrix.matrix[2][3] = 24;
  matrix.matrix[2][4] = 25;

  matrix.matrix[3][0] = 31;
  matrix.matrix[3][1] = 32;
  matrix.matrix[3][2] = 33;
  matrix.matrix[3][3] = 34;
  matrix.matrix[3][4] = 35;

  matrix.matrix[4][0] = 41;
  matrix.matrix[4][1] = 42;
  matrix.matrix[4][2] = 43;
  matrix.matrix[4][3] = 44;
  matrix.matrix[4][4] = 45;

  int res_ret = s21_determinant(&matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(OK, res_ret);
  ck_assert_double_eq_tol(res, 0.0, 1e-6);
}
END_TEST

START_TEST(s21_matrix_determinant_4) {
  int rows = 3;
  int colmns = 3;
  double res = 0.0;
  matrix_t matrix = {0};

  s21_create_matrix(rows, colmns, &matrix);

  matrix.matrix[0][0] = 1;
  matrix.matrix[0][1] = 21;
  matrix.matrix[0][2] = 3;

  matrix.matrix[1][0] = -4;
  matrix.matrix[1][1] = -2;
  matrix.matrix[1][2] = -3;

  matrix.matrix[2][0] = -1;
  matrix.matrix[2][1] = -5;
  matrix.matrix[2][2] = -3;

  int res_ret = s21_determinant(&matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(OK, res_ret);
  ck_assert_double_eq_tol(res, -144, 1e-6);
}
END_TEST

START_TEST(s21_matrix_determinant_5) {
  int rows = 5;
  int colmns = 4;
  double res = 0.0;
  matrix_t matrix = {0};

  s21_create_matrix(rows, colmns, &matrix);

  int res_ret = s21_determinant(&matrix, &res);
  s21_remove_matrix(&matrix);

  ck_assert_int_eq(MATH_ERROR, res_ret);
}
END_TEST

Suite *s21_matrix_determinant_suite(void) {
  Suite *s = suite_create("suite_determinant");
  TCase *tc = tcase_create("case_determinant");

  tcase_add_test(tc, s21_matrix_determinant_1);
  tcase_add_test(tc, s21_matrix_determinant_2);
  tcase_add_test(tc, s21_matrix_determinant_3);
  tcase_add_test(tc, s21_matrix_determinant_4);
  tcase_add_test(tc, s21_matrix_determinant_5);

  suite_add_tcase(s, tc);
  return s;
}
