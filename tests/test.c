#include <stdio.h>
#include "linear/linear.h"

int main(){
    scalar_t scalar = 12.0f;
    printf("scalar: %f\n", scalar);

    double m_data[2][2] = {
        {3.0f, 4.0f},
        {2.0f, 1.0f}
    };

    matrix_t* matrix_1 = initMatrix(2, 2, m_data);


    matrix_t* matrix_2 = initMatrix(2, 2, 
        (double[2][2]){
            {3.0f, 4.0f},
            {2.0f, 5.0f}
        }
    );

    //matrix->setData(
    //    (double[2][2]){
    //    {2.0f, 1.0f},
    //    {3.0f, 0.0f}
    //});

    matrix_t* matrix_3 = initMatrix(4, 4,
        (double[4][4]){
            {0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0},
            {0.0, 0.0, 0.0, 0.0}
        }
    );
    prettyPrintMatrix(matrix_1);
    prettyPrintMatrix(matrix_2);
    prettyPrintMatrix(matrix_3);
    return 0;
}