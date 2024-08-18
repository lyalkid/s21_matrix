#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || !result) return ERROR;
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
  A->matrix = NULL;
  A -> rows = 0, A->columns = 0;
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
    int code = is_matrices_both_correct(A, B);
    if(code == OK ){
        int rows = A ->rows, cols = A -> columns;
        code = s21_create_matrix(rows, cols, result);
        for(int i= 0; code == OK && i < result ->rows; i++){
            for(int j = 0;  j < result -> columns; j++){
                result -> matrix[i][j] = A -> matrix[i][j] + B -> matrix[i][j];
            }
        }
    }
    return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = is_matrices_both_correct(A, B);
  if(code == OK){
    int rows = A ->rows, cols = A -> columns;
    code = s21_create_matrix(rows, cols, result);
    for(int i= 0; code == OKй && i < result ->rows; i++){
      for(int j = 0; j < result -> columns; j++){
        result -> matrix[i][j] = A -> matrix[i][j] - B -> matrix[i][j];
      }
    }
  }
  else if(A -> rows != B -> rows || A -> columns != B -> columns){
    code = CALC_ERROR;
  }
  return code;
}

int is_sizes_equals(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    code = FAILURE;
  }
  return code;
}

int is_matrix_correct(matrix_t *A) {
  int status_code = OK;
  if (A == NULL ||  (A->matrix == NULL) || A->rows <= 0 || A -> columns <=0) {
      status_code = ERROR;
  }
  else {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        status_code = ERROR;
        break;
      }
    }
  }
  return status_code;
}

int is_matrices_both_correct(matrix_t *A, matrix_t *B ){
    int code1 = is_matrix_correct(A), code2 = is_matrix_correct(B);
    int status_code = OK;
    if(code1 == ERROR || code2 == ERROR){
        status_code = ERROR;
    } else if( A -> rows != B -> rows || A -> columns != B ->columns){
        status_code = CALC_ERROR;
    }
    return status_code;
}