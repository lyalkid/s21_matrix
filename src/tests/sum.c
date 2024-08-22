
#include "test.h"

START_TEST(sum_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &correct);
  double k = 1.0;
  double g = 2.5;
  double f = 3.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = g;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f++;
    }
  }
  int ret_value = s21_sum_matrix(&A, &B, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(sum_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &correct);
  double k = 1.0;
  double g = 2.5;
  double f = 3.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = g;
      g++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 2;
    }
  }
  int ret_value = s21_sum_matrix(&A, &B, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(sum_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);
  int ret_value = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret_value, CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(0, 2, &A);
  s21_create_matrix(3, 3, &B);
  int ret_value = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *res = NULL;
  s21_create_matrix(0, 2, &A);
  s21_create_matrix(3, 3, &B);
  int ret_value = s21_sum_matrix(&A, &B, res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_6) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(0, 2, A);
  s21_create_matrix(3, 3, &B);
  int ret_value = s21_sum_matrix(A, &B, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_matrix_sum(void) {
  Suite *s1 = suite_create("SUM");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, sum_matrix_1);
  tcase_add_test(tc1_1, sum_matrix_2);
  tcase_add_test(tc1_1, sum_matrix_3);
  tcase_add_test(tc1_1, sum_matrix_4);
  tcase_add_test(tc1_1, sum_matrix_5);
  tcase_add_test(tc1_1, sum_matrix_6);
  suite_add_tcase(s1, tc1_1);
  return s1;
}