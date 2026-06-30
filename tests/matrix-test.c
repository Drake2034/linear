#include "linear/linear.h"

int main(){
    sayHi();

    matrix_t* m_1 = initMatrix(3, 3,
        (scalar_t[3][3]){
            {1, 1, 1},
            {2, 2, 2},
            {2, 3, 4}
        }
    );
    if(!m_1) return 1;

    matrix_t* m_2 = iMatrix(3);
    if(!m_2){
        destroyMatrix(m_1);
        return 1;
    }

    matrix_t* result = matrixMultiplication(m_1, m_2);
    if(!result){
        destroyMatrix(m_1); destroyMatrix(m_2);
        return 1;
    }

    printf("\nm_1:");
    prettyPrintMatrix(m_1);
    printf("\n");
    printf("m_2:");
    prettyPrintMatrix(m_2);
    printf("\n");

    printf("m_1 x m_2 = ");
    prettyPrintMatrix(result);
    printf("\n");

    setMatrixData(m_1,
        (scalar_t[3][3]){
            {1, 1, 1},
            {2, 2, 2},
            {3, 3, 3}
        }
    );

    printf("m_1 fixed:");
    prettyPrintMatrix(m_1);
    printf("\n");

    matrix_t* m_3 = initMatrix(3, 3, 
        (scalar_t[3][3]){
            {1, 2, 3},
            {3, 4, 4},
            {1, 3, 4}
        }
    );

    printf("m_3:");
    prettyPrintMatrix(m_3);
    printf("\n");

    destroyMatrix(result);
    result = matrixAddition(m_1, m_3);

    prettyPrintMatrix(result);

    printf("m_1 data:");
    scalar_t** m_1_data = getMatrixData(m_1);

    printf("\n");
    for(size_t i = 0; i < 3; ++i){
        for(size_t j = 0; j < 3; ++j){
            printf("%.1f ", m_1_data[i][j]);
        }
        printf("\n");
    }

    destroyMatrix(m_1);
    destroyMatrix(m_2);
    return 0;
}   