#include "s21_matrix_test.h"

START_TEST(s21_matrix_inverse_1) {
  int rows = 3;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;

  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;

  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;
  int res_ret = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(OK, res_ret);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_matrix_inverse_2) {
  int rows = 3;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[3][3] = {{0.6, -0.4, 0.8}, {0.7, 0.2, 0.1}, {-0.1, 0.4, -0.3}};

  m.matrix[0][0] = -1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = -2;

  m.matrix[1][0] = 2;
  m.matrix[1][1] = -1;
  m.matrix[1][2] = 5;

  m.matrix[2][0] = 3;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 4;
  int res_ret = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(OK, res_ret);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_matrix_inverse_3) {
  int rows = 2;
  int colmns = 2;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  m.matrix[0][0] = 5;
  m.matrix[0][1] = 5;

  m.matrix[1][0] = 5;
  m.matrix[1][1] = 5;

  int res_ret = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(MATH_ERROR, res_ret);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_matrix_inverse_4) {
  int rows = 2;
  int colmns = 2;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[2][2] = {{0.004444444, 0.00093333}, {-0.04444444, 0.00066667}};

  m.matrix[0][0] = 15;
  m.matrix[0][1] = -21;

  m.matrix[1][0] = 1000;
  m.matrix[1][1] = 100;

  int res_ret = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(OK, res_ret);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }
  s21_remove_matrix(&m);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_matrix_inverse_5) {
  int rows = 2;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  int res_ret = s21_inverse_matrix(&m, &result);

  ck_assert_int_eq(MATH_ERROR, res_ret);

  s21_remove_matrix(&m);
}
END_TEST

Suite *s21_matrix_inverse_suite(void) {
  Suite *s = suite_create("suite_inverse");
  TCase *tc = tcase_create("case_inverse");

  tcase_add_test(tc, s21_matrix_inverse_1);
  tcase_add_test(tc, s21_matrix_inverse_2);
  tcase_add_test(tc, s21_matrix_inverse_3);
  tcase_add_test(tc, s21_matrix_inverse_4);
  tcase_add_test(tc, s21_matrix_inverse_5);

  suite_add_tcase(s, tc);
  return s;
}
