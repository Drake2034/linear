# changelog


# [0.1.0] - 2026-06-28

### added
    - new matrix initializer: `initMatrix(int rows, int cols, double data[rows][cols])`
    - new matrix printer: `printMatrix(matrix_t* matrix)`
    - new matrix pretty printer: `prettyPrintMatrix(matrix_t* matrix)`

# [0.1.1] - 2026-06-28

### changed
    - documentation within the header file (tensor struct)

# [0.2.0] - 2026-06-30

## [unreleased]
    - tensor implementation
    - tensor to matrix converter
    - tensor to vector converter
    - tensor to scalar converter

### added
    - vector implementation
    - new vector initializer `initVector(size_t size, const scalar_t data[size])`
    - new vector destroyer `destroyVector(vector_t* vector)`
    - new vector copier `copyVector(vector_t* src)`
    - new null vector initializer `nullVector(size_t size)`
    - new null vector checker `int isnull(vector_t* vector)`
    - new vector data getter `getVectorData(vector_t* vector)`
    - new vector data setter `setVectorData(vector_t* vector, scalar_t data[vector->size])`
    - new vector magnitude function `vectorMagnitude(vector_t* vector)`
    - new vector addition operator `vectorAddition(vector_t* vec1, vector_t* vec2)`
    - new vector subtraction operator `vectorSubtraction(vector_t* vec1, vector_t* vec2)`
    - new vector scalar multiplication operator `vectorScalarMultiplication(scalar_t scalar, vector_t* vector)`
    - new vector dot product operator `vectorDotProduct(vector_t* vec1, vector_t* vec2)`
    - new vector cross product operator `vectorCrossProduct(vector_t* vec1, vector_t* vec2)`
    - new vector printer `printVector(vector_t* vector)`
    - new vector pretty printer `prettyPrintVector(vector_t* vector)`
    - new matrix destroyer `destroyMatrix(matrix_t* matrix)`
    - new matrix copier `copyMatrix(matrix_t* src)`
    - new null matrix initializer `nullMatrix(size_t rows, size_t cols)`
    - new identity matrix initializer `iMatrix(size_t size)`
    - new diagonal matrix initializer `diagMatrix(size_t size, scalar_t data[size])`
    - new matrix data getter `getMatrixData(matrix_t* matrix)`
    - new matrix data setter `setMatrixData(matrix_t* matrix, scalat_t[matrix->rows][matrix->cols])`
    - new matrix data free function `freeData(scalar_t** data, size_t size)`
    - new matrix determinant function `det(matrix_t* matrix)`
    - new matrix determinant function without using the matrix type `detR(size_t rows, size_t cols, scalar_t data[rows][cols])`
    - new square matrix checker `isSquareMatrix(matrix_t* matrix)`
    - new identity matrix checker `isIMatrix(matrix_t* matrix)`
    - new null matrix checker `isNullMatrix(matrix_t* matrix)`
    - new matrix addition operator `matrixAddition(matrix_t* mat1, matrix_t* mat2)`
    - new matrix subtraction operator `matrixSubtraction(matrix_t* mat1, matrix_t* mat2)`
    - new matrix multiplication operator `matrixMultiplication(matrix_t* mat1, matrix_t* mat2)`
    - new matrix scalar multiplication operator `matrixScalarMultiplication(matrix_t* matrix, scalar_t scalar)`
    - new matrix element wise product operator `matrixElementWiseProduct(matrix_t* mat1, matrix_t* mat2)`
    - new matrix to vector converter `mtov(matrix_t* matrix)`
    - new matrix to scalar converter `mtos(matrix_t* matrix)`
    - new vector to scalar converter `vtos(vector_t* vector)`

### fixed
    - bug fixes