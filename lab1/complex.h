#ifndef COMPLEX_H
#define COMPLEX_H

#include "source.h"
#include "array.h"

typedef struct
{
    float x_point;
    float y_point;
}complex;

void print_complex(complex number);

char *flt_to_str(float number);

#endif