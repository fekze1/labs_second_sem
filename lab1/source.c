#include "source.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_int(void *value)
{
    node *node_val = (node *)value;
    printf("%d\n", *(int *)node_val->data);
}

node *new_int(void *value)
{
    int *value_int_ptr = (int *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &int_info;
    new_node->data = (void *)value_int_ptr;

    return new_node;
}

void print_float(void *value)
{
    node *node_val = (node *)value;
    printf("%f\n", *(float *)node_val->data);
}

node *new_float(void *value)
{
    float *value_float_ptr = (float *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &float_info;
    new_node->data = (void *)value_float_ptr;

    return new_node;
}

info int_info = 
{
    .print = &print_int,
    .new = &new_int
};

info float_info = 
{
    .print = &print_float,
    .new = &new_float
};