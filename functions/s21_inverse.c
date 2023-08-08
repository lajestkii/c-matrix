#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A) || result == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return MATH_ERROR;

  int flag = OK;
  double determinant = 0.0;

  s21_determinant(A, &determinant);
  if (fabs(determinant - 0.0) > 1e-7) {
    matrix_t temp_calc = {0};
    matrix_t temp_tcalc = {0};
    s21_calc_complements(A, &temp_calc);
    s21_transpose(&temp_calc, &temp_tcalc);
    s21_mult_number(&temp_tcalc, (1 / determinant), result);
    s21_remove_matrix(&temp_tcalc);
    s21_remove_matrix(&temp_calc);
  } else {
    flag = MATH_ERROR;
  }
  return flag;
}