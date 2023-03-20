#ifndef SOURCE_H
#define SOURCE_H

#include "array.h"

typedef struct node_tmp node;

typedef struct
{
    void (*print)(void *value);
    struct node_tmp *(*new)(void *value);
}info;

extern info int_info;

extern info float_info;

struct node_tmp
{
    info *node_info;
    void *data;
};

#endif