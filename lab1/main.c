#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "complex.h"
#include "outputs.h"
#include "dynarr.h"

bool func(float element)
{
    if (element > 0.05) return true;
    return false;
}

int main()
{
    float_array data = create_flt_arr(100);

    for (int i = 0; i < data.capacity; i++) data.data[i] = (1. / (i + 1));

    int test = where_flt_count(func, data);

    print_flt_arr(data);
    printf("\n");
    if (!test) printf("ERROR\n");
    printf("%d\n", test);

    //delete_data(test.data);
    delete_data(data.data);
    return 0;
}