#include "test.h"
// S21_EQ_MATRIX

START_TEST(eq_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double k = 1.0;
  double g = 2.5;
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
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(4, 5, &A);
  s21_create_matrix(3, 3, &B);
  double k = 1.0;
  double g = 2.5;
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
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double g = 2.5;
  double k = 2.5;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = g;
      g++;
    }
  }
  for (int i = 0; i < B.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      B.matrix[i][j] = k;
      k++;
    }
  }
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double k = 1.0;
  double g = 1.0;
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
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double k = 1.0000000;
  double g = 1.0000001;
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
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  double k = 1.0000000;
  double g = 1.00000001;
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
  int ret_value = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(ret_value, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_matrix_equals(void) {
  Suite *s1 = suite_create("EQUALS");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, eq_matrix_1);
  tcase_add_test(tc1_1, eq_matrix_2);
  tcase_add_test(tc1_1, eq_matrix_3);
  tcase_add_test(tc1_1, eq_matrix_4);
  tcase_add_test(tc1_1, eq_matrix_5);
  tcase_add_test(tc1_1, eq_matrix_6);

  suite_add_tcase(s1, tc1_1);
  return s1;
}