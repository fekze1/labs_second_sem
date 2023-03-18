#include "complex.h"

complex create_complex(float x_point, float y_point)
{
    return (complex)
    {
        .x_point = x_point, 
        .y_point = y_point
    };
}