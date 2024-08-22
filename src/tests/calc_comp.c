#include "test.h"

START_TEST(calc_complements_1) {
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

  correct.matrix[0][0] = -48;
  correct.matrix[0][1] = -78;
  correct.matrix[0][2] = 32;
  correct.matrix[1][0] = 42;
  correct.matrix[1][1] = 30;
  correct.matrix[1][2] = 6;
  correct.matrix[2][0] = -12;
  correct.matrix[2][1] = 6;
  correct.matrix[2][2] = 8;
  int ret_value = s21_calc_complements(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(calc_complements_2) {
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

  correct.matrix[0][0] = -12;
  correct.matrix[0][1] = -0;
  correct.matrix[0][2] = 0;
  correct.matrix[0][3] = -0;
  correct.matrix[1][0] = 96;
  correct.matrix[1][1] = -60;
  correct.matrix[1][2] = -0;
  correct.matrix[1][3] = 0;
  correct.matrix[2][0] = 240;
  correct.matrix[2][1] = -150;
  correct.matrix[2][2] = 15;
  correct.matrix[2][3] = -0;
  correct.matrix[3][0] = -48;
  correct.matrix[3][1] = 20;
  correct.matrix[3][2] = -0;
  correct.matrix[3][3] = -20;
  int ret_value = s21_calc_complements(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 3, &A);
  int ret_value = s21_calc_complements(&A, &res);
  ck_assert_int_eq(ret_value, CALC_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t A = {0};
  matrix_t res = {0};
  s21_create_matrix(4, 0, &A);
  int ret_value = s21_calc_complements(&A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_5) {
  matrix_t A = {0};
  matrix_t res = {0};
  matrix_t correct = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &correct);
  A.matrix[0][0] = -48;
  correct.matrix[0][0] = 1;
  int ret_value = s21_calc_complements(&A, &res);
  int equal = s21_eq_matrix(&res, &correct);
  ck_assert_int_eq(ret_value, OK);
  ck_assert_int_eq(equal, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
  s21_remove_matrix(&correct);
}
END_TEST

START_TEST(calc_complements_6) {
  matrix_t A = {0};
  matrix_t *res = NULL;
  s21_create_matrix(1, 1, &A);
  int ret_value = s21_calc_complements(&A, res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_7) {
  matrix_t *A = NULL;
  matrix_t res = {0};
  s21_create_matrix(2, 2, A);
  int ret_value = s21_calc_complements(A, &res);
  ck_assert_int_eq(ret_value, ERROR);
  s21_remove_matrix(&res);
}
END_TEST

Suite *suite_s21_matrix_calc_comp(void) {
  Suite *s1 = suite_create("CALC_COMP");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, calc_complements_1);
  tcase_add_test(tc1_1, calc_complements_2);
  tcase_add_test(tc1_1, calc_complements_3);
  tcase_add_test(tc1_1, calc_complements_4);
  tcase_add_test(tc1_1, calc_complements_5);
  tcase_add_test(tc1_1, calc_complements_6);
  tcase_add_test(tc1_1, calc_complements_7);
  suite_add_tcase(s1, tc1_1);
  return s1;
}