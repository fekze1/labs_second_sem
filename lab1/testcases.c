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

void element_delete_set_test()
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

    node *set_float_element = (node *)malloc(sizeof(node));
    float *set_float_val = (float *)malloc(sizeof(float));
    *set_float_val = 0.2345;
    set_float_element->data = (void *)set_float_val;
    set_float_element->node_info = &float_class;

    node *set_complex_element = (node *)malloc(sizeof(node));
    complex *set_complex_val = create_complex(5.4321, 6.7890);
    set_complex_element->data = (void *)set_complex_val;
    set_complex_element->node_info = &complex_class;

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

    database[0]->array_info->set_by_id(database[0], set_float_element, 0);
    database[1]->array_info->set_by_id(database[1], set_complex_element, 0);

    assert(database[0]->data[0]->data == set_float_element->data);
    assert(database[1]->data[0]->data == set_complex_element->data);

    database[0]->array_info->delete_by_id(database[0], 0);
    database[1]->array_info->delete_by_id(database[1], 0);

    assert(!database[0]->data);
    assert(!database[1]->data);


    delete_database(database, count);

    second_passed();
}

void cat_sort_map_where_test()
{
    node *float_element_arr1 = (node *)malloc(sizeof(node));
    float *float_val_arr1 = (float *)malloc(sizeof(float));
    *float_val_arr1 = 0.1234;
    float_element_arr1->data = (void *)float_val_arr1;
    float_element_arr1->node_info = &float_class;

    node *float_element_arr2 = (node *)malloc(sizeof(node));
    float *float_val_arr2 = (float *)malloc(sizeof(float));
    *float_val_arr2 = 1.1234;
    float_element_arr2->data = (void *)float_val_arr2;
    float_element_arr2->node_info = &float_class;

    node *float_element_arr3 = (node *)malloc(sizeof(node));
    float *float_val_arr3 = (float *)malloc(sizeof(float));
    *float_val_arr3 = 2.1234;
    float_element_arr3->data = (void *)float_val_arr3;
    float_element_arr3->node_info = &float_class;

    node *float_element_arr4 = (node *)malloc(sizeof(node));
    float *float_val_arr4 = (float *)malloc(sizeof(float));
    *float_val_arr4 = 4.1234;
    float_element_arr4->data = (void *)float_val_arr4;
    float_element_arr4->node_info = &float_class;

    node *float_element_arr5 = (node *)malloc(sizeof(node));
    float *float_val_arr5 = (float *)malloc(sizeof(float));
    *float_val_arr5 = 5.1234;
    float_element_arr5->data = (void *)float_val_arr5;
    float_element_arr5->node_info = &float_class;

    node *float_element_arr6 = (node *)malloc(sizeof(node));
    float *float_val_arr6 = (float *)malloc(sizeof(float));
    *float_val_arr6 = 6.1234;
    float_element_arr6->data = (void *)float_val_arr6;
    float_element_arr6->node_info = &float_class;

    node *float_element1 = (node *)malloc(sizeof(node));
    float *float_val1 = (float *)malloc(sizeof(float));
    *float_val1 = 0.1234;
    float_element1->data = (void *)float_val1;
    float_element1->node_info = &float_class;

    node *float_element2 = (node *)malloc(sizeof(node));
    float *float_val2 = (float *)malloc(sizeof(float));
    *float_val2 = 1.1234;
    float_element2->data = (void *)float_val2;
    float_element2->node_info = &float_class;

    node *float_element3 = (node *)malloc(sizeof(node));
    float *float_val3 = (float *)malloc(sizeof(float));
    *float_val3 = 2.1234;
    float_element3->data = (void *)float_val3;
    float_element3->node_info = &float_class;

    node *float_element4 = (node *)malloc(sizeof(node));
    float *float_val4 = (float *)malloc(sizeof(float));
    *float_val4 = 4.1234;
    float_element4->data = (void *)float_val4;
    float_element4->node_info = &float_class;

    node *float_element5 = (node *)malloc(sizeof(node));
    float *float_val5 = (float *)malloc(sizeof(float));
    *float_val5 = 5.1234;
    float_element5->data = (void *)float_val5;
    float_element5->node_info = &float_class;

    node *float_element6 = (node *)malloc(sizeof(node));
    float *float_val6 = (float *)malloc(sizeof(float));
    *float_val6 = 6.1234;
    float_element6->data = (void *)float_val6;
    float_element6->node_info = &float_class;

    node_array *float_array1 = (node_array *)malloc(sizeof(node_array));
    float_array1->array_info = (node_array_class *)malloc(sizeof(node_array_class));
    float_array1->data = (node **)malloc(3 * sizeof(node *));

    node_array *float_array2 = (node_array *)malloc(sizeof(node_array));
    float_array2->array_info = (node_array_class *)malloc(sizeof(node_array_class));
    float_array2->data = (node **)malloc(3 * sizeof(node *));

    set_array_class(&float_array1->array_info);
    set_array_class(&float_array2->array_info);

    float_array1->data[0] = float_element_arr3;
    float_array1->data[1] = float_element_arr2;
    float_array1->data[2] = float_element_arr1;
    float_array1->array_info->element_size = (int)sizeof(float);
    float_array1->array_info->count = 3;
    float_array1->array_info->capacity = 3;

    float_array2->data[0] = float_element_arr4;
    float_array2->data[1] = float_element_arr5;
    float_array2->data[2] = float_element_arr6;
    float_array2->array_info->element_size = (int)sizeof(float);
    float_array2->array_info->count = 3;
    float_array2->array_info->capacity = 3;

    int count = 0;
    node_array **database = create_database();
    database = add_array(database, &count);
    database = add_array(database, &count);

    database[0]->array_info->add(database[0], float_element1);
    database[0]->array_info->add(database[0], float_element2);
    database[0]->array_info->add(database[0], float_element3);

    database[1]->array_info->add(database[1], float_element4);
    database[1]->array_info->add(database[1], float_element5);
    database[1]->array_info->add(database[1], float_element6);
    
    database[0]->array_info->sort(database[0], float_cmpr);

    database = add_array(database, &count);
    database[count - 1]->array_info->delete(database[count - 1]);
    database[2] = database[1]->array_info->cancat(database[0], database[1]);

    database = add_array(database, &count);
    database[count - 1]->array_info->delete(database[count - 1]);
    database[3] = database[2]->array_info->map(database[2], double_val_map);

    database = add_array(database, &count);
    database[count - 1]->array_info->delete(database[count - 1]);
    database[4] = database[2]->array_info->where(database[2], integers_where);

    assert(*(float *)float_array1->data[0]->data == *(float *)database[0]->data[0]->data);
    assert(*(float *)float_array1->data[1]->data == *(float *)database[0]->data[1]->data);
    assert(*(float *)float_array1->data[2]->data == *(float *)database[0]->data[2]->data);

    assert(*(float *)float_array1->data[0]->data == *(float *)database[2]->data[0]->data);
    assert(*(float *)float_array1->data[1]->data == *(float *)database[2]->data[1]->data);
    assert(*(float *)float_array1->data[2]->data == *(float *)database[2]->data[2]->data);
    assert(*(float *)float_array2->data[0]->data == *(float *)database[2]->data[3]->data);
    assert(*(float *)float_array2->data[1]->data == *(float *)database[2]->data[4]->data);
    assert(*(float *)float_array2->data[2]->data == *(float *)database[2]->data[5]->data);

    assert(*(float *)float_array1->data[0]->data * 2 == *(float *)database[3]->data[0]->data);
    assert(*(float *)float_array1->data[1]->data * 2 == *(float *)database[3]->data[1]->data);
    assert(*(float *)float_array1->data[2]->data * 2 == *(float *)database[3]->data[2]->data);
    assert(*(float *)float_array2->data[0]->data * 2 == *(float *)database[3]->data[3]->data);
    assert(*(float *)float_array2->data[1]->data * 2 == *(float *)database[3]->data[4]->data);
    assert(*(float *)float_array2->data[2]->data * 2 == *(float *)database[3]->data[5]->data);

    assert(!database[4]->array_info->count);

    free(float_array2->array_info);
    free(float_array2->data[0]->data);
    free(float_array2->data[0]);
    free(float_array2->data[1]->data);
    free(float_array2->data[1]);
    free(float_array2->data[2]->data);
    free(float_array2->data[2]);
    free(float_array2->data);
    free(float_array2);

    free(float_array1->array_info);
    free(float_array1->data[0]->data);
    free(float_array1->data[0]);
    free(float_array1->data[1]->data);
    free(float_array1->data[1]);
    free(float_array1->data[2]->data);
    free(float_array1->data[2]);
    free(float_array1->data);
    free(float_array1);

    delete_database(database, count);

    third_passed();
}