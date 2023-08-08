#include "s21_matrix_test.h"

START_TEST(s21_matrix_calc_components_1) {
  int rows = 3;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[3][3] = {
      {0.0, 10.0, -20.0}, {4.0, -14.0, 8.0}, {-8.0, -2.0, 4.0}};

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;

  m.matrix[1][0] = 0;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 2;

  m.matrix[2][0] = 5;
  m.matrix[2][1] = 2;
  m.matrix[2][2] = 1;
  int res_ret = s21_calc_complements(&m, &result);

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

START_TEST(s21_matrix_calc_components_2) {
  int rows = 3;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[3][3] = {
      {-13.0, 16.0, -4.0}, {7.0, -14.0, 7.0}, {-1.0, 5.0, -3.0}};

  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[0][2] = 3;

  m.matrix[1][0] = 4;
  m.matrix[1][1] = 5;
  m.matrix[1][2] = 7;

  m.matrix[2][0] = 8;
  m.matrix[2][1] = 9;
  m.matrix[2][2] = 10;
  int res_ret = s21_calc_complements(&m, &result);

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

START_TEST(s21_matrix_calc_components_3) {
  int rows = 3;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[3][3] = {
      {135.0, -240.0, -23.0}, {-381.0, -132.0, -43.0}, {465.0, 792.0, -349.0}};

  m.matrix[0][0] = -11;
  m.matrix[0][1] = 21;
  m.matrix[0][2] = 33;

  m.matrix[1][0] = 14;
  m.matrix[1][1] = 5;
  m.matrix[1][2] = 30;

  m.matrix[2][0] = -1;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 15;
  int res_ret = s21_calc_complements(&m, &result);

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

START_TEST(s21_matrix_calc_components_4) {
  int rows = 2;
  int colmns = 2;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(rows, colmns, &m);

  double etalon[2][2] = {{1000.0, -100.0}, {21.0, 15.0}};

  m.matrix[0][0] = 15;
  m.matrix[0][1] = -21;

  m.matrix[1][0] = 100;
  m.matrix[1][1] = 1000;

  int res_ret = s21_calc_complements(&m, &result);

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

START_TEST(s21_matrix_calc_components_5) {
  int rows = 2;
  int colmns = 3;
  matrix_t m = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &m);

  int res_ret = s21_calc_complements(&m, &result);

  s21_remove_matrix(&m);
  ck_assert_int_eq(MATH_ERROR, res_ret);
}
END_TEST

Suite *s21_matrix_calc_components_suite(void) {
  Suite *s = suite_create("suite_calc_components");
  TCase *tc = tcase_create("case_calc_components");

  tcase_add_test(tc, s21_matrix_calc_components_1);
  tcase_add_test(tc, s21_matrix_calc_components_2);
  tcase_add_test(tc, s21_matrix_calc_components_3);
  tcase_add_test(tc, s21_matrix_calc_components_4);
  tcase_add_test(tc, s21_matrix_calc_components_5);

  suite_add_tcase(s, tc);
  return s;
}
