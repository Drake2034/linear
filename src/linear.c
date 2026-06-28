#include <stdlib.h>
#include <stdio.h>

#include "linear/linear.h"

void sayHi(){ printf("linear: HI\n"); }

matrix_t* initMatrix(int rows, int cols, double data[rows][cols]){
    matrix_t* new_matrix = malloc(sizeof *new_matrix);
    if(!new_matrix) return NULL;

    new_matrix->cols = cols; new_matrix->rows = rows;
    new_matrix->data = calloc(rows, sizeof(double*));
    if(!new_matrix->data){
        free(new_matrix); return NULL;
    }

    for(int i = 0; i < rows; ++i){
        new_matrix->data[i] = calloc(cols, sizeof(double));
        if(!new_matrix->data[i]){
            for(int j = 0; j < i; j++){
                free(new_matrix->data[j]);
            }
            free(new_matrix->data); free(new_matrix);
            return NULL;
        }
    }

    //TODO
//    size_t data_size = sizeof(data[0]) * sizeof(data[0][0]);
//    printf("data: %zu\n", data_size);
//    size_t matrix_size = sizeof(new_matrix->data[0]) * sizeof(new_matrix->data[0][0]);
//    printf("matrix: %zu\n", matrix_size);
//
//    if(matrix_size * 2 != data_size){
//        printf("[ERR]: invalid size returned %d x %d matrix (please use correct size)\n", rows, cols);
//        return new_matrix;
//    }

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            new_matrix->data[i][j] = data[i][j];
        }
    }
    return new_matrix;
}

void printMatrix(matrix_t* matrix){
    if(!matrix) return;    
    printf("\n");
    for(int i = 0; i < matrix->rows; ++i){
        for(int j = 0; j < matrix->cols; ++j){
            printf("%f ", matrix->data[i][j]);
        }
    }
    printf("\n");
}

void prettyPrintMatrix(matrix_t* matrix /* , const char* options */){
    if(!matrix) return;
    printf("\n");
    for(int i = 0; i < matrix->rows; ++i){
        for(int j = 0; j < matrix->cols; ++j){
            if(j == 0){
                printf("| ");
            }
            printf("%f ", matrix->data[i][j]);
            if(j == matrix->cols - 1){
                printf("|\n");
            }
        }
    }
}