#include "../s21_matrix.h"

double s21_det(matrix_t *A) {
  if (A->rows == 1) return A->matrix[0][0];
  double res = 0.0;
  matrix_t temp = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp);

  for (int i = 0; i < A->columns; i++) {
    s21_get_matrix_without_row_col(0, i, A, &temp);
    if (i % 2 == 0) {
      res += A->matrix[0][i] * s21_det(&temp);
    } else {
      res -= A->matrix[0][i] * s21_det(&temp);
    }
  }
  s21_remove_matrix(&temp);
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_check_matrix(A) || result == NULL) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return MATH_ERROR;

  *result = s21_det(A);
  return OK;
}