#include "../s21_matrix.h"

int s21_check_matrix(matrix_t *A) {
  if (A == NULL) return 0;
  if (A->matrix == NULL) return 0;
  if (A->rows == 0 || A->columns == 0) return 0;
  return 1;
}

void s21_get_matrix_without_row_col(int row, int coln, matrix_t *m,
                                    matrix_t *result) {
  int res_row = 0;
  int res_coln = 0;
  for (int i = 0; i < m->rows; i++) {
    if (i == row) continue;
    res_coln = 0;
    for (int j = 0; j < m->columns; j++) {
      if (j == coln) continue;
      result->matrix[res_row][res_coln] = m->matrix[i][j];
      res_coln++;
    }
    res_row++;
  }
}