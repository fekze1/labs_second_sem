#include "testcases.h"
#include <stdio.h>

int main()
{
    create_add_delete_test();

    element_delete_set_test();

    cat_sort_map_where_test();


	printf("ALL TESTS PASSED\n");
    return 0;
}
