#ifndef SOURCE_H
#define SOURCE_H

#include "array.h"

typedef struct node node;

typedef struct
{
    void (*print)(void *value);
    struct node *(*new)(void *value);
}class;

extern class complex_class;

extern class float_class;

struct node
{
    class *node_info;
    void *data;
};

char *input_string();

#endif