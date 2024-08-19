#include "test.h"

// S21_MULT_MATRIX //
START_TEST(mult_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(4, 5, &B);
  int ret_value = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret_value, S21_CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5;
  double g = 1.3;
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
  correct.matrix[0][0] = 51.1500000;
  correct.matrix[0][1] = 61.6500000;
  correct.matrix[0][2] = 72.1500000;
  correct.matrix[1][0] = 89.8500000;
  correct.matrix[1][1] = 109.3500000;
  correct.matrix[1][2] = 128.8500000;
  correct.matrix[2][0] = 128.5500000;
  correct.matrix[2][1] = 157.0500000;
  correct.matrix[2][2] = 185.5500000;
  int ret_value = s21_mult_matrix(&A, &B, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 4, &B);
  s21_create_matrix(3, 4, &correct);
  double k = 2.5;
  double g = 1.3;
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
  correct.matrix[0][0] = 21.8000000;
  correct.matrix[0][1] = 27.8000000;
  correct.matrix[0][2] = 33.8000000;
  correct.matrix[0][3] = 39.8000000;
  correct.matrix[1][0] = 35.0000000;
  correct.matrix[1][1] = 45.0000000;
  correct.matrix[1][2] = 55.0000000;
  correct.matrix[1][3] = 65.0000000;
  correct.matrix[2][0] = 48.2000000;
  correct.matrix[2][1] = 62.2000000;
  correct.matrix[2][2] = 76.2000000;
  correct.matrix[2][3] = 90.2000000;
  int ret_value = s21_mult_matrix(&A, &B, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, S21_OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  int ret_value = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret_value, S21_CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t res = {0};
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(2, 2, &B);
  int ret_value = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_6) {
  matrix_t A = {0};
  matrix_t *B = NULL;
  matrix_t res = {0};
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(2, 2, B);
  int ret_value = s21_mult_matrix(&A, B, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *res = NULL;
  s21_create_matrix(0, 3, &A);
  s21_create_matrix(2, 2, &B);
  int ret_value = s21_mult_matrix(&A, &B, res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_matrix_mult(void) {
  Suite *s1 = suite_create("MULT");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, mult_matrix_1);
  tcase_add_test(tc1_1, mult_matrix_2);
  tcase_add_test(tc1_1, mult_matrix_3);
  tcase_add_test(tc1_1, mult_matrix_4);
  tcase_add_test(tc1_1, mult_matrix_5);
  tcase_add_test(tc1_1, mult_matrix_6);
  tcase_add_test(tc1_1, mult_matrix_7);

  suite_add_tcase(s1, tc1_1);
  return s1;
}