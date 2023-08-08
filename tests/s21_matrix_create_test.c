#include "s21_matrix_test.h"

START_TEST(s21_matrix_create_1) {
  int rows = 3;
  int colmns = 4;
  matrix_t matrix = {0};

  int res = s21_create_matrix(rows, colmns, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_int_eq(OK, res);
}
END_TEST

START_TEST(s21_matrix_create_2) {
  int rows = 0;
  int colmns = 4;
  matrix_t matrix = {0};

  int res = s21_create_matrix(rows, colmns, &matrix);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
}
END_TEST

START_TEST(s21_matrix_create_3) {
  int rows = 3;
  int colmns = 0;
  matrix_t matrix = {0};

  int res = s21_create_matrix(rows, colmns, &matrix);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
}
END_TEST

Suite *s21_matrix_create_suite(void) {
  Suite *s = suite_create("suite_create");
  TCase *tc = tcase_create("case_create");

  tcase_add_test(tc, s21_matrix_create_1);
  tcase_add_test(tc, s21_matrix_create_2);
  tcase_add_test(tc, s21_matrix_create_3);

  suite_add_tcase(s, tc);
  return s;
}
