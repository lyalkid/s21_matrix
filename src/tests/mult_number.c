#include "test.h"

START_TEST(mult_number_1) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5;
  double f = 3.25;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5134512;
  double f = 3.2674866;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5134512;
  double f = 3.2674866;
  double value = 1.3;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f += 1.3;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(0, 3, &A);
  double value = 1.3;
  int ret_value = s21_mult_number(&A, value, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_5) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(0, 3, &A);
  double value = NAN;
  int ret_value = s21_mult_number(&A, value, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_6) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  double k = 2.5134512;
  double f = -5.9229478;
  double value = -2.3565;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = k;
      k++;
    }
  }
  for (int i = 0; i < correct.rows; i++) {
    for (int j = 0; j < correct.columns; j++) {
      correct.matrix[i][j] = f;
      f -= 2.3565;
    }
  }
  int ret_value = s21_mult_number(&A, value, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(mult_number_7) {
  matrix_t A = {0};
  matrix_t *res = NULL;
  s21_create_matrix(3, 3, &A);
  double value = 0;
  int ret_value = s21_mult_number(&A, value, res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_8) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  s21_create_matrix(3, 3, A);
  double value = 0;
  int ret_value = s21_mult_number(A, value, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_matrix_mult_number(void) {
  Suite *s1 = suite_create("MULT NUMBER");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, mult_number_1);
  tcase_add_test(tc1_1, mult_number_2);
  tcase_add_test(tc1_1, mult_number_3);
  tcase_add_test(tc1_1, mult_number_4);
  tcase_add_test(tc1_1, mult_number_5);
  tcase_add_test(tc1_1, mult_number_6);
  tcase_add_test(tc1_1, mult_number_7);
  tcase_add_test(tc1_1, mult_number_8);
  suite_add_tcase(s1, tc1_1);
  return s1;
}