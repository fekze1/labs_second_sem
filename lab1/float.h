#ifndef FLOAT_H
#define FLOAT_H

#include "array.h"

extern value_class float_class;

float *create_float(float value);

void print_float_node(node *value);

node *new_float_node(void *value);

#endif
