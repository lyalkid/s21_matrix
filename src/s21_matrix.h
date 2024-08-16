#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <stdlib.h>
#include <stdio.h>

/* 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)
 * */
enum status{OK, ERROR, CALC_ERROR};

typedef struct matrix_struct {
    int rows;
    int columns;
    double** matrix;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

void out_matrix(matrix_t matrix);

#endif // S21_MATRIX_H
