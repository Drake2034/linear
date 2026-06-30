/**
 * @file linear.h
 * @author f
 * @brief a collection of basic linear algebra utility functions and structures
 * @version 0.1
 * @date __DATE__
 */

#ifndef LINEAR_H
    #define LINEAR_H
    
    #include <stdio.h>
    #include <stdlib.h>
    
    typedef double scalar_t; /** @note `scalar_t` and `double` are interchangeable */
    typedef struct vector vector_t; /** `scalar_t*` data, `size_t` size */
    typedef struct matrix matrix_t; /** `scalar_t**` data, `size_t` rows, `size_t` cols */
    typedef struct tensor tensor_t; /** `scalat_t*` data, `size_t` rank, `size_t*` shape, `size_t` stride */
    

    struct vector{
        scalar_t* data; /** elements of the vector */
        size_t size; /** number of elements in the vector*/
    };
    
    struct matrix{
        scalar_t** data; /** elements m(i, j) of the matrix*/
        size_t rows;  /** number of rows in the matrix*/
        size_t cols; /** number of columns in the matrix */
    };
    
    struct tensor{
        /** rank of tensor:
         * rank 0 -> scalar
         * rank 1 -> vector
         * rank 2 -> matrix
         * rank 3 ... n -> tensor
         * */
        size_t rank; 
        /** 
         * and the size of each dimension
        */
        int* shape; 
        /** 
         * the jump necessary to go from one element to the next one in the specified dimension
        */
        int* stride; 
        /** 
         * element t(i, j, ...) of the tensor
        */
        scalar_t* data; 
    };

    /**
     * @brief prints hi to stdout
     */
    void sayHi();

    /**
     * @brief initializes vector on the heap
     * 
     * @details
     * allocates memory for vector of size n and initializes it with provided data,
     * if data is NULL then the vector is filled with zeros
     * 
     * @note setting `data` to NULL returns a null vector
     * 
     * @return pointer to vector `vector_t*` or NULL on failure
     * 
     * @warning don't forget to free using `destroyVector(vector_t* vector)`
     * 
     * usage example:
     * 
     * @code{.c}
    ` 
    vector_t* v = initVector(2, (scalar_t[2]){0.0f, 1.0f});

    OR

    scalar_t[2] v_data = {0.0f, 1.0f};
    vector_t* v = initVector(2, v_data);
    ` @endcode
     *
     * @param size number of components
     * @param data array of scalars (setting to null initializes a null vector)
     */
    vector_t* initVector(size_t size, const scalar_t data[size]);

    /**
     * @brief frees the data of the vector as well as the vector pointer itself
     */
    void destroyVector(vector_t* vector);

    /**
     * @brief initializes a new vector and copies the data
     * 
     * @details
     * allocates memory the same size as the source vector and copies the data
     * which is put in the destination vector
     * 
     * @return pointer to copy vector `vector_t*` or NULL on failure
     * 
     * usage example:
     * 
     * @code{.c}
    `
    vector_t* v_src = initVector(2, (scalar_t[2]){0.0f, 1.0f});
    vector_t* v_copy = copyVector(v_src);
    ` @endcode
     *
     * @param src source vector
     */
    vector_t* copyVector(vector_t* src);

    /**
     * @brief initializes a null vector
     * 
     * @return pointer to null vector `vector_t*` or NULL on failure
     * 
     * @param size number of components
     */
    vector_t* nullVector(size_t size);

    /**
     * @brief checks if vector is null
     * 
     * @return 1 on true, 0 on false
     * 
     * @param vector pointer to vector
     */
    int isnull(vector_t* vector);

    /**
     * @brief set the data of a vector
     * 
     * @return void
     * 
     * usage example:
     * 
     * @code{.c}
    `
    vector_t* null_v = nullVector(3);

    setVectorData(null_v, (scalar_t[3]){0.0f, 0.0f, 1.0f});
    ` @endcode
     * 
     * @param vector pointer to vector
     * @param data array of scalars
     */
    void setVectorData(vector_t* vector, scalar_t data[vector->size]);

    /**
     * @brief gets the data of a vector
     * 
     * @return array of scalars initialized on the heap `scalar_t**` or NULL on failure
     * 
     * @warning don't forget to free after usage 
     * 
     * @code{.c}
    `
    vector_t* v = initVector(2, (scalar_t[2]){1.0f, 0.0f});
    
    scalar_t* vector_data = getVectorData(v);

    // !!!
    free(vector_data);
    ` @endcode
     * 
     * @param vector pointer to vector
     */
    scalar_t* getVectorData(vector_t* vector);

    /**
     * @brief evaluates magnitude of a vector
     * 
     * @return scalar `scalar_t` or 0 on failure
     * 
     * @param vector pointer to vector
     */
    scalar_t vectorMagnitude(vector_t* vector);

    /**
     * @brief add two vectors
     * 
     * @return pointer to returned vector `vector_t*` or NULL on failure
     * 
     * @note vectors must be of same size
     * 
     * @param vec1 pointer to first vector
     * @param vec2 pointer to second vector
     */
    vector_t* vectorAddition(vector_t* vec1, vector_t* vec2);

    /**
     * @brief substract the second vector from the first vector
     * 
     * @return pointer to returned vector `vector_t*` or NULL on failure
     * 
     * @note vectors must be of same size
     * 
     * @param vec1 pointer to first vector
     * @param vec2 pointer to second vector
     */
    vector_t* vectorSubtraction(vector_t* vec1, vector_t* vec2);

    /**
     * @brief multiply a vector by a scalar
     * 
     * @return pointer to returned vector `vector_t*` or NULL on failure
     * 
     * @param scalar scalar (real number)
     * @param vector pointer to vector
     */
    vector_t* vectorScalarMultiplication(scalar_t scalar, vector_t* vector);

    /**
     * @brief dot product of two vectors
     * 
     * @return scalar `scalar_t` or 0 on failure
     * 
     * @note vectors must be of same size
     * 
     * @param vec1 pointer to first vector
     * @param vec2 pointer to second vector
     */
    scalar_t vectorDotProduct(vector_t* vec1, vector_t* vec2);

    /**
     * @brief cross product of two vectors
     * 
     * @return pointer to the returned vector `vector_t*` or NULL on failure
     * 
     * @note vectors must be of same size
     * 
     * @param vec1 pointer to first vector
     * @param vec2 pointer to second vector
     */
    vector_t* vectorCrossProduct(vector_t* vec1, vector_t* vec2);

    /**
     * @brief prints vector to stdout
     * 
     * @param vector pointer to vector
     */
    void printVector(vector_t* vector);

    /**
     * @brief prints vector to stdout in a more human readable format
     * 
     * @param matrix pointer to vector
     * @param options specifiers to extract better readable text
     */
    void prettyPrintVector(vector_t* vector);

    /**
     * @brief initializes matrix on the heap
     * 
     * @details
     * allocates memory for n x m matrix and initializes it with provided data,
     * if data is NULL then the matrix is filled with zeros
     * 
     * @return pointer to matrix `matrix_t*` or NULL on failure
     * 
     * @warning don't forget to free with `destroyMatrix(matrix_t* matrix)`
     * 
     * @note setting `data` to NULL returns a null matrix
     * 
     * usage example:
     * 
     * @code{.c}
    `
    matrix_t* m = initMatrix(3, 3 
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    OR

    scalar_t matrix_data[3][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
     };
     
    matrix_t* m = initMatrix(3, 3, matrix_data);
    `
    @endcode
     *
     * @param rows number of rows
     * @param cols number of columns
     * @param data matrix of scalars
     * 
     */
    matrix_t* initMatrix(size_t rows, size_t cols, const scalar_t data[rows][cols]);

    /**
     * @brief frees the data of the matrix as well as the matrix pointer itself
     * 
     * @param matrix pointer to initialized matrix
     */
    void destroyMatrix(matrix_t* matrix);

    /**
     * @brief initializes a new matrix and copies the data
     * 
     * @details
     * allocates memory the same size as the source matrix and copies the data
     * which is put in the destination matrix
     * 
     * @return pointer to copy matrix `matrix_t*` or NULL on failure
     * 
     * usage example:
     * 
     * @code{.c}
    `
    matrix_t* m = initMatrix(3, 3,
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );
    matrix_t* m_copy = copyMatrix(m);
    ` @endcode
     *
     * @param src pointer to source matrix
     */
    matrix_t* copyMatrix(matrix_t* src);

    /**
     * @brief explicitely initialize a zero matrix
     * 
     * @return pointer to zero matrix `matrix_t*` or NULL on failure
     * 
     * @param rows number of rows
     * @param cols number of columns
     */
    matrix_t* nullMatrix(size_t rows, size_t cols);

    /**
     * @brief initializes identity matrix
     * 
     * @details
     * allocates memory for a square matrix and fills the main diagonal with one's
     * 
     * @return pointer to identity matrix `matrix_t*` or NULL on failure
     * 
     * @param size the size of the square
     */
    matrix_t* iMatrix(size_t size);
    
    /**
     * @brief initializes a diagonal matrix
     * 
     * @details
     * allocates memory for a square matrix and fills the main diagonal with
     * provided data
     * 
     * @return pointer to diagonal matrix `matrix_t*` or NULL on failure
     * 
     * @param size the size of the square
     * @param data array of scalars
     */
    matrix_t* diagMatrix(size_t size, scalar_t data[size]);

    /**
     * @brief set the data of a matrix
     * 
     * @return void
     * 
     * usage example:
     * 
     * @code{.c}
    `
    matrix_t* zero_m = zeroMatrix(3, 3);

    setMatrixData(zero_m,
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f}.
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    OR

    scalar_t new_data[3][3] = {
        {1.0f, 0.0f, 0.0f}.
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    setMatrixData(zero_m, new_data);
    ` @endcode
     * 
     * @param matrix pointer to the matrix
     * @param data matrix of scalars (setting to null initializes a null matrix)
     */
    void setMatrixData(matrix_t* matrix, scalar_t data[matrix->rows][matrix->cols]);

    /**
     * @brief gets data of the matrix
     * 
     * @returns matrix of scalars initialized on the heap `scalar_t**` or NULL on failure
     * 
     * @warning don't forget to free with `freeData(scalar_t** data, size_t size)`
     * 
     * usage example: 
     * 
     * @code{.c}
    `
    matrix_t* m = initMatrix(3, 3,
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    scalar_t** m_data = getMatrixData(m);

    // !!!
    freeData(m_data, m->rows);
    `  @endcode
     * 
     * @param matrix pointer to matrix
     */
    scalar_t** getMatrixData(matrix_t* matrix);

    /**
     * @brief special function to call after `getMatrixData`
     */
    void freeData(scalar_t** data, size_t size);

    /**
     * @brief evaluates the determinant of a matrix
     * 
     * @return the determinant as `scalar_t`
     * 
     * usage example:
     * 
     * @code{.c}
    `
    matrix_t* m = initMatrix(3, 3,
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    scalar_t determinant_m = det(m);
    ` @endcode
     * 
     * @param matrix pointer to matrix
     */
    scalar_t det(matrix_t* matrix);

    /**
     * @brief evaluates the determinant of a matrix initialized on the stack
     * 
     * @returns the determinant as `scalar_t`
     * 
     * usage example:
     * 
     * @code{.c}
    `
    scalar_t det = detR(3, 3,
        (scalar_t[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    OR

    scalar_t m_stack[3][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
    };

    scalar_t det = detR(3, 3, m_stack);
    `  @endcode
     *
     * @param rows number of rows
     * @param cols number of columns
     * @param data matrix of scalars
     */
    scalar_t detR(size_t rows, size_t cols, scalar_t data[rows][cols]);

    /**
     * @brief checks if matrix is square
     * 
     * @returns 1 on true, 0 on false
     * 
     * @param matrix pointer to matrix
     */
    int isSquareMatrix(matrix_t* matrix);

    /**
     * @brief checks if matrix is an identity matrix
     * 
     * @returns 1 on true, 0 on false
     * 
     * @param matrix pointer to matrix
     */
    int isIMatrix(matrix_t* matrix);

    /**
     * @brief checks if matrix is a null matrix
     * 
     * @returns 1 on true, 0 on false
     * 
     * @param matrix pointer to matrix
     */
    int isNullMatrix(matrix_t* matrix);

    /**
     * @brief add two matrices
     * 
     * @return pointer to returned matrix `matrix_t*` or NULL on failure
     * 
     * @note matrices must be of same size
     * 
     * @param mat1 pointer to first matrix
     * @param mat2 pointer to second matrix
     */
    matrix_t* matrixAddition(matrix_t* mat1, matrix_t* mat2);

    /**
     * @brief substract the second matrix from the first matrix
     * 
     * @return pointer to returned matrix `matrix_t*` or NULL on failure
     * 
     * @note matrices must be of same size
     * 
     * @param mat1 pointer to first matrix
     * @param mat2 pointer to second matrix
     */
    matrix_t* matrixSubtraction(matrix_t* mat1, matrix_t* mat2);

    /**
     * @brief multiply matrix by a scalar
     * 
     * @return pointer to returned matrix `matrix_t*` or NULL on failure
     * 
     * @param scalar scalar (real number)
     * @param matrix pointer to matrix
     */
    matrix_t* matrixScalarMultiplication(matrix_t* matrix, scalar_t scalar);

    /**
     * @brief multiply matrix by another matrix
     * 
     * @return pointer to the returned matrix `matrix_t*` or NULL on failure
     * 
     * @note number of rows of the first matrix must be the same as the number of columns of the second matrix
     */
    matrix_t* matrixMultiplication(matrix_t* mat1, matrix_t* mat2);

    /**
     * @brief Hadamard product of two matrices
     * 
     * @return pointer to the returned matrix `matrix_t*` or NULL on failure
     * 
     * @note matrices must be of same size
     */
    matrix_t* matrixElementWiseProduct(matrix_t* mat1, matrix_t* mat2);

    /**
     * @brief print the cells of matrix to stdout
     * 
     * @param matrix pointer to matrix
     */
    void printMatrix(matrix_t* matrix);

    /**
     * @brief prints matrix to stdout in a more human readable format
     * 
     * @param matrix pointer to matrix
     * @param options specifiers to beautify
     */
    void prettyPrintMatrix(matrix_t* matrix /* , const char* options */);

    /**
     * @brief turns a 1 x m or n x 1 matrix to a vector type
     * 
     * @returns pointer to returned vector `vector_t*` or NULL on failure
     * 
     * @param matrix pointer to matrix
     */
    vector_t* mtov(matrix_t* matrix);

    /**
     * @brief turns a 1 x 1 matrix to a scalar type
     * 
     * @returns scalar (real number)
     * 
     * @param matrix pointer to matrix
     */
    scalar_t mtos(matrix_t* matrix);

    /**
     * @brief turns a vector with a single component to a scalar type
     * 
     * @returns scalar (real number)
     * 
     * @param vector pointer to vector
     */
    scalar_t vtos(vector_t* vector);

#endif