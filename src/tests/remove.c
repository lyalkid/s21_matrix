#include "test.h"

START_TEST(remove_matrix_1) {
  matrix_t res = {0};
  s21_create_matrix(5, 4, &res);
  s21_remove_matrix(&res);
  ck_assert_int_eq(res.rows, 0);
  ck_assert_int_eq(res.columns, 0);
  ck_assert_ptr_eq(res.matrix, NULL);
}
END_TEST

Suite *suite_s21_matrix_remove(void) {
  Suite *s1 = suite_create("REMOVE");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, remove_matrix_1);
  suite_add_tcase(s1, tc1_1);
  return s1;
}