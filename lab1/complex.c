#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

complex create_complex(float x_point, float y_point)
{
    return (complex )
    {
        .x_point = x_point,
        .y_point = y_point
    };
}

void print_complex(complex number)
{
    if (number.x_point == 0 && number.y_point == 0) printf("z = 0\n");
    else if (number.x_point == 0 && number.y_point != 0) printf("z = %fi\n", number.y_point);
    else if (number.x_point != 0 && number.y_point == 0) printf("z = %f\n", number.x_point);
    else printf("z = %f + (%f)i\n", number.x_point, number.y_point);
}

void print_complex_node(node *value)
{
    complex value_cmplx = *(complex *)value->data;
    print_complex(value_cmplx);
}

node *new_complex_node(void *value)
{
    complex *value_cmplx_ptr = (complex *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &complex_class;
    new_node->data = (void *)value_cmplx_ptr;

    return new_node;
}

value_class complex_class = 
{
    .size = (int)sizeof(complex),
    .print = &print_complex_node,
    .new = &new_complex_node
};