#ifndef ARRAY_H
#define ARRAY_H

#include "source.h"
#include <stdbool.h>

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
    int element_size;
    int count;
    int capacity;

    void (*print)(struct node_array *array);
    void (*delete)(struct node_array *array);
    void (*add)(struct node_array *array, node *element);
    void (*delete_by_id)(struct node_array *array, int id);
    struct node_array *(*map)(struct node_array *array, node *(*func)(node *element));
    struct node_array *(*where)(struct node_array *array, bool (*func)(node *element));
}node_array_class;

struct node
{
    value_class *node_info;
    void *data;
};

struct node_array
{
    node_array_class *array_info;
    node **data;
};

node_array *create_array();

bool test_func(node *element);

node *test_map(node *element);

#endif