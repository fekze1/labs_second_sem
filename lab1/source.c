#include "source.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool input_str(char **string) 
{
	*string = (char *)malloc(1);
	char buffer[81];
	int n, str_length = 0;
	**string = '\0';
	
	do
	{
		n = scanf("%80[^\n]", buffer);
		
		if(n < 0)
		{
			free(*string);
			*string = NULL;
			continue;
		}

		if(n == 0) scanf("%*c");

		else 
		{
			str_length += strlen(buffer);
			*string = (char *)realloc(*string, str_length + 1);
			*string = strcat(*string, buffer);
		}	
	} while(n > 0);

	if (!(*string)) return false;
	
	return true;
}