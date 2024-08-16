#include "s21_matrix.h"


int main(){
    matrix_t result = {};
    int rows = 4;
    int cols = 5;

    int res = s21_create_matrix(rows, cols, &result);
    out_matrix(result);
    s21_remove_matrix(&result);
}