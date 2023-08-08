#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B) || result == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->columns || A->rows != B->rows) return MATH_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B) || result == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->columns || A->rows != B->rows) return MATH_ERROR;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_check_matrix(A) || result == NULL) return INCORRECT_MATRIX;

  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B) || result == NULL)
    return INCORRECT_MATRIX;
  if (A->columns != B->rows || A->rows != B->columns) return MATH_ERROR;

  s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return OK;
}