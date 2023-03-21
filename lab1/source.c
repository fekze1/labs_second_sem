#include "source.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

char *input_string()
{
    int length = 0;
    char *string = (char *)calloc(1, sizeof(char));

    char currentChar = getchar();
	
	if (currentChar == EOF)
    {
        free(string);
        return NULL;
    }

	while (currentChar != '\n'){
		while (currentChar == ' ' || currentChar == '\t'){
		
			currentChar = getchar();
			if (currentChar == '\n') return 0;
			
			if (currentChar != ' ' && currentChar != '\t'){
				length++;
                string = (char *)realloc(string, length * sizeof(char));
                string[length - 1] = currentChar;
			} 
		}
		
		length++;
        string = (char *)realloc(string, length * sizeof(char));
        string[length - 1] = currentChar;

		currentChar = getchar();
	}

    length++;
    string = (char *)realloc(string, length * sizeof(char));
    string[length - 1] = '\0';
    return string;
}

// void print_complex(void *value)
// {
//     node *node_val = (node *)value;
//     printf("%d\n", *(int *)node_val->data);
// }

node *new_complex(void *value)
{
    int *value_int_ptr = (int *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &complex_class;
    new_node->data = (void *)value_int_ptr;

    return new_node;
}

void print_float(void *value)
{
    node *node_val = (node *)value;
    printf("%f\n", *(float *)node_val->data);
}

node *new_float(void *value)
{
    float *value_float_ptr = (float *)value;

    node *new_node = (node *)malloc(sizeof(node));

    new_node->node_info = &float_class;
    new_node->data = (void *)value_float_ptr;

    return new_node;
}

class complex_class = 
{
    //.print = &print_complex,
    .new = &new_complex
};

class float_class = 
{
    .print = &print_float,
    .new = &new_float
};