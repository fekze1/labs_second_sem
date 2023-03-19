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

void add_complex(complex_array *array, complex element)
{
    array->capacity++;
    array->count++;
    array->data = (complex *)realloc(array->data, array->capacity * sizeof(complex));

    array->data[array->capacity - 1] = element;
}

void add_float(float_array *array, float element)
{
    array->capacity++;
    array->count++;
    array->data = (float *)realloc(array->data, array->capacity * sizeof(float));

    array->data[array->capacity - 1] = element;
}

void del_complex(complex_array *array, int id)
{
    for (int i = id; i < array->capacity - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->capacity--;
    array->count--;
}

void del_float(float_array *array, int id)
{
    for (int i = id; i < array->capacity - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->capacity--;
    array->count--;
}

complex_array cancat_cmplx(complex_array array1, complex_array array2)
{
    complex_array array_cat = create_cmplx_arr(array1.capacity + array2.capacity);

    for (int i = 0; i < array1.capacity; i++) array_cat.data[i] = array1.data[i];
    for (int i = 0, j = array1.capacity; i < array2.capacity; i++, j++) array_cat.data[j] = array2.data[i];

    return array_cat;
}

complex_array cancat_and_del_cmplx(complex_array array1, complex_array *array2)
{
    complex_array array_cat = create_cmplx_arr(array1.capacity + array2->capacity);

    for (int i = 0; i < array1.capacity; i++) array_cat.data[i] = array1.data[i];
    for (int i = 0, j = array1.capacity; i < array2->capacity; i++, j++) array_cat.data[j] = array2->data[i];

    delete_data(array2->data);
    return array_cat;
}

float_array cancat_flt(float_array array1, float_array array2)
{
    float_array array_cat = create_flt_arr(array1.capacity + array2.capacity);

    for (int i = 0; i < array1.capacity; i++) array_cat.data[i] = array1.data[i];
    for (int i = 0, j = array1.capacity; i < array2.capacity; i++, j++) array_cat.data[j] = array2.data[i];

    return array_cat;
}

float_array cancat_and_del_flt(float_array array1, float_array *array2)
{
    float_array array_cat = create_flt_arr(array1.capacity + array2->capacity);

    for (int i = 0; i < array1.capacity; i++) array_cat.data[i] = array1.data[i];
    for (int i = 0, j = array1.capacity; i < array2->capacity; i++, j++) array_cat.data[j] = array2->data[i];

    delete_data(array2->data);
    return array_cat;
}

complex_array map_cmplx(complex (*func)(complex element), complex_array array)
{
    complex_array new_array = create_cmplx_arr(array.capacity);

    for (int i = 0; i < array.capacity; i++)
    {
        new_array.data[i] = func(array.data[i]);
    }

    return new_array;
}

complex_array map_and_del_cmplx(complex (*func)(complex element), complex_array *array)
{
    complex_array new_array = create_cmplx_arr(array->capacity);

    for (int i = 0; i < array->capacity; i++)
    {
        new_array.data[i] = func(array->data[i]);
    }

    delete_data(array->data);
    return new_array;
}

float_array map_flt(float (*func)(float element), float_array array)
{
    float_array new_array = create_flt_arr(array.capacity);

    for (int i = 0; i < array.capacity; i++)
    {
        new_array.data[i] = func(array.data[i]);
    }

    return new_array;
}

float_array map_and_del_flt(float (*func)(float element), float_array *array)
{
    float_array new_array = create_flt_arr(array->capacity);

    for (int i = 0; i < array->capacity; i++)
    {
        new_array.data[i] = func(array->data[i]);
    }

    delete_data(array->data);
    return new_array;
}

complex_array where_cmplx_arr(bool (*func)(complex element), complex_array array)
{
    complex_array new_array = create_cmplx_arr(0);
    for (int i = 0; i < array.capacity; i++)
    {
        if (func(array.data[i])) add_complex(&new_array, array.data[i]);
    }

    return new_array;
}

int where_cmplx_count(bool (*func)(complex element), complex_array array)
{
    int count = 0;
    for (int i = 0; i < array.capacity; i++)
    {
        if (func(array.data[i])) count++;
    }

    return count;
}

float_array where_flt_arr(bool (*func)(float element), float_array array)
{
    float_array new_array = create_flt_arr(0);
    for (int i = 0; i < array.capacity; i++)
    {
        if (func(array.data[i])) add_float(&new_array, array.data[i]);
    }

    return new_array;
}

int where_flt_count(bool (*func)(float element), float_array array)
{
    int count = 0;
    for (int i = 0; i < array.capacity; i++)
    {
        if (func(array.data[i])) count++;
    }

    return count;
}