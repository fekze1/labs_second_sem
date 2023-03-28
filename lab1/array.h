#ifndef ARRAY_H
#define ARRAY_H

#include "source.h"

typedef struct node node;
typedef struct node_array node_array;

typedef struct
{
    const int size;
    void (*print)(struct node *value);
    struct node *(*new)(void *value);
}value_class;

typedef struct
{   
    void (*print)(struct node_array *array);
    struct node_array *(*new)();
    void (*delete)(struct node_array *array);
    void (*add)(struct node_array *array, node *element);
    void (*delete_by_id)(struct node_array *array, int id);
}node_array_class;

struct node
{
    value_class *node_info;
    void *data;
};

struct node_array
{
    int element_size;
    int count;
    int capacity;

    node_array_class *array_info;
    node **data;
};

extern node_array_class array_class;

#endif