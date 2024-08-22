#include "test.h"

START_TEST(transpose_1) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &correct);
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.columns; i++) {
    for (int j = 0; j < correct.rows; j++) {
      correct.matrix[j][i] = f;
      f++;
    }
  }
  int ret_value = s21_transpose(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &correct);
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.columns; i++) {
    for (int j = 0; j < correct.rows; j++) {
      correct.matrix[j][i] = f;
      f++;
    }
  }
  int ret_value = s21_transpose(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(2, -2, &A);
  int ret_value = s21_transpose(&A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &correct);
  double k = 2.5;
  double f = 2.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.columns; i++) {
    for (int j = 0; j < correct.rows; j++) {
      correct.matrix[j][i] = f;
      f++;
    }
  }
  int ret_value = s21_transpose(&A, &res);
  ck_assert_int_eq(ret_value, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(transpose_5) {
  matrix_t A = {0};
  matrix_t *res = NULL;
  s21_create_matrix(1, 1, &A);
  int ret_value = s21_transpose(&A, res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_6) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  s21_create_matrix(1, 1, A);
  int ret_value = s21_transpose(A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_matrix_transpose(void) {
  Suite *s1 = suite_create("TRANSPOSE");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, transpose_1);
  tcase_add_test(tc1_1, transpose_2);
  tcase_add_test(tc1_1, transpose_3);
  tcase_add_test(tc1_1, transpose_4);
  tcase_add_test(tc1_1, transpose_5);
  tcase_add_test(tc1_1, transpose_6);
  suite_add_tcase(s1, tc1_1);
  return s1;
}