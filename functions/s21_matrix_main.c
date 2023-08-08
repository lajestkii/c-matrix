#include "../s21_matrix.h"

int s21_create_matrix(int rows, int colmns, matrix_t *res) {
  if (colmns <= 0 || rows <= 0) return INCORRECT_MATRIX;

  if (res == NULL) return INCORRECT_MATRIX;

  res->columns = colmns;
  res->rows = rows;

  res->matrix = (double **)calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    res->matrix[i] = (double *)calloc(colmns, sizeof(double));
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}