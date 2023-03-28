#ifndef COMPLEX_H
#define COMPLEX_H

#include "source.h"
#include "array.h"

extern value_class complex_class;

typedef struct
{
    float x_point;
    float y_point;
}complex;

complex create_complex(float x_point, float y_point);

void print_complex(complex number);

void print_complex_node(node *value);

node *new_complex_node(void *value);

#endif