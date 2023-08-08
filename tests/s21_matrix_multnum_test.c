#include "s21_matrix_test.h"

START_TEST(s21_matrix_multnum_1) {
  int rows = 3;
  int colmn = 3;
  matrix_t matrix = {0};
  matrix_t result = {0};

  double etalon[3][3] = {{2.2222, 1, 4}, {15, 11, 38.4}, {100, 200, 150}};

  s21_create_matrix(rows, colmn, &matrix);

  matrix.matrix[0][0] = 1.1111;
  matrix.matrix[0][1] = 0.5;
  matrix.matrix[0][2] = 2;

  matrix.matrix[1][0] = 7.5;
  matrix.matrix[1][1] = 5.5;
  matrix.matrix[1][2] = 19.2;

  matrix.matrix[2][0] = 50;
  matrix.matrix[2][1] = 100;
  matrix.matrix[2][2] = 75;

  int res = s21_mult_number(&matrix, 2.0, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmn; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_matrix_multnum_2) {
  int rows = 3;
  int colmn = 3;
  matrix_t matrix = {0};
  matrix_t result = {0};

  double etalon[3][3] = {
      {1.66665, 0.75, 3}, {11.25, 8.25, 28.8}, {75, 150, 112.5}};

  s21_create_matrix(rows, colmn, &matrix);

  matrix.matrix[0][0] = 1.1111;
  matrix.matrix[0][1] = 0.5;
  matrix.matrix[0][2] = 2;

  matrix.matrix[1][0] = 7.5;
  matrix.matrix[1][1] = 5.5;
  matrix.matrix[1][2] = 19.2;

  matrix.matrix[2][0] = 50;
  matrix.matrix[2][1] = 100;
  matrix.matrix[2][2] = 75;

  int res = s21_mult_number(&matrix, 1.5, &result);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmn; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], etalon[i][j], 1e-6);
    }
  }

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&result);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(s21_matrix_multnum_3) {
  int rows = 3;
  int colmn = 0;
  matrix_t matrix = {0};
  matrix_t result = {0};

  s21_create_matrix(rows, colmn, &matrix);

  int res = s21_mult_number(&matrix, 1.5, &result);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *s21_matrix_multnum_suite(void) {
  Suite *s = suite_create("suite_multnum");
  TCase *tc = tcase_create("case_multnum");

  tcase_add_test(tc, s21_matrix_multnum_1);
  tcase_add_test(tc, s21_matrix_multnum_2);
  tcase_add_test(tc, s21_matrix_multnum_3);

  suite_add_tcase(s, tc);
  return s;
}