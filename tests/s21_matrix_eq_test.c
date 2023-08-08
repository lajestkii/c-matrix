#include "s21_matrix_test.h"

START_TEST(s21_matrix_eq_1) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  int res = s21_eq_matrix(&matrix, &matrix_1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(SUCCESS, res);
}
END_TEST

START_TEST(s21_matrix_eq_2) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(colmns, rows, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  int res = s21_eq_matrix(&matrix, &matrix_1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(FAILURE, res);
}
END_TEST

START_TEST(s21_matrix_eq_3) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  matrix.matrix[0][0] = 1;
  matrix_1.matrix[0][0] = 2;

  int res = s21_eq_matrix(&matrix, &matrix_1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(FAILURE, res);
}
END_TEST

START_TEST(s21_matrix_eq_4) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, colmns, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  matrix.matrix[0][0] = 2.5;
  matrix_1.matrix[0][0] = 2.5;

  int res = s21_eq_matrix(&matrix, &matrix_1);

  s21_remove_matrix(&matrix);
  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(SUCCESS, res);
}
END_TEST

START_TEST(s21_matrix_eq_5) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, 0, &matrix);
  s21_create_matrix(rows, colmns, &matrix_1);

  int res = s21_eq_matrix(&matrix, &matrix_1);

  matrix_1.matrix[0][0] = 2.5;

  s21_remove_matrix(&matrix_1);

  ck_assert_int_eq(FAILURE, res);
}
END_TEST

START_TEST(s21_matrix_eq_6) {
  int rows = 3;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, 0, &matrix);
  s21_create_matrix(rows, 0, &matrix_1);

  int res = s21_eq_matrix(&matrix, &matrix_1);

  ck_assert_int_eq(FAILURE, res);
}
END_TEST

START_TEST(s21_matrix_eq_7) {
  int colmn = 3;
  int rows = 3;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, colmn, &matrix);
  s21_create_matrix(rows, colmn, &matrix_1);

  matrix.matrix[0][0] = 1.568;
  matrix.matrix[0][1] = 1.333;
  matrix.matrix[0][2] = 256.123;
  matrix.matrix[1][0] = 256.777;
  matrix.matrix[1][1] = -100.1;
  matrix.matrix[1][2] = 0;
  matrix.matrix[2][0] = 0.25;
  matrix.matrix[2][1] = 0.75;
  matrix.matrix[2][2] = 0.568;

  matrix_1.matrix[0][0] = 1.568;
  matrix_1.matrix[0][1] = 1.333;
  matrix_1.matrix[0][2] = 256.123;
  matrix_1.matrix[1][0] = 256.777;
  matrix_1.matrix[1][1] = -100.1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][0] = 0.25;
  matrix_1.matrix[2][1] = 0.75;
  matrix_1.matrix[2][2] = 0.568;

  int res = s21_eq_matrix(&matrix, &matrix_1);

  ck_assert_int_eq(SUCCESS, res);
}
END_TEST

START_TEST(s21_matrix_eq_8) {
  int colmn = 3;
  int rows = 3;

  matrix_t matrix = {0};
  matrix_t matrix_1 = {0};

  s21_create_matrix(rows, colmn, &matrix);
  s21_create_matrix(rows, colmn, &matrix_1);

  matrix.matrix[0][0] = 1.568;
  matrix.matrix[0][1] = 1.333;
  matrix.matrix[0][2] = 256.123;
  matrix.matrix[1][0] = 256.777;
  matrix.matrix[1][1] = -100.123;
  matrix.matrix[1][2] = 0;
  matrix.matrix[2][0] = 0.25;
  matrix.matrix[2][1] = 0.75;
  matrix.matrix[2][2] = 0.568;

  matrix_1.matrix[0][0] = 1.568;
  matrix_1.matrix[0][1] = 1.333;
  matrix_1.matrix[0][2] = 256.123;
  matrix_1.matrix[1][0] = 256.777;
  matrix_1.matrix[1][1] = -100.1;
  matrix_1.matrix[1][2] = 0;
  matrix_1.matrix[2][0] = 0.25;
  matrix_1.matrix[2][1] = 0.75;
  matrix_1.matrix[2][2] = 0.568;

  int res = s21_eq_matrix(&matrix, &matrix_1);

  ck_assert_int_eq(FAILURE, res);
}
END_TEST

Suite *s21_matrix_eq_suite(void) {
  Suite *s = suite_create("suite_eq");
  TCase *tc = tcase_create("case_eq");

  tcase_add_test(tc, s21_matrix_eq_1);
  tcase_add_test(tc, s21_matrix_eq_2);
  tcase_add_test(tc, s21_matrix_eq_3);
  tcase_add_test(tc, s21_matrix_eq_4);
  tcase_add_test(tc, s21_matrix_eq_5);
  tcase_add_test(tc, s21_matrix_eq_6);
  tcase_add_test(tc, s21_matrix_eq_7);
  tcase_add_test(tc, s21_matrix_eq_8);

  suite_add_tcase(s, tc);
  return s;
}
