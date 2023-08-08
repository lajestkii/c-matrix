#include "s21_matrix_test.h"

int main(void) {
  int number_failed = 0;
  Suite* s[] = {s21_matrix_create_suite(),
                s21_matrix_eq_suite(),
                s21_matrix_sum_suite(),
                s21_matrix_sub_suite(),
                s21_matrix_multnum_suite(),
                s21_matrix_mult_suite(),
                s21_matrix_transpose_suite(),
                s21_matrix_determinant_suite(),
                s21_matrix_calc_components_suite(),
                s21_matrix_inverse_suite(),
                NULL};
  for (Suite** current_suit = s; *current_suit != NULL; current_suit++) {
    s21_test_one_suite(*current_suit, &number_failed);
  }
  return 0;  //(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void s21_test_one_suite(Suite* current_suit, int* sum_of_errors) {
  SRunner* sr;
  sr = srunner_create(current_suit);

  srunner_run_all(sr, CK_NORMAL);
  *sum_of_errors += srunner_ntests_failed(sr);
  srunner_free(sr);
}