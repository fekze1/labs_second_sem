#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "source.h"
#include "outputs.h"
#include "array.h"
#include "testcases.h"
#include "complex.h"
#include "float.h"

void create_add_delete_test()
{
    node *float_element_arr = (node *)malloc(sizeof(node));
    float *float_val_arr = (float *)malloc(sizeof(float));
    *float_val_arr = 1.2345;
    float_element_arr->data = (void *)float_val_arr;
    float_element_arr->node_info = &float_class;

    node *complex_element_arr = (node *)malloc(sizeof(node));
    complex *complex_val_arr = create_complex(5.4321, 6.7890);
    complex_element_arr->data = (void *)complex_val_arr;
    complex_element_arr->node_info = &complex_class;

    node *float_element = (node *)malloc(sizeof(node));
    float *float_val = (float *)malloc(sizeof(float));
    *float_val = 1.2345;
    float_element->data = (void *)float_val;
    float_element->node_info = &float_class;

    node *complex_element = (node *)malloc(sizeof(node));
    complex *complex_val = create_complex(5.4321, 6.7890);
    complex_element->data = (void *)complex_val;
    complex_element->node_info = &complex_class;

    int count = 0;
    node_array **database = create_database();
    database = add_array(database, &count);
    database = add_array(database, &count);

    database[0]->array_info->add(database[0], float_element);
    database[1]->array_info->add(database[1], complex_element);

    node_array *float_array = (node_array *)malloc(sizeof(node_array));
    float_array->array_info = (node_array_class *)malloc(sizeof(node_array_class));
    float_array->data = (node **)malloc(sizeof(node *));

    node_array *complex_array = (node_array *)malloc(sizeof(node_array));
    complex_array->array_info = (node_array_class *)malloc(sizeof(node_array_class));
    complex_array->data = (node **)malloc(sizeof(node *));

    set_array_class(&float_array->array_info);
    set_array_class(&complex_array->array_info);

    float_array->data[0] = float_element_arr;
    float_array->array_info->element_size = (int)sizeof(float);
    float_array->array_info->count = 1;
    float_array->array_info->capacity = 1;

    complex_array->data[0] = complex_element_arr;
    complex_array->array_info->element_size = (int)sizeof(complex);
    complex_array->array_info->count = 1;
    complex_array->array_info->capacity = 1;

    assert(database[0]->array_info->element_size == float_array->array_info->element_size);
    assert(database[0]->array_info->capacity == float_array->array_info->capacity);
    assert(database[0]->array_info->count == float_array->array_info->count);
    assert(database[0]->array_info->add = float_array->array_info->add);
    assert(database[0]->array_info->delete_by_id == float_array->array_info->delete_by_id);
    assert(database[0]->array_info->delete == float_array->array_info->delete);
    assert(database[0]->array_info->print == float_array->array_info->print);
    assert(database[0]->array_info->map == float_array->array_info->map);
    assert(database[0]->array_info->where == float_array->array_info->where);
    assert(database[0]->array_info->cancat == float_array->array_info->cancat);
    assert(database[0]->array_info->sort == float_array->array_info->sort);

    assert(database[1]->array_info->element_size == complex_array->array_info->element_size);
    assert(database[1]->array_info->capacity == complex_array->array_info->capacity);
    assert(database[1]->array_info->count == complex_array->array_info->count);
    assert(database[1]->array_info->add = complex_array->array_info->add);
    assert(database[1]->array_info->delete_by_id == complex_array->array_info->delete_by_id);
    assert(database[1]->array_info->delete == complex_array->array_info->delete);
    assert(database[1]->array_info->print == complex_array->array_info->print);
    assert(database[1]->array_info->map == complex_array->array_info->map);
    assert(database[1]->array_info->where == complex_array->array_info->where);
    assert(database[1]->array_info->cancat == complex_array->array_info->cancat);
    assert(database[1]->array_info->sort == complex_array->array_info->sort);

    database = delete_array_in_database(database, &count, 0);

    assert(database[0]->array_info->element_size == complex_array->array_info->element_size);
    assert(database[0]->array_info->capacity == complex_array->array_info->capacity);
    assert(database[0]->array_info->count == complex_array->array_info->count);
    assert(database[0]->array_info->add = complex_array->array_info->add);
    assert(database[0]->array_info->delete_by_id == complex_array->array_info->delete_by_id);
    assert(database[0]->array_info->delete == complex_array->array_info->delete);
    assert(database[0]->array_info->print == complex_array->array_info->print);
    assert(database[0]->array_info->map == complex_array->array_info->map);
    assert(database[0]->array_info->where == complex_array->array_info->where);
    assert(database[0]->array_info->cancat == complex_array->array_info->cancat);
    assert(database[0]->array_info->sort == complex_array->array_info->sort);

    database = delete_array_in_database(database, &count, 0);

    assert(!database);

    free(float_array->data[0]->data);
    free(float_array->data[0]);
    free(float_array->data);
    free(float_array->array_info);
    free(float_array);

    free(complex_array->data[0]->data);
    free(complex_array->data[0]);
    free(complex_array->data);
    free(complex_array->array_info);
    free(complex_array);

    delete_database(database, count);

    first_passed();
}

void element_deleting_set_test()
{
    node *float_element1 = (node *)malloc(sizeof(node));
    float *float_val1 = (float *)malloc(sizeof(float));
    *float_val1 = 1.2345;
    float_element1->data = (void *)float_val1;
    float_element1->node_info = &float_class;

    node *float_element2 = (node *)malloc(sizeof(node));
    float *float_val2 = (float *)malloc(sizeof(float));
    *float_val2 = 2.2345;
    float_element2->data = (void *)float_val2;
    float_element2->node_info = &float_class;

    node *complex_element1 = (node *)malloc(sizeof(node));
    complex *complex_val1 = create_complex(5.4321, 6.7890);
    complex_element1->data = (void *)complex_val1;
    complex_element1->node_info = &complex_class;

    node *complex_element2 = (node *)malloc(sizeof(node));
    complex *complex_val2 = create_complex(6.4321, 7.7890);
    complex_element2->data = (void *)complex_val2;
    complex_element2->node_info = &complex_class;

    int count = 0;
    node_array **database = create_database();
    database = add_array(database, &count);
    database = add_array(database, &count);

    database[0]->array_info->add(database[0], float_element1);
    database[0]->array_info->add(database[0], float_element2);

    database[1]->array_info->add(database[1], complex_element1);
    database[1]->array_info->add(database[1], complex_element2);

    database[0]->array_info->delete_by_id(database[0], 0);
    database[1]->array_info->delete_by_id(database[1], 0);

    assert(database[0]->data[0]->data == float_element2->data);
    assert(database[1]->data[0]->data == complex_element2->data);

    database[0]->array_info->delete_by_id(database[0], 0);
    database[1]->array_info->delete_by_id(database[1], 0);

    assert(!database[0]->data);
    assert(!database[1]->data);


    delete_database(database, count);
}

void command3_test()
{

}