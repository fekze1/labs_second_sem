#include "source.h"
#include "float.h"
#include "complex.h"
#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

void print_float_node(node *value)
{
    printf("%f\n", *(float *)value->data);
}

node *new_float_node(void *value)
{
    float *value_float_ptr = (float *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &float_class;
    new_node->data = (void *)value_float_ptr;

    return new_node;
}

value_class float_class = 
{
    .size = (int)sizeof(float),
    .print = &print_float_node,
    .new = &new_float_node
};