#include "linear/linear.h"

int main(){
    sayHi();

    scalar_t number = 1 + 1;
    printf("%.1f\n", number);

    vector_t* vector = initVector(400, (scalar_t[10]){number, number});
    printVector(vector);
    return 0;
}