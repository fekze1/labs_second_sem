#include "source.h"
#include "array.h"
#include "complex.h"
#include <stdio.h>
#include <stdlib.h>

void set_array_class(node_array_class **class);

node_array *new_array()
{
    node **new_data = (node **)calloc(1, sizeof(node *));
    node_array *array = (node_array *)calloc(1, sizeof(node_array));

    node_array_class *new_class = (node_array_class *)calloc(1, sizeof(node_array_class));
    set_array_class(&new_class);
    
    array->data = new_data;

    array->array_info = new_class;

    return array;
}

void print_array (node_array *array)
{
    if (!array->array_info->capacity) printf("EMPTY ARRAY\n");
    for (int i = 0; i < array->array_info->capacity; i++)
    {
        array->data[i]->node_info->print(array->data[i]);
    }
}

void delete_array (node_array *array)
{
    for (int i = 0; i < array->array_info->capacity; i++)
    {
        free(array->data[i]);
    }

    free(array->array_info);
    free(array->data);
    free(array);
}

void add_node(node_array *array, node *element)
{
    if (!array->array_info->element_size)
    {
        array->array_info->element_size = element->node_info->size;
    }
    
    array->array_info->capacity++;
    array->array_info->count++;
    array->data = (node **)realloc(array->data, array->array_info->capacity * sizeof(node *));

    array->data[array->array_info->capacity - 1] = element;
}

void delete_node_by_id (node_array *array, int id)
{
    free(array->data[id]);
    for (int i = 0; i < array->array_info->capacity - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->array_info->capacity--;
    array->array_info->count--;
    array->data = (node **)realloc(array->data, array->array_info->capacity * sizeof(node *));
    if (!array->array_info->capacity) array->array_info->element_size = 0;
}

void set_array_class(node_array_class **class)
{
    (*class)->count = 0;
    (*class)->capacity = 0;
    (*class)->element_size = 0;
    (*class)->add = &add_node;
    (*class)->delete = &delete_array;
    (*class)->delete_by_id = &delete_node_by_id;
    (*class)->print = &print_array;
}
// node_array_class array_class = 
// {
//     .print = &print_array,
//     .delete = &delete_array,
//     .add = &add_node,
//     .delete_by_id = &delete_node_by_id
// };