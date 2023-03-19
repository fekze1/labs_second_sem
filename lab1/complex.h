#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct
{
    float x_point;
    float y_point;
}complex;

complex create_complex(float x_point, float y_point);

float find_abs(complex number);

complex find_add_cmplx(complex number1, complex number2);

complex find_sub_cmplx(complex number1, complex number2);

complex find_mul_cmplx(complex number1, complex number2);

complex find_div_cmplx(complex number1, complex number2);

int cmp_complex(complex *number1, complex *number2);

int cmpr_complex(complex *number1, complex *number2);

#endif