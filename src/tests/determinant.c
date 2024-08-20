#include "test.h"

//   // S21_DETERMINANT //

START_TEST(determinant_1) {
  matrix_t A = {0};
  double res = 0;
  double correct = 0;
  s21_create_matrix(3, 3, &A);
  double k = 2.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_double_eq(res, correct);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
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
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_double_eq(res, correct);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {0};
  double res = 0;
  double correct = 204;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = -7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_double_eq(res, correct);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t A = {0};
  double res = 0;
  double correct = 85.656;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 85.656;
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_double_eq(res, correct);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A = {0};
  double res = 0;
  s21_create_matrix(1, 2, &A);
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t A = {0};
  double res = 0;
  s21_create_matrix(2, 0, &A);
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_7) {
  matrix_t A = {0};
  double res = 0;
  double correct = 0;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  int ret_value = s21_determinant(&A, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_double_eq(res, correct);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_8) {
  matrix_t A = {0};
  double *res = NULL;
  s21_create_matrix(2, 2, &A);
  int ret_value = s21_determinant(&A, res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  matrix_t *A = NULL;
  double res = 0;
  s21_create_matrix(2, 2, A);
  int ret_value = s21_determinant(A, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
}
END_TEST

Suite *suite_s21_matrix_det(void) {
  Suite *s1 = suite_create("DETERMINANT");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, determinant_1);
  tcase_add_test(tc1_1, determinant_2);
  tcase_add_test(tc1_1, determinant_3);
  tcase_add_test(tc1_1, determinant_4);
  tcase_add_test(tc1_1, determinant_5);
  tcase_add_test(tc1_1, determinant_6);
  tcase_add_test(tc1_1, determinant_7);
  tcase_add_test(tc1_1, determinant_8);
  tcase_add_test(tc1_1, determinant_9);
  suite_add_tcase(s1, tc1_1);
  return s1;
}