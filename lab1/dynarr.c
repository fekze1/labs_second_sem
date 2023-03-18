#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dynarr.h"
#include "complex.h"
#include "outputs.h"

complex_array create_cmplx_arr(int count)
{
    complex *array = (complex *)calloc(count, sizeof(complex));
    return (complex_array)
    {
        .count = count,
        .capacity = count,
        .element_size = (int)sizeof(complex),
        .data = array
    };
}

float_array create_flt_arr(int count)
{
    float *array = (float *)calloc(count, sizeof(float));
    return (float_array)
    {
        .count = count,
        .capacity = count,
        .element_size = (int)sizeof(float),
        .data = array
    };
}

void delete_data(void *data)
{
    free(data);
}

bool is_defined(void *number)
{
    if (*(char *)(number) == '\0') return false;
    return true;
}

void add_complex(complex_array *array, complex element)
{
    array->capacity++;
    array->data = (complex *)realloc(array->data, array->capacity * sizeof(complex));

    array->data[array->capacity - 1] = element;
}

void add_float(float_array *array, float element)
{
    array->capacity++;
    array->data = (float *)realloc(array->data, array->capacity * sizeof(float));

    array->data[array->capacity - 1] = element;
}