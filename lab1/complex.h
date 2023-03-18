#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
    float x_point;
    float y_point;
}complex;

complex create_complex(float x_point, float y_point);

#endif