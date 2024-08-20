#include <string.h>

#include "helpers.h"
#include "s21_matrix.h"
int main() {
  //  char* file_name = "preset.txt";
  //  FILE* file = fopen(file_name, "r");
  //  if (file == NULL) {
  //    printf("cant open file\n");
  //  }
  //
  //  int num_matrices;
  //
  //  if (fscanf(file, "%d", &num_matrices) != 1) {
  //    printf("Ошибка чтения количества матриц.\n");
  //    fclose(file);
  //    return 1;
  //  } else {
  //    // printf("%d\n", num_matrices);
  //    matrix_t matrices[num_matrices];
  //
  //    for (int i = 0; i < num_matrices; i++) {
  //      matrices[i] = read_matrix_from_file(file);
  //    }
  //    matrix_t result = {};
  //    //     int res = s21_eq_matrix(&matrices[0], &matrices[1]);
  //    //     res ? printf("EQUALS\n") : printf("NOT EQUALS\n");
  //    //     res = s21_sum_matrix(&matrices[0], &matrices[1], &result);
  //
  //    // matrix_t res = {};
  //    out_matrix(matrices[2]);
  //    // printf("__________________\n");
  //    double result_det = 0;
  //    // res = get_minor(matrices[0], 0, 0);
  //    //     int code = s21_transpose(&matrices[0], &res);
  //    int code = s21_determinant(&matrices[2], &result_det);
  //    // out_matrix(res);
  //    printf("det: %lf\n%d\n", result_det, code);
  //  }
  matrix_t A = {0};
  double res = 0;
  double correct = -60;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 8;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 10;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = -4;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 3;
  out_matrix(A);
  int ret_value = s21_determinant(&A, &res);
  printf("det: %lf\n", res);
  ret_value == OK      ? printf("OK\n")
  : ret_value == ERROR ? printf("ERROR\n")
                       : printf("CALC_ERROR\n");
  correct == res ? printf("YES\n") : printf("NO\n");
}