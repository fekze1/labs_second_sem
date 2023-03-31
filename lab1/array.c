#include "source.h"
#include "array.h"
#include "complex.h"
#include "float.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void set_array_class(node_array_class **class);

node_array *create_array()
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
    if (!array->array_info->capacity) printf("\tEMPTY ARRAY\n");
    for (int i = 0; i < array->array_info->capacity; i++)
    {   
        printf("\t[%d]: ", i + 1);
        array->data[i]->node_info->print(array->data[i]);
    }
}

void delete_array (node_array *array)
{
    for (int i = 0; i < array->array_info->capacity; i++)
    {
        free(array->data[i]->data);
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
    free(array->data[id]->data);
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

node *create_copy(node *element)
{
    node *copy;

    switch (element->node_info->size)
    {
    case sizeof(complex):
        complex *new_cmplx = create_complex((*(complex *)element->data).x_point, (*(complex *)element->data).y_point);

        copy = complex_class.new((void *)new_cmplx);
    break;
    
    case sizeof(float):
        float *new_flt = create_float((*(float *)element->data));

        copy = float_class.new((void *)new_flt);
    break;
    }

    return copy;
}

node_array *map_array(node_array *array, node *(*func)(node *element))
{
    node_array *mapped_array = create_array();

    for (int i = 0; i < array->array_info->capacity; i++)
    {   
        node *element_copy = create_copy(array->data[i]);
        mapped_array->array_info->add(mapped_array, func(element_copy));
    }

    return mapped_array;
}

node_array *where_array(node_array *array, bool (*func)(node *element))
{
    node_array *new_array = create_array();

    for (int i = 0; i < array->array_info->capacity; i++)
    {
        if (func(array->data[i]))
        {
            node *element_copy = create_copy(array->data[i]);
            new_array->array_info->add(new_array, element_copy);
        }
    }

    return new_array;
}

node_array *cancat_arrays(node_array *array1, node_array *array2)
{
    node_array *cancated_array = create_array();

    for(int i = 0; i < array1->array_info->capacity; i++)
    {   
        node *element_copy = create_copy(array1->data[i]);
        cancated_array->array_info->add(cancated_array, element_copy);
    }

    for(int i = 0; i < array2->array_info->capacity; i++)
    {
        node *element_copy = create_copy(array2->data[i]);
        cancated_array->array_info->add(cancated_array, element_copy);
    }

    return cancated_array;
}

int get_gap(int gap)
{
	gap = gap * 10 / 13;
	if (gap < 1) return 1;
	return gap;
}

void swap_nodes(node *element1, node *element2)
{
    float *data = (float *)element1->data;

    element1->data = element2->data;
    element2->data = (void *)data;
}

int float_cmp(node *element1, node *element2)
{
    if (*(float *)element1->data > *(float *)element2->data) return 1;
    else if (*(float *)element1->data < *(float *)element2->data) return -1;
    return 0;
}


int float_cmpr(node *element1, node *element2)
{
    if (*(float *)element1->data > *(float *)element2->data) return -1;
    else if (*(float *)element1->data < *(float *)element2->data) return 1;
    return 0;
}

void comb_sort(node_array *array, int (*comparator)(node *element1, node *element2))
{
    int gap = array->array_info->capacity;
	int flag = 1;

	while(gap != 1 || flag == 1)
	{
		gap = get_gap(gap);
		flag = 0;

		for (int i = 0; i < (array->array_info->capacity - gap); i++)
		{
			if (comparator(array->data[i], array->data[i + gap]) == 1)
			{
				swap_nodes(array->data[i], array->data[i + gap]);
			}
		}
	}
}

bool test_func(node *element)
{
    switch (element->node_info->size)
    {
        case sizeof(complex):
            if (((complex *)element->data)->x_point + ((complex *)element->data)->y_point > 10)
            {
                return true;
            }
            return false;
        break;
        case sizeof(float):
            if (*(float *)element->data > 1)
            {
                return true;
            }
            return false;
        break;
    }
}

node *test_map(node *element)
{
    switch (element->node_info->size)
    {
    case sizeof(complex):
        ((complex *)element->data)->x_point++;
        ((complex *)element->data)->y_point++;
    break;
    
    case sizeof(float):
        (*(float *)element->data)++;
    break;
    }

    return element;
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
    (*class)->map = &map_array;
    (*class)->where = &where_array;
    (*class)->cancat = &cancat_arrays;
    (*class)->sort = &comb_sort;
}