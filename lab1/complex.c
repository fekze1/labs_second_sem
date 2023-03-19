#include "complex.h"
#include <stdio.h>
#include <math.h>

complex create_complex(float x_point, float y_point)
{
    return (complex)
    {
        .x_point = x_point, 
        .y_point = y_point
    };
}

float find_abs(complex number)
{
    return sqrt(pow(number.x_point, 2) + pow(number.y_point, 2));
}

complex find_add_cmplx(complex number1, complex number2)
{
    return (complex)
    {
        .x_point = number1.x_point + number2.x_point,
        .y_point = number1.y_point + number2.y_point
    };
}

complex find_sub_cmplx(complex number1, complex number2)
{
    return (complex)
    {
        .x_point = number1.x_point - number2.x_point,
        .y_point = number1.y_point - number2.y_point
    };
}

complex find_mul_cmplx(complex number1, complex number2)
{
    return (complex)
    {
        .x_point = (number1.x_point * number2.x_point) - (number1.y_point * number2.y_point),
        .y_point = (number1.x_point * number2.y_point) + (number1.y_point * number2.x_point)
    };
}

complex find_div_cmplx(complex number1, complex number2)
{
    return (complex)
    {
        .x_point = ((number1.x_point * number2.x_point) + (number1.y_point * number2.y_point)) / (pow(number2.x_point, 2) + pow(number2.y_point, 2)),
        .y_point = ((number1.y_point * number2.y_point) - (number1.x_point * number2.y_point)) / (pow(number2.x_point, 2) + pow(number2.y_point, 2)),
    };
}

int cmp_complex(complex *number1, complex *number2)
{
    float diff = find_abs(*number1) - find_abs(*number2);
    
    if (diff > 0.) return 1;
    else if (diff == 0.) return 0;
    
    return -1;
}

int cmpr_complex(complex *number1, complex *number2)
{
    float diff = find_abs(*number1) - find_abs(*number2);
    
    if (diff > 0.) return -1;
    else if (diff == 0.) return 0;
    
    return 1;
}