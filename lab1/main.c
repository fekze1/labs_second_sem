#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "complex.h"
#include "outputs.h"
#include "dynarr.h"

int main()
{
    complex_array test1 = create_cmplx_arr(10);
    float_array test2 = create_flt_arr(10);

    add_complex(&test1, (complex){1, 1});
    add_float(&test2, 2.12412);

    delete_data(test1.data);
    delete_data(test2.data);
    return 0;
}