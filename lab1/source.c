#include "source.h"
#include "complex.h"
#include "array.h"
#include "float.h"
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
        getchar();
        free(string);
        return NULL;
    }

	while (currentChar != '\n' && currentChar != EOF){
		while (currentChar == ' ' || currentChar == '\t'){
            
			currentChar = getchar();
			if (currentChar == '\n') return NULL;
			
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

void print_menu()
{
    printf("\n\t\t\t\033[40m\033[92m      LIST OF COMMANDS    \033[0m\n");
	printf("\t\t\t\033[40m\033[92m1. CREATE ARRAY           \033[0m\n");
	printf("\t\t\t\033[40m\033[92m2. ADD ELEMENT            \033[0m\n");
	printf("\t\t\t\033[40m\033[92m3. DELETE ELEMENT         \033[0m\n");
	printf("\t\t\t\033[40m\033[92m4. PRINT ARRAY            \033[0m\n");
	printf("\t\t\t\033[40m\033[92m5. CANCATINATE TWO ARRAYS \033[0m\n");
    printf("\t\t\t\033[40m\033[92m6. SORT ARRAY             \033[0m\n");
    printf("\t\t\t\033[40m\033[92m7. MAP ARRAY              \033[0m\n");
    printf("\t\t\t\033[40m\033[92m8. USE WHERE IN ARRAY     \033[0m\n");
	printf("\t\t\t\033[40m\033[92m9. EXIT                   \033[0m\n");
}

void command_input()
{
    printf("Input command: ");
}

void invalid_input()
{
    printf("Invalid input, try again: ");
}

void error_completion()
{
    system("clear");
    printf("\t\t\t\033[91mPROGRAM ENDS WITH ERROR\033[0m\n");
}

void completion()
{
    system("clear");
    printf("\t\t\t\033[92m   PROGRAM COMPLETION\033[0m\n");
}

bool input_check(char *input)
{
    if (!input) return false;
    return true;
}

void status()
{   
    char *command_str;
    int command = 0;

    while (command != 9)
    {
        print_menu();
	    command_input();
        command_str = input_string();

        while (!command_str)
        {
            free(command_str);
            //DELETE ALL ARRAYS
            error_completion();
            exit(1);
        }
        
        command = atoi(command_str);
        free(command_str);

        switch (command)
        {
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;

            case 9:
                //DELETE ALL ARRAYS
                completion();
            break;
        }
        
    }
    
}