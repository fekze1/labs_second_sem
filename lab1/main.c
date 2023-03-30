#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "float.h"
#include "source.h"
#include "array.h"

int main()
{   
    float *test_cmplx = create_float(1.234);
    node *test_cmplx_node = float_class.new((void *)test_cmplx);
    node_array *cmplx_array = create_array();
    cmplx_array->array_info->add(cmplx_array, test_cmplx_node);
    cmplx_array->array_info->print(cmplx_array);

    node_array *cmplx_array2 = cmplx_array->array_info->where(cmplx_array, test_func);
    cmplx_array2->array_info->print(cmplx_array2);


    cmplx_array2->array_info->delete(cmplx_array2);
    cmplx_array->array_info->delete(cmplx_array);
    return 0;
}
