#include "source.h"
#include "complex.h"
#include "array.h"
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