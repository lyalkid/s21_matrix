#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum status { OK, ERROR, CALC_ERROR };
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

matrix_t get_minor(matrix_t A, int i, int j);

int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
#endif  // S21_MATRIX_H
