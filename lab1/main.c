#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "source.h"
#include "array.h"

int main()
{  
    float value = 10.123;
    node *test = float_info.new(&value);

    test->node_info->print(test);

    free(test);
    return 0;
}