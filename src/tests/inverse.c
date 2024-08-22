#include "test.h"

START_TEST(inverse_matrix_1) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &correct);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = -2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = -7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  correct.matrix[0][0] = -0.2352941;
  correct.matrix[0][1] = 0.2058824;
  correct.matrix[0][2] = -0.0588235;
  correct.matrix[1][0] = -0.3823529;
  correct.matrix[1][1] = 0.1470588;
  correct.matrix[1][2] = 0.0294118;
  correct.matrix[2][0] = 0.1568627;
  correct.matrix[2][1] = 0.0294118;
  correct.matrix[2][2] = 0.0392157;
  int ret_value = s21_inverse_matrix(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &correct);
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

  correct.matrix[0][0] = 0.2;
  correct.matrix[0][1] = -1.6;
  correct.matrix[0][2] = -4;
  correct.matrix[0][3] = 0.8;
  correct.matrix[1][0] = 0;
  correct.matrix[1][1] = 1;
  correct.matrix[1][2] = 2.5;
  correct.matrix[1][3] = -0.3333333;
  correct.matrix[2][0] = 0;
  correct.matrix[2][1] = 0;
  correct.matrix[2][2] = -0.25;
  correct.matrix[2][3] = 0;
  correct.matrix[3][0] = 0;
  correct.matrix[3][1] = 0;
  correct.matrix[3][2] = 0;
  correct.matrix[3][3] = 0.3333333;
  int ret_value = s21_inverse_matrix(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 3, &A);
  int ret_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(ret_value, CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 0, &A);
  int ret_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &correct);
  A.matrix[0][0] = 48;
  correct.matrix[0][0] = 0.0208333;
  int ret_value = s21_inverse_matrix(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(inverse_matrix_6) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  int ret_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(ret_value, CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  s21_create_matrix(2, 2, A);
  int ret_value = s21_inverse_matrix(A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_matrix_inverse(void) {
  Suite *s1 = suite_create("INVERSE");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, inverse_matrix_1);
  tcase_add_test(tc1_1, inverse_matrix_2);
  tcase_add_test(tc1_1, inverse_matrix_3);
  tcase_add_test(tc1_1, inverse_matrix_4);
  tcase_add_test(tc1_1, inverse_matrix_5);
  tcase_add_test(tc1_1, inverse_matrix_6);

  tcase_add_test(tc1_1, inverse_matrix_7);
  suite_add_tcase(s1, tc1_1);
  return s1;
}