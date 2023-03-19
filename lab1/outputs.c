#include "outputs.h"
#include "complex.h"
#include "dynarr.h"
#include <stdio.h>
#include <stdbool.h>

void print_complex(complex number)
{
    if (number.x_point == 0 && number.y_point == 0) printf("z = 0\n");
    else if (number.x_point == 0 && number.y_point != 0) printf("z = %fi\n", number.y_point);
    else if (number.x_point != 0 && number.y_point == 0) printf("z = %f\n", number.x_point);
    else printf("z = %f + (%f)i\n", number.x_point, number.y_point);
}

void print_cmplx_arr(complex_array array)
{
    for (int i = 0; i < array.capacity; i++)
    {
        printf("[%d]: ", i + 1);  
        print_complex(array.data[i]);
    } 
}

void print_flt_arr(float_array array)
{
    for (int i = 0; i < array.capacity; i++) printf("[%d]: %f\n", i + 1, array.data[i]);
}
