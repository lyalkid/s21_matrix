
#include "test.h"
// S21_CREATE_MATRIX //

START_TEST(create_matrix_1) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(0, 0, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(1, 0, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(1, 1, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_4) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(5, 1, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_5) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(5, 7, &res);
  ck_assert_int_eq(ret_value, S21_OK);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_6) {
  matrix_t res = {0};
  int ret_value = s21_create_matrix(3, -2, &res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(create_matrix_7) {
  matrix_t *res = NULL;
  int ret_value = s21_create_matrix(3, 2, res);
  ck_assert_int_eq(ret_value, S21_INCORRECT);

  // S21_REMOVE_MATRIX
}
END_TEST

Suite *suite_s21_matrix_create(void) {
  Suite *s1 = suite_create("CREATE");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_matrix_1);
  tcase_add_test(tc1_1, create_matrix_2);
  tcase_add_test(tc1_1, create_matrix_3);
  tcase_add_test(tc1_1, create_matrix_4);
  tcase_add_test(tc1_1, create_matrix_5);
  tcase_add_test(tc1_1, create_matrix_6);
  tcase_add_test(tc1_1, create_matrix_7);

  suite_add_tcase(s1, tc1_1);
  return s1;
}