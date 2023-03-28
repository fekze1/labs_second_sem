#include "source.h"
#include "array.h"
#include "complex.h"
#include <stdio.h>
#include <stdlib.h>

void print_array (node_array *array)
{
    if (!array->capacity) printf("EMPTY ARRAY\n");
    for (int i = 0; i < array->capacity; i++)
    {
        array->data[i]->node_info->print(array->data[i]);
    }
}

node_array *new_array()
{
    node **new_data = (node **)calloc(1, sizeof(node *));
    node_array *array = (node_array *)calloc(1, sizeof(node_array));

    array->data = new_data;

    array->array_info = &array_class;

    return array;
}

void delete_array (node_array *array)
{
    for (int i = 0; i < array->capacity; i++)
    {
        free(array->data[i]);
    }

    free(array->data);
    free(array);
}

void add_node(node_array *array, node *element)
{
    if (!array->element_size)
    {
        switch(element->node_info->size)
        {
            case (int)sizeof(complex):
                array->element_size = (int)sizeof(complex);
            break;
            case (int)sizeof(float):
                array->element_size = (int)sizeof(float);
            break;
        }
    }
    
    array->capacity++;
    array->count++;
    array->data = (node **)realloc(array->data, array->capacity * sizeof(node *));

    array->data[array->capacity - 1] = element;
}

void delete_node_by_id (node_array *array, int id)
{
    free(array->data[id]);
    for (int i = 0; i < array->capacity - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->capacity--;
    array->count--;
    array->data = (node **)realloc(array->data, array->capacity * sizeof(node *));
    if (!array->capacity) array->element_size = 0;
}

node_array_class array_class = 
{
    .print = &print_array,
    .new = &new_array,
    .delete = &delete_array,
    .add = &add_node,
    .delete_by_id = &delete_node_by_id
};