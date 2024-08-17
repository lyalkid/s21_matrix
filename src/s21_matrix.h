#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

enum eq{FAILURE, SUCCESS};
#define eps 1e-7
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int is_sizes_equals(matrix_t* A, matrix_t* B);
int is_matrix_correct(matrix_t *A);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);



#endif // S21_MATRIX_H
