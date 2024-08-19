#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* 0 - OK
 * 1 - Error, incorrect matrix
 * 2 - Calculation error (mismatched matrix sizes; matrix for which calculations
 * cannot be performed, etc.)
 * */
enum status { OK, ERROR, CALC_ERROR };
enum s21_status { S21_OK, S21_INCORRECT, S21_CALC_ERROR };
typedef struct matrix_struct {
  int rows;
  int columns;
  double **matrix;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

enum eq { FAILURE, SUCCESS };
#define eps 1e-7
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int is_sizes_equals(matrix_t *A, matrix_t *B);
int is_matrix_correct(matrix_t *A);

enum operations { SUM, SUB, MULT, MULT_NUMBER };
int is_matrices_correct(matrix_t *A, matrix_t *B, int operation);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
double mult_vectors_sum(matrix_t A, matrix_t B, int i, int j);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
#endif  // S21_MATRIX_H
