#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) return ERROR;
  result->columns = columns;
  result->rows = rows;
  double **matrix = malloc(rows * (sizeof(double *)));
  if (matrix == NULL) return ERROR;
  for (int i = 0; i < rows; i++) {
    matrix[i] = calloc(columns, sizeof(double));
    if (matrix[i] == NULL) return ERROR;
  }
  result->matrix = matrix;
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = is_sizes_equals(A, B);
  if (code) {
    int row = A->rows;
    int cols = A->columns;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < cols; j++) {
        double a = A->matrix[i][j], b = B->matrix[i][j];
        if (fabs(a - b) >= eps) {
          code = FAILURE;
          break;
        }
      }
      if (!code) {
        break;
      }
    }
  }
  return code;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

int is_sizes_equals(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    code = FAILURE;
  }
  return code;
}

int is_matrtix_correct(matrix_t *A) {
  int status_code = OK;
  if (A == NULL || (&A->columns == NULL) || (&A->rows == NULL) ||
      (A->rows <= 0) || (A->columns <= 0) || (A->matrix == NULL)) {
    status_code = ERROR;
  }
  else {
    for(int i =0 ; i < A->rows; i++) {
      if(A -> matrix[i] == NULL) {
        status_code = ERROR;
        break;
      }
    }
  }
  return status_code;
}