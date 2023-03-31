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
    struct node_array *(*cancat)(struct node_array *array1, struct node_array *array2);
    void (*sort)(struct node_array *array, int (*comparator)(node *element1, node *element2));
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

int float_cmp(node *element1, node *element2);

int float_cmpr(node *element1, node *element2);

#endif