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

void add_complex(complex_array *array, complex element);

void add_float(float_array *array, float element);

void del_complex(complex_array *array, int id);

void del_float(float_array *array, int id);

complex_array cancat_cmplx(complex_array array1, complex_array array2);

complex_array cancat_and_del_cmplx(complex_array array1, complex_array *array2);

float_array cancat_flt(float_array array1, float_array array2);

float_array cancat_and_del_flt(float_array array1, float_array *array2);

complex_array map_cmplx(complex (*func)(complex element), complex_array array);

complex_array map_and_del_cmplx(complex (*func)(complex element), complex_array *array);

float_array map_flt(float (*func)(float element), float_array array);

float_array map_and_del_flt(float (*func)(float element), float_array *array);

#endif