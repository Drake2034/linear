#include <stdlib.h>
#include <stdio.h>
#include "linear/linear.h"

void sayHi(){ printf("linear: HI\n"); }

struct tensor{
    unsigned int rank;
    int* shape;
    int* stride;
    double* data;
};

