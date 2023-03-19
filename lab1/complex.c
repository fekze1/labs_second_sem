#include "complex.h"
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