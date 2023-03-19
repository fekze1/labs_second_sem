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
    complex_array data = create_cmplx_arr(100);

    for (int i = 0; i < data.capacity; i++) data.data[i] = create_complex(i, i - 1);

    print_cmplx_arr(data);


    delete_data(data.data);
    scanf("%*d");
    remove("OUTPUT.txt");
    return 0;
}