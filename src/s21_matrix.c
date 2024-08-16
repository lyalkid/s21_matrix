#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result){
    if(rows <= 0 || columns <= 0) return  ERROR;
    result -> columns = columns;
    result -> rows = rows;
    double** matrix = malloc(rows * (sizeof (double *)));
    if(matrix == NULL  ) return ERROR;
    for(int i = 0; i < rows; i++){
        matrix[i] = calloc(columns, sizeof(double));
        if(matrix[i] == NULL) return ERROR;
    }
    result -> matrix = matrix;
    return OK;
}


void s21_remove_matrix(matrix_t *A){
    for(int i = 0; i < A -> rows; i++){
        free(A->matrix[i]);
    }
    free(A->matrix);
}

void out_matrix(matrix_t matrix){
    int cols = matrix.columns;
    int rows = matrix.rows;
    for(int i = 0; i <  rows;i++ ){
        for(int j = 0; j < cols-1; j++){
            printf("%lf ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}