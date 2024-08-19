#ifndef S21_TESTS_H
#define S21_TESTS_H
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../s21_matrix.h"


Suite *suite_s21_matrix_sum(void);
Suite *suite_s21_matrix_create(void);
Suite *suite_s21_matrix_equals(void);
Suite *suite_s21_matrix_remove(void);
Suite *suite_s21_matrix_sub(void);
Suite *suite_s21_matrix_mult_number(void);
Suite *suite_s21_matrix_mult(void);
Suite *suite_s21_matrix_transpose(void);
#endif //S21_TESTS_H