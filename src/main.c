#include <string.h>

#include "helpers.h"
#include "s21_matrix.h"
int main() {
  char* file_name = "matrix.txt";
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("cant open file\n");
  }

  int num_matrices;

  if (fscanf(file, "%d", &num_matrices) != 1) {
    printf("Ошибка чтения количества матриц.\n");
    fclose(file);
    return 1;
  } else {
    // printf("%d\n", num_matrices);
    matrix_t matrices[num_matrices];

    for (int i = 0; i < num_matrices; i++) {
      matrices[i] = read_matrix_from_file(file);
    }
    matrix_t  result = {};
    int res = s21_eq_matrix(&matrices[0], &matrices[1]);
    res ? printf("EQUALS\n") : printf("NOT EQUALS\n");
    res = s21_sum_matrix(&matrices[0], &matrices[1], &result);

  }
}