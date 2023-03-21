#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "source.h"
#include "array.h"

int main()
{  
    char *test = input_string();

    if (test) printf("%s\n", test);
    if (!test) printf("ERROR\n");

    free(test);
    return 0;
}