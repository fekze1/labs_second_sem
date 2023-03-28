#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "float.h"
#include "source.h"
#include "array.h"

int main()
{   
    node_array *test = new_array();

    node_array *test2 = new_array();
    
    float flt = 1.2345;
    complex cmplx = create_complex(1.234, 5.678);
    
    node *flt_node = float_class.new((void *)&flt);
    node *cmplx_node = complex_class.new((void *)&cmplx);
    
    test->array_info->add(test, flt_node);
    test2->array_info->add(test2, cmplx_node);

    test->array_info->print(test);
    test2->array_info->print(test2);



    test2->array_info->delete(test2);
    test->array_info->delete(test);
    return 0;
}