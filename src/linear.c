#include "linear/linear.h"

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

void sayHi(){ printf("linear: HI\n"); }

vector_t* initVector(size_t size, const scalar_t data[size]){
    vector_t* new_vector = malloc(sizeof *new_vector);
    if(!new_vector) return NULL;

    new_vector->size = size;
    new_vector->data = calloc(size, sizeof(scalar_t));
    if(!new_vector->data){
        free(new_vector); return NULL;
    }
    
    if(!data) return new_vector;

    for(size_t i = 0; i < size; ++i)new_vector->data[i] = data[i];
    return new_vector;
}

void destroyVector(vector_t* vector){
    free(vector->data); free(vector);
}

vector_t* copyVector(vector_t* src){
    vector_t* dest = initVector(src->size, NULL);
    if(!dest) return NULL;
    for(size_t i = 0; i < src->size; ++i) dest->data[i] = src->data[i];
    return dest;
}

vector_t* nullVector(size_t size){
    return initVector(size, NULL);
}

int isnull(vector_t* vector){
    for(size_t i = 0; i < vector->size; ++i) if(vector->data[i] != 0) return 0;
    return 1;
}

void setVectorData(vector_t* vector, scalar_t data[vector->size]){
    for(size_t i = 0; i < vector->size; ++i) vector->data[i] = data[i];
}

scalar_t* getVectorData(vector_t* vector){
    scalar_t* vector_data = calloc(vector->size, sizeof(scalar_t));
    if(!vector_data) return NULL;
    for(size_t i = 0; i < vector->size; ++i) vector_data[i] = vector->data[i];
    return vector_data;
}

scalar_t vectorMagnitude(vector_t* vector){
    scalar_t sum = 0;
    for(size_t i = 0; i < vector->size; ++i) sum += vector->data[i] * vector->data[i];
    return (scalar_t)sqrt(sum);
}

vector_t* vectorAddition(vector_t* vec1, vector_t* vec2){
    if(vec1->size != vec2->size) return NULL;

    vector_t* out_vec = initVector(vec1->size, NULL);
    if(!out_vec) return NULL;

    for(size_t i = 0; i < vec1->size; ++i) out_vec->data[i] = vec1->data[i] + vec2->data[i];
    return out_vec;
}

vector_t* vectorSubtraction(vector_t* vec1, vector_t* vec2){
    if(vec1->size != vec2->size) return NULL;

    vector_t* out_vec = initVector(vec1->size, NULL);
    if(!out_vec) return NULL;

    for(size_t i = 0; i < vec1->size; ++i) out_vec->data[i] = vec1->data[i] - vec2->data[i];
    return out_vec;
}

vector_t* vectorScalarMultiplication(scalar_t scalar, vector_t* vector){
    vector_t* out_vec = copyVector(vector);
    if(!out_vec) return NULL;
    for(size_t i = 0; i < vector->size; ++i) out_vec->data[i] *= scalar;
    return out_vec;
}

scalar_t vectorDotProduct(vector_t* vec1, vector_t* vec2){
    if(vec1->size != vec2->size) return 0;
    scalar_t out = 0.0;
    for(size_t i = 0; i < vec1->size; i++) out += (vec1->data[i] * vec2->data[i]);
    return out;
}

vector_t* vectorCrossProduct(vector_t* vec1, vector_t* vec2){
    if(vec1->size != vec2->size || vec1->size > 3 || vec2->size > 3) return NULL;

    if(vec1->size == 2){
        vector_t* out_vec = initVector(1, (scalar_t[1]){
            (vec1->data[0] * vec2->data[1]) - (vec1->data[1] * vec2->data[0]) 
        });
        return out_vec ? out_vec : NULL;
    }else if(vec1->size == 3){
        vector_t* out_vec = initVector(3, (scalar_t[3]){
            (vec1->data[1] * vec2->data[2]) - (vec1->data[2] * vec2->data[1]),
            (vec1->data[2] * vec2->data[0]) - (vec1->data[0] * vec2->data[2]),
            (vec1->data[0] * vec2->data[1]) - (vec1->data[1] * vec2->data[0])
        });
        return out_vec ? out_vec : NULL;
    }else return NULL;
}

void printVector(vector_t* vector){
    for(size_t i = 0; i < vector->size; ++i){
        printf("%.1f ",vector->data[i]);
    }
    printf("\n");
}

//TODO
void prettyPrintVector(vector_t* vector/*, const char* options*/){
    for(size_t i = 0; i < vector->size; ++i){
        printf("%.1f ",vector->data[i]);
    }
    printf("\n");
}

matrix_t* initMatrix(size_t rows, size_t cols, const scalar_t data[rows][cols]){

    matrix_t* new_matrix = malloc(sizeof *new_matrix);
    if(!new_matrix) return NULL;

    new_matrix->cols = cols; new_matrix->rows = rows;
    new_matrix->data = calloc(rows, sizeof(scalar_t*));
    if(!new_matrix->data){
        free(new_matrix); return NULL;
    }

    for(size_t i = 0; i < rows; ++i){
        new_matrix->data[i] = calloc(cols, sizeof(scalar_t));
        if(!new_matrix->data[i]){
            for(size_t j = 0; j < i; j++){
                free(new_matrix->data[j]);
            }
            free(new_matrix->data); free(new_matrix);
            return NULL;
        }
    }

    if(!data) return new_matrix;

    for(size_t i = 0; i < rows; ++i){
        for(size_t j = 0; j < cols; ++j){
            new_matrix->data[i][j] = data[i][j];
        }
    }
    return new_matrix;
}

void destroyMatrix(matrix_t* matrix){
    for(size_t i = 0; i < matrix->rows; ++i) free(matrix->data[i]);
    free(matrix->data); free(matrix);
}

matrix_t* copyMatrix(matrix_t* src){
    matrix_t* dest = initMatrix(src->rows, src->cols, NULL);
    if(!dest) return NULL;

    for(size_t i = 0; i < src->rows; ++i){
        for(size_t j = 0; j < src->cols; ++j){
            dest->data[i][j] = src->data[i][j];
        }
    }
    return dest;
}

matrix_t* nullMatrix(size_t rows, size_t cols){
    return initMatrix(rows, cols, NULL);
}

matrix_t* iMatrix(size_t size){
    matrix_t* identity_matrix = initMatrix(size, size, NULL);
    if(!identity_matrix) return NULL;
    for(size_t i = 0; i < size; ++i) identity_matrix->data[i][i] = 1;
    return identity_matrix;
}

matrix_t* diagMatrix(size_t size, scalar_t data[size]){
    matrix_t* diagonal_matrix = initMatrix(size, size, NULL);
    if(!diagonal_matrix) return NULL;
    for(size_t i = 0; i < size; ++i) diagonal_matrix->data[i][i] = data[i];
    return diagonal_matrix;
}

void setMatrixData(matrix_t* matrix, scalar_t data[matrix->rows][matrix->cols]){
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            matrix->data[i][j] = data[i][j];
        }
    }
}

scalar_t** getMatrixData(matrix_t* matrix){
    scalar_t** matrix_data = calloc(matrix->rows, sizeof(scalar_t*));
    if(!matrix_data) return NULL;
    for(size_t i = 0; i < matrix->cols; ++i){
        matrix_data[i] = calloc(matrix->cols, sizeof(scalar_t));
        if(!matrix_data[i]){
            for(size_t j = 0; j < i; ++j){
                free(matrix_data[i]); free(matrix_data);
                return NULL;
            }
        }
    }

    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; j++){
            matrix_data[i][j] = matrix->data[i][j];
        }
    }

    return matrix_data;
}

void freeData(scalar_t** data, size_t size){
    for(size_t i = 0; i < size; ++i){
        free(data[i]);
    }
    free(data);
}

scalar_t det(matrix_t* matrix){
    if(matrix->cols != matrix->rows) return 0;
    if(matrix->cols == 1) return matrix->data[0][0];
    if(matrix->cols == 2){
        return
        (matrix->data[0][0] * matrix->data[1][1]) -
        (matrix->data[1][0] * matrix->data[0][1]);
    }

    matrix_t* temp_matrix = copyMatrix(matrix);
    if(!temp_matrix) return 0;

    scalar_t determinant = 1.0f;
    for(size_t i = 0; i < matrix->rows; ++i){
        size_t pivot = i;
        for(size_t j = 0; j < matrix->cols; ++j){
            if(abs(temp_matrix->data[i][j] > abs(temp_matrix->data[pivot][j]))){
                pivot = j;
            }
        }

        if(temp_matrix->data[i][pivot] == 0){
            destroyMatrix(temp_matrix); return 0;
        }

        if(pivot != i){
            scalar_t* temp = temp_matrix->data[i];
            temp_matrix->data[i] = temp_matrix->data[pivot];
            temp_matrix->data[pivot] = temp;
            determinant = -determinant;
        }

        for(size_t j = i + 1; j < matrix->cols; j++){
            scalar_t factor = temp_matrix->data[j][i] / temp_matrix->data[i][i];
            for(size_t k = i; k < matrix->cols; k++){
                temp_matrix->data[j][k] -= factor * temp_matrix->data[i][k];
            }
        }
        determinant *= temp_matrix->data[i][i];
    }
    destroyMatrix(temp_matrix);
    return determinant;
}

scalar_t detR(size_t rows, size_t cols, scalar_t data[rows][cols]){
    if(rows != cols) return 0;
    if(cols == 1) return data[0][0];
    if(cols == 2){
        return
        (data[0][0] * data[1][1]) -
        (data[0][1] * data[1][0]);
    }

    matrix_t* temp_matrix = initMatrix(rows, cols, data);
    if(!initMatrix) return 0;

    scalar_t out_det = det(temp_matrix);
    destroyMatrix(temp_matrix);
    return out_det;
}

int isSquareMatrix(matrix_t* matrix){
    return (matrix && matrix->cols == matrix->rows && matrix->rows > 0) ? 1 : 0;
}

int isIMatrix(matrix_t* matrix){
    if(!(matrix->rows == matrix->cols && matrix->cols > 0)) return 0;
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            if(
                (i == j && matrix->data[i][j] != 1) ||
                (i != j && matrix->data[i][j] != 0)
            ) return 0;
        }
    }
    return 1;
}

int isNullMatrix(matrix_t* matrix){
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            if(matrix->data[i][j] != 0) return 0;
        }
    }
    return 1;
}

matrix_t* matrixAddition(matrix_t* mat1, matrix_t* mat2){
    if(mat1->rows != mat2->rows || mat1->cols != mat2->cols) return NULL;

    matrix_t* out_matrix = initMatrix(mat1->rows, mat1->cols, NULL);
    if(!out_matrix) return NULL;
    
    for(size_t i = 0; i < mat1->rows; ++i){
        for(size_t j = 0; j < mat1->cols; ++j){
            out_matrix->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return out_matrix;
}

matrix_t* matrixSubtraction(matrix_t* mat1, matrix_t* mat2){
    if(mat1->rows != mat2->rows || mat1->cols != mat2->cols) return NULL;

    matrix_t* out_matrix = initMatrix(mat1->rows, mat1->cols, NULL);
    if(!out_matrix) return NULL;
    
    for(size_t i = 0; i < mat1->rows; ++i){
        for(size_t j = 0; j < mat1->cols; ++j){
            out_matrix->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
        }
    }
    return out_matrix;
}

matrix_t* matrixScalarMultiplication(matrix_t* matrix, scalar_t scalar){
    matrix_t* out_matrix = copyMatrix(matrix);
    if(!out_matrix) return NULL;
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            out_matrix->data[i][j] *= scalar;
        }
    }
    return out_matrix;
}

matrix_t* matrixMultiplication(matrix_t* mat1, matrix_t* mat2){
    if(mat1->rows != mat2->cols) return NULL;

    matrix_t* out_matrix = initMatrix(mat1->rows, mat2->cols, NULL);
    if(!out_matrix) return NULL;

    for(size_t i = 0; i < out_matrix->rows; ++i){
        for(size_t j = 0; j < out_matrix->cols; ++j){
            scalar_t sum = 0;
            for(size_t k = 0; k < mat1->cols; ++k){
                sum += (mat1->data[i][k] * mat2->data[k][j]);
            }
            out_matrix->data[i][j] = sum;
        }
    }
    return out_matrix;
}

matrix_t* matrixElementWiseProduct(matrix_t* mat1, matrix_t* mat2){
    if(mat1->cols != mat2->cols || mat1->rows != mat2->rows) return NULL;

    matrix_t* out_matrix = copyMatrix(mat1);
    if(!out_matrix) return NULL;

    for(size_t i = 0; i < mat1->rows; ++i){
        for(size_t j = 0; j < mat2->cols; ++j){
            out_matrix->data[i][j] *= mat2->data[i][j];
        }
    }

    return out_matrix;
}

void printMatrix(matrix_t* matrix){
    if(!matrix) return;    
    printf("\n");
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            printf("%.1f ", matrix->data[i][j]);
        }
    }
    printf("\n");
}

//TODO
void prettyPrintMatrix(matrix_t* matrix /* , const char* options */){
    if(!matrix) return;
    printf("\n");
    for(size_t i = 0; i < matrix->rows; ++i){
        for(size_t j = 0; j < matrix->cols; ++j){
            if(j == 0){
                printf("| ");
            }
            printf("%.1f ", matrix->data[i][j]);
            if(j == matrix->cols - 1){
                printf("|\n");
            }
        }
    }
}

//TODO
//matrix_t* ttom(tensor_t* tensor){
//    
//}
//
//vector_t* ttov(tensor_t* tensor){
//
//}
//
//scalar_t ttos(tensor_t* tensor){
//
//}

vector_t* mtov(matrix_t* matrix){
    if(matrix->cols == 1 && matrix->rows > 1){
        vector_t* out_vec = initVector(matrix->rows, NULL);
        if(!out_vec) return NULL;

        for(size_t i = 0; i < out_vec->size; ++i)
            out_vec->data[i] = matrix->data[i][0];
        return out_vec;
    }
    if(matrix->rows == 1 && matrix->cols > 1){
        vector_t* out_vec = initVector(matrix->cols, NULL);
        if(!out_vec) return NULL;

        for(size_t i = 0; i < out_vec->size; ++i)
            out_vec->data[i] = matrix->data[0][i];
        return out_vec;
    }else return NULL;
}

scalar_t mtos(matrix_t* matrix){
    return (matrix->rows == 1 && matrix->cols == 1) ? matrix->data[0][0] : 0;
}

scalar_t vtos(vector_t* vector){
    return (vector->size == 1) ? vector->data[0] : 0;
}
