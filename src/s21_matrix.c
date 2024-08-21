#include "s21_matrix.h"

#include "helpers.h"

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
  A->rows = 0, A->columns = 0;
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
  int code = is_matrices_correct(A, B, SUM);
  if (code == OK) {
    int rows = A->rows, cols = A->columns;
    code = s21_create_matrix(rows, cols, result);
    for (int i = 0; code == OK && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = is_matrices_correct(A, B, SUB);
  if (code == OK) {
    int rows = A->rows, cols = A->columns;
    code = s21_create_matrix(rows, cols, result);
    for (int i = 0; code == OK && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
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
  if (A == NULL || (A->matrix == NULL) || A->rows <= 0 || A->columns <= 0) {
    status_code = ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] == NULL) {
        status_code = ERROR;
        break;
      }
    }
  }
  return status_code;
}

int is_matrices_correct(matrix_t *A, matrix_t *B, int operation) {
  int code1 = is_matrix_correct(A), code2 = is_matrix_correct(B);
  int status_code = OK;
  if (code1 == ERROR || code2 == ERROR) {
    status_code = ERROR;
  } else if (((A->rows != B->rows || A->columns != B->columns) &&
              (operation == SUM || operation == SUB)) ||
             (operation == MULT && A->columns != B->rows)) {
    status_code = CALC_ERROR;
  }
  return status_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = is_matrix_correct(A);
  if (code == OK) {
    int rows = A->rows, columns = A->columns;
    code = s21_create_matrix(rows, columns, result);
    for (int i = 0; code == OK && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = is_matrices_correct(A, B, MULT);
  if (code == OK) {
    int rows = A->rows, cols = B->columns;
    code = s21_create_matrix(rows, cols, result);
    int t = A->columns;
    for (int i = 0; t >= 0 && code == OK && i < result->rows; i++, t--) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = mult_vectors_sum(*A, *B, i, j);
      }
    }
  }
  return code;
}

double mult_vectors_sum(matrix_t A, matrix_t B, int i, int j) {
  double sum = 0;
  int len = A.columns;

  for (int k = 0; k < len; k++) {
    sum += A.matrix[i][k] * B.matrix[k][j];
  }
  return sum;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = is_matrix_correct(A);
  if (code == OK) {
    int rows = A->columns, columns = A->rows;
    code = s21_create_matrix(rows, columns, result);
    for (int i = 0; code == OK && i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return code;
}
int s21_determinant(matrix_t *A, double *result) {
  int code = is_matrix_correct(A) == OK && A->rows == A->columns && result ? OK
             : is_matrix_correct(A) == ERROR || !result ? ERROR
                                                        : CALC_ERROR;
  int scale;
  if (code == OK) scale = A->rows;
  if (code == OK && scale == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (code == OK && scale == 1) {
    *result = A->matrix[0][0];
  } else if (code == OK && scale > 2) {
    double det = 0;
    for (int i = 0; i < A->rows; i++) {
      double tmp = A->matrix[0][i];

      matrix_t minor = get_minor(*A, 0, i);
      if (tmp != 0) {
        code = s21_determinant(&minor, &det);
      } else {
        det = 0;
      }
      s21_remove_matrix(&minor);
      int sign = (i) % 2 == 0 ? 1 : -1;
      *result += det * tmp * sign;
      det = 0;
    }
  }

  return code;
}

matrix_t get_minor(matrix_t A, int i, int j) {
  int scale = A.rows;
  matrix_t b = {};
  if (A.rows > 1) {
    scale = A.rows - 1;
    int m = 0, n = 0;  // счетчики для минора
    int code = s21_create_matrix(scale, scale, &b);
    for (int k = 0; code == OK && k < A.rows; k++) {
      if (k == i) {
        continue;
      }
      n = 0;
      for (int g = 0; g < A.columns; g++) {
        if (g == j) {
          continue;
        }
        double tmp = A.matrix[k][g];
        b.matrix[m][n] = tmp;
        n++;
      }
      //    if (m < scale)
      m++;
    }
  } else {
    s21_create_matrix(1, 1, &b);
    int sign = (i + j + 2) % 2 == 0 ? 1 : -1;
    b.matrix[0][0] = 1 * sign;
  }
  return b;
};

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = is_matrix_correct(A);

  if (code == OK && A->rows == A->columns) {
    int rows = A->rows, columns = A->columns;
    code = s21_create_matrix(rows, columns, result);
    for (int i = 0; code == OK && i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        double det = 0;
        matrix_t minor = get_minor(*A, i, j);

        code = s21_determinant(&minor, &det);
        s21_remove_matrix(&minor);
        int sign = (i + j + 2) % 2 == 0 ? 1 : -1;
        result->matrix[i][j] = det * sign;
      }
    }
  } else if (code == OK) {
    code = CALC_ERROR;
  }
  return code;
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = is_matrix_correct(A) == OK && A->rows == A->columns ? OK
             : is_matrix_correct(A) == ERROR                     ? ERROR
                                                                 : CALC_ERROR;
  double det = 0;
  matrix_t calc_comp = {};
  matrix_t calc_comp_tr = {};

  if (code == OK) {
    code = s21_determinant(A, &det);
  }
  if (code == OK && det != 0) {
    code = s21_calc_complements(A, &calc_comp);

    code = s21_transpose(&calc_comp, &calc_comp_tr);

    code = s21_create_matrix(calc_comp_tr.rows, calc_comp_tr.columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        double tmp = 1 / det;
        result->matrix[i][j] = calc_comp_tr.matrix[i][j] * tmp;
      }
    }
    s21_remove_matrix(&calc_comp);
    s21_remove_matrix(&calc_comp_tr);
  } else if (code == OK) {
    code = CALC_ERROR;
  }
  return code;
}
