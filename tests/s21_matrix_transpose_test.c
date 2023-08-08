#include "s21_matrix_test.h"

START_TEST(s21_matrix_transpose_1) {
  int rows = 3;
  int colmns = 4;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(colmns, rows, &matrix_1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      matrix.matrix[i][j] = i + j / 2;
      matrix_1.matrix[j][i] = i + j / 2;
    }
  }

  int res = s21_transpose(&matrix, &result);
  int res1 = s21_eq_matrix(&matrix_1, &result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
  ck_assert_int_eq(SUCCESS, res1);
}
END_TEST

START_TEST(s21_matrix_transpose_2) {
  int rows = 2;
  int colmns = 2;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(colmns, rows, &matrix_1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      matrix.matrix[i][j] = 11 * 0.5 * i;
      matrix_1.matrix[j][i] = 11 * 0.5 * i;
    }
  }

  int res = s21_transpose(&matrix, &result);
  int res1 = s21_eq_matrix(&matrix_1, &result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
  ck_assert_int_eq(SUCCESS, res1);
}
END_TEST

START_TEST(s21_matrix_transpose_3) {
  int rows = 4;
  int colmns = 3;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  matrix_t result = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(colmns, rows, &matrix_1);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < colmns; j++) {
      matrix.matrix[i][j] = 11 * 0.32 * i;
      matrix_1.matrix[j][i] = 11 * 0.32 * i;
    }
  }

  int res = s21_transpose(&matrix, &result);
  int res1 = s21_eq_matrix(&matrix_1, &result);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);

  ck_assert_int_eq(OK, res);
  ck_assert_int_eq(SUCCESS, res1);
}
END_TEST

START_TEST(s21_matrix_transpose_4) {
  int rows = 4;
  int colmns = 3;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  matrix_t result = {0};

  s21_create_matrix(colmns, rows, &matrix_1);

  int res = s21_transpose(&matrix, &result);

  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(INCORRECT_MATRIX, res);
}
END_TEST

Suite *s21_matrix_transpose_suite(void) {
  Suite *s = suite_create("suite_transpose");
  TCase *tc = tcase_create("case_transpose");

  tcase_add_test(tc, s21_matrix_transpose_1);
  tcase_add_test(tc, s21_matrix_transpose_2);
  tcase_add_test(tc, s21_matrix_transpose_3);
  tcase_add_test(tc, s21_matrix_transpose_4);

  suite_add_tcase(s, tc);
  return s;
}
