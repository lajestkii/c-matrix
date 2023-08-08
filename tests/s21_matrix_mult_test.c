#include "s21_matrix_test.h"

START_TEST(s21_matrix_mult_1) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_matrix_mult_2) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = -3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 5;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = -2;

  matrix_t mtx = {0};

  s21_create_matrix(cols, rows, &mtx);

  mtx.matrix[0][0] = -7;
  mtx.matrix[0][1] = 5;
  mtx.matrix[1][0] = 2;
  mtx.matrix[1][1] = -1;
  mtx.matrix[2][0] = 4;
  mtx.matrix[2][1] = 3;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = -16;
  check.matrix[0][1] = 16;
  check.matrix[1][0] = -35;
  check.matrix[1][1] = 15;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_matrix_mult_3) {
  matrix_t m = {0};
  matrix_t mtx = {0};

  s21_create_matrix(2, 2, &m);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_matrix_mult_4) {
  matrix_t m = {0};
  matrix_t mtx = {0};

  s21_create_matrix(5, 5, &mtx);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), INCORRECT_MATRIX);

  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(s21_matrix_mult_5) {
  matrix_t m = {0};
  matrix_t mtx = {0};

  s21_create_matrix(2, 2, &m);
  s21_create_matrix(5, 5, &mtx);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), MATH_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

Suite *s21_matrix_mult_suite(void) {
  Suite *s = suite_create("suite_mult");
  TCase *tc = tcase_create("case_mult");

  tcase_add_test(tc, s21_matrix_mult_1);
  tcase_add_test(tc, s21_matrix_mult_2);
  tcase_add_test(tc, s21_matrix_mult_3);
  tcase_add_test(tc, s21_matrix_mult_4);
  tcase_add_test(tc, s21_matrix_mult_5);

  suite_add_tcase(s, tc);
  return s;
}