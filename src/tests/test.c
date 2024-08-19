#include "test.h"
int main(void) {
  int all = 0, successed = 0, failed = 0;
  Suite *suite[] = {suite_s21_matrix_create(), suite_s21_matrix_remove(),
                    suite_s21_matrix_equals(), suite_s21_matrix_sum(),
                    suite_s21_matrix_sub(),    suite_s21_matrix_mult_number(),
                    suite_s21_matrix_mult(), suite_s21_matrix_transpose(),   NULL};

  for (int i = 0; suite[i] != NULL; i++) {
    SRunner *sr = srunner_create(suite[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    all += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  successed = all - failed;

  printf(
      "========= ALL: %d ========= SUCCESSED: %d ========= FAILED: %d "
      "=========\n%.2f percents\n",
      all, successed, failed, ((float)successed / all) * 100);

  return failed == 0 ? 0 : 1;
}

// Suite *suite_s21_matrix_tests(void){
//     Suite *s1 = suite_create("Core");
//     TCase *tc1_1 = tcase_create("Core");
//     suite_add_tcase(s1, tc1_1);
//     tcase_add_test(tc1_1, create_matrix_1);
//     tcase_add_test(tc1_1, create_matrix_2);
//     tcase_add_test(tc1_1, create_matrix_3);
//     tcase_add_test(tc1_1, create_matrix_4);
//     tcase_add_test(tc1_1, create_matrix_5);
//     tcase_add_test(tc1_1, create_matrix_6);
//     tcase_add_test(tc1_1, create_matrix_7);
//     tcase_add_test(tc1_1, remove_matrix_1);
//     tcase_add_test(tc1_1, eq_matrix_1);
//     tcase_add_test(tc1_1, eq_matrix_2);
//     tcase_add_test(tc1_1, eq_matrix_3);
//     tcase_add_test(tc1_1, eq_matrix_4);
//     tcase_add_test(tc1_1, eq_matrix_5);
//     tcase_add_test(tc1_1, eq_matrix_6);
//     tcase_add_test(tc1_1, sum_matrix_1);
//     tcase_add_test(tc1_1, sum_matrix_2);
//     tcase_add_test(tc1_1, sum_matrix_3);
//     tcase_add_test(tc1_1, sum_matrix_4);
//     tcase_add_test(tc1_1, sum_matrix_5);
//     tcase_add_test(tc1_1, sum_matrix_6);
//     tcase_add_test(tc1_1, sub_matrix_1);
//     tcase_add_test(tc1_1, sub_matrix_2);
//     tcase_add_test(tc1_1, sub_matrix_3);
//     tcase_add_test(tc1_1, sub_matrix_4);
//     tcase_add_test(tc1_1, sub_matrix_5);
//     tcase_add_test(tc1_1, sub_matrix_6);
//     tcase_add_test(tc1_1, sub_matrix_7);
// tcase_add_test(tc1_1, mult_number_1);
// tcase_add_test(tc1_1, mult_number_2);
// tcase_add_test(tc1_1, mult_number_3);
// tcase_add_test(tc1_1, mult_number_4);
// tcase_add_test(tc1_1, mult_number_5);
// tcase_add_test(tc1_1, mult_number_6);
// tcase_add_test(tc1_1, mult_number_7);
// tcase_add_test(tc1_1, mult_number_8);
// tcase_add_test(tc1_1, mult_matrix_1);
// tcase_add_test(tc1_1, mult_matrix_2);
// tcase_add_test(tc1_1, mult_matrix_3);
// tcase_add_test(tc1_1, mult_matrix_4);
// tcase_add_test(tc1_1, mult_matrix_5);
// tcase_add_test(tc1_1, mult_matrix_6);
// tcase_add_test(tc1_1, mult_matrix_7);
// tcase_add_test(tc1_1, transpose_1);
// tcase_add_test(tc1_1, transpose_2);
// tcase_add_test(tc1_1, transpose_3);
// tcase_add_test(tc1_1, transpose_4);
// tcase_add_test(tc1_1, transpose_5);
// tcase_add_test(tc1_1, transpose_6);
// tcase_add_test(tc1_1, determinant_1);
// tcase_add_test(tc1_1, determinant_2);
// tcase_add_test(tc1_1, determinant_3);
// tcase_add_test(tc1_1, determinant_4);
// tcase_add_test(tc1_1, determinant_5);
// tcase_add_test(tc1_1, determinant_6);
// tcase_add_test(tc1_1, determinant_7);
// tcase_add_test(tc1_1, determinant_8);
// tcase_add_test(tc1_1, determinant_9);
// tcase_add_test(tc1_1, calc_complements_1);
// tcase_add_test(tc1_1, calc_complements_2);
// tcase_add_test(tc1_1, calc_complements_3);
// tcase_add_test(tc1_1, calc_complements_4);
// tcase_add_test(tc1_1, calc_complements_5);
// tcase_add_test(tc1_1, calc_complements_6);
// tcase_add_test(tc1_1, calc_complements_7);
// tcase_add_test(tc1_1, inverse_matrix_1);
// tcase_add_test(tc1_1, inverse_matrix_2);
// tcase_add_test(tc1_1, inverse_matrix_3);
// tcase_add_test(tc1_1, inverse_matrix_4);
// tcase_add_test(tc1_1, inverse_matrix_5);
// tcase_add_test(tc1_1, inverse_matrix_6);
// tcase_add_test(tc1_1, inverse_matrix_7);
// tcase_add_test(tc1_1, inverse_matrix_8);
//     suite_add_tcase(s1, tc1_1);
//     return s1;
//
// }