#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B)) return FAILURE;

  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;

  int flag = 1;

  for (int i = 0; i < A->rows && flag; i++) {
    for (int j = 0; j < A->columns && flag; j++) {
      if (round(A->matrix[i][j] * pow(10, 7)) !=
          round(B->matrix[i][j] * pow(10, 7)))
        flag = 0;
    }
  }
  return flag ? SUCCESS : FAILURE;
}