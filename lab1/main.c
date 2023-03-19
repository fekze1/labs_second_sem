#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "complex.h"
#include "outputs.h"
#include "dynarr.h"

complex test(complex element)
{
    return find_mul_cmplx(element, (complex){.x_point = 123, .y_point = 321});
}

float func(float element)
{
    return element * 0.01;
}

int main()
{
    float_array test1 = create_flt_arr(5);
    for (int i = 0; i < test1.capacity; i++) test1.data[i] = (i + ((1.) / (i + 1)));
    float_array test2 = create_flt_arr(5);
    for (int i = 0; i < test2.capacity; i++) test2.data[i] = (i + ((1.) / (i + 1)));


    float_array test3 = cancat_and_del_flt(test1, &test2);

    float_array test4 = map_and_del_flt(func, &test3);
    
    //print_flt_arr(test3);
    printf("\n");
    print_flt_arr(test4);

    delete_data(test4.data);
    //delete_data(test3.data);
    delete_data(test1.data);
    return 0;
}