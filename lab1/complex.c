#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char *int_to_str(int number)
{
    unsigned int length = log10(number) + 1;
    if (!length) length = 1;

    int string_length = length + 1;
    char *string = (char *)calloc(string_length, sizeof(char));

    int i = 0;
    do
    {
        int last_digit = number % 10;
        string[string_length - i - 2] = last_digit + 48;
        number /= 10;
        i++;
    } while (number > 0);

    return string;
}

char *flt_to_str(float number)
{
    int integer = (int)number;
    int decimal = (number - (int)number) * 100000;

    char *integer_str = int_to_str(integer);
    char *decimal_str = int_to_str(decimal);

    int new_len = (int)(strlen(integer_str) + strlen(decimal_str)) + 2;

    char *string = (char *)calloc(new_len, sizeof(char));

    for (int i = 0; i < (int)(strlen(integer_str)); i++)
    {
        string[i] = integer_str[i];
    }
    string[(int)(strlen(integer_str))] = '.';
    for (int i = (int)(strlen(integer_str)) + 1, j = 0; i < new_len; i++, j++)
    {
        string[i] = decimal_str[j];
    }

    free(integer_str);
    free(decimal_str);
    
    return string;
}

// void print_complex(complex number)
// {
//     char *output = to_string(number);
//     puts(output);
// }