#include "helpers.h"

void out_matrix(matrix_t matrix) {
  int cols = matrix.columns;
  int rows = matrix.rows;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j == cols - 1) {
        printf("%lf\n", matrix.matrix[i][j]);
      } else {
        printf("%lf ", matrix.matrix[i][j]);
      }
    }
  }
}

matrix_t read_matrix_from_file(FILE* file) {
  int rows, columns;

  matrix_t mat = {};
  // Считываем количество строк и столбцов для матрицы
  if (fscanf(file, "%d %d", &rows, &columns) != 2) {
    return mat;  // Ошибка чтения размеров или конец файла
  }

  int code = s21_create_matrix(rows, columns, &mat);

  // Считываем элементы матрицы
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double tmp;
      if (fscanf(file, "%lf", &tmp) != 1) {
        printf("Ошибка чтения элемента матрицы.\n");
        s21_remove_matrix(&mat);
        exit(EXIT_FAILURE);
      } else {
        int c;
        mat.matrix[i][j] = tmp;
      }
    }
  }

  return mat;
}
