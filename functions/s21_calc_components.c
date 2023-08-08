#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A) || result == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return MATH_ERROR;

  matrix_t temp = {0};
  s21_create_matrix(A->rows, A->columns, result);
  s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double temp_d = 0.0;
      s21_get_matrix_without_row_col(i, j, A, &temp);
      s21_determinant(&temp, &temp_d);
      result->matrix[i][j] = pow(-1, (i + j)) * temp_d;
    }
  }

  s21_remove_matrix(&temp);
  return OK;
}