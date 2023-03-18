#ifndef DYNARR_H
#define DYNARR_H

#include <stdbool.h>
#include "complex.h"

typedef struct
{
    int count;
    int capacity;
    int element_size;
    complex *data;
}complex_array;

typedef struct
{
    int count;
    int capacity;
    int element_size;
    float *data;
}float_array;

complex_array create_cmplx_arr(int count);

float_array create_flt_arr(int count);

void delete_data(void *data);

bool is_defined(void *number);

void add_complex(complex_array *array, complex element);

void add_float(float_array *array, float element);

#endif