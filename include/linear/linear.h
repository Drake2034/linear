/**
 * @file linear.h
 * @author f
 * @brief a collection of basic linear algebra utility functions and structures
 * @version 0.1
 * @date __DATE__
 */

#ifndef LINEAR_H
    #define LINEAR_H

    struct vector{
        double* data; /** elements of the vector */
        size_t size; /** number of elements in the vector*/
    };
    
    struct matrix{
        double** data; /** elements m(i, j) of the matrix*/
        int rows;  /** number of rows in the matrix*/
        int cols; /** number of columns in the matrix */
    };
    
    struct tensor{
        /** rank of tensor:
         * rank 0 -> scalar
         * rank 1 -> vector
         * rank 2 -> matrix
         * rank 3 ... n -> tensor
         * */
        unsigned int rank; 
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
        double* data; 
    };
    
    typedef double scalar_t;
    typedef struct vector vector_t;
    typedef struct matrix matrix_t;
    typedef struct tensor tensor_t;

    /**
     * @brief prints hi to stdout
     */
    void sayHi();

    /**
     * @brief initializes matrix on the heap
     * 
     * @details
     * allocates memory for n x m matrix an initializes it with provided data,
     * if data is NULL then the matrix is filled with zeros
     * 
     * @return pointer to matrix or NULL on failure
     *  
     * usage example:
     * 
     * @code{.c}
    `
    matrix_t* m = initMatrix(3, 3 
        (double[3][3]){
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            {0.0f, 0.0f, 1.0f}
        }
    );

    double matrix_data[3][3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f}
     };
     
    matrix_t* m = initMatrix(3, 3, (double**)matrix_data);
    `
    @endcode
     */
    matrix_t* initMatrix(int rows, int cols, double data[rows][cols]);

    /**
     * @brief print the cells of matrix to stdout
     */
    void printMatrix(matrix_t* matrix);

    /**
     * @brief prints matrix to stdout in a more human readable format
     */
    void prettyPrintMatrix(matrix_t* matrix /* , const char* options */);


#endif