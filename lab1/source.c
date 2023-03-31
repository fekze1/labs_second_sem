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

float str_to_float(char *string)
{
    float number = 0;
    int point_index = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '.')
        {
            point_index = i;
            break;
        }
    }

    char *int_part = (char *)calloc(point_index + 2, sizeof(char));

    for (int i = 0; i < point_index; i++)
    {
       int_part[i] = string[i];
    }

    number += atoi(int_part);
    free(int_part);
    
    int decimal_length = (int)strlen(string) - point_index;

    char *decimal_part = (char *)calloc(decimal_length, sizeof(char));
    
    for (int i = 0, j = point_index + 1; i < decimal_length; i++, j++)
    {
        decimal_part[i] = string[j];
    }

    float decimal = atoi(decimal_part);

    number += decimal * pow(10, -decimal_length + 1) * 1.0000001;
    free(decimal_part);

    return number;
}

node_array **create_database()
{
    node_array **database = (node_array **)malloc(sizeof(node_array *));
    return database;
}

node_array **add_array(node_array **database, int *count)
{   
    (*count)++;
    database = (node_array **)realloc(database, *count * sizeof(node_array *));

    database[*count - 1] = create_array();

    return database;
}

void delete_database(node_array **database, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("test\n");
        database[i]->array_info->delete(database[i]);
    }

    free(database);
}

void print_database(node_array **database, int count)
{
    system("clear");

    for (int i = 0; i < count; i++)
    {
        printf("\n\tID: %d\n", i + 1);
        
        switch (database[i]->array_info->element_size)
        {
            case (int)sizeof(complex):
                printf("\tTYPE: COMPLEX\n");
            break;

            case (int)sizeof(float):
                printf("\tTYPE: FLOAT\n");
            break;

            default:
                printf("\tNO TYPE\n");
            break;
        }
        printf("\tCOUNT: %d\n", database[i]->array_info->count);
    }
}

void print_menu()
{
    printf("\n\t\t\t\033[40m\033[92m      LIST OF COMMANDS    \033[0m\n");
	printf("\t\t\t\033[40m\033[92m1. ADD ARRAY              \033[0m\n");
	printf("\t\t\t\033[40m\033[92m2. ADD ELEMENT TO ARRAY   \033[0m\n");
	printf("\t\t\t\033[40m\033[92m3. DELETE ELEMENT IN ARRAY\033[0m\n");
	printf("\t\t\t\033[40m\033[92m4. PRINT ARRAY            \033[0m\n");
    printf("\t\t\t\033[40m\033[92m5. PRINT ALL ARRAYS       \033[0m\n");
	printf("\t\t\t\033[40m\033[92m6. CANCATINATE TWO ARRAYS \033[0m\n");
    printf("\t\t\t\033[40m\033[92m7. SORT ARRAY             \033[0m\n");
    printf("\t\t\t\033[40m\033[92m8. MAP ARRAY              \033[0m\n");
    printf("\t\t\t\033[40m\033[92m9. USE WHERE IN ARRAY     \033[0m\n");
	printf("\t\t\t\033[40m\033[92m10. EXIT                  \033[0m\n");
}

void command_input()
{
    printf("Input command: ");
}

void ID_input()
{
    printf("Input array ID: ");
}

void first_ID_input()
{
    printf("Input first array ID: ");
}

void second_ID_input()
{
    printf("Input second array ID: ");
}

void element_ID_input()
{
    printf("Input element ID: ");
}

void type_input()
{
    printf("Input element type (complex/float): ");
}

void float_value_input()
{
    printf("Input element float value: ");
}

void complex_xpoint_value_input()
{
    printf("Input element float X value: ");
}

void complex_ypoint_value_input()
{
    printf("Input element float Y value: ");
}

void invalid_ID_input()
{
    printf("Invalid ID input, try again: ");
}

void invalid_type_input()
{
    printf("Invalid type input, try again (complex/float): ");
}

void invalid_float_input()
{
    printf("Invalid float input, try again: ");
}

void invalid_command()
{
    system("clear");
    printf("\t\t\t\033[91m     INVALID COMMAND\033[0m\n");
}

void error_completion()
{
    system("clear");
    printf("\t\t\t\033[91mPROGRAM ENDS WITH ERROR\033[0m\n");
}

void wrong_type()
{
    system("clear");
    printf("\t\t\033[91m  ELEMENT TYPE DOESN'T MATCH ARRAY TYPE\033[0m\n");
}

void wrong_arrays()
{
    system("clear");
    printf("\t\t\033[91m        ARRAYS TYPES DOESN'T MATCH \033[0m\n");
}

void null_database()
{
    system("clear");
    printf("\t\t\t\033[91mYOU DON'T HAVE ANY ARRAYS\033[0m\n");
}

void complex_comparation()
{
    system("clear");
    printf("\t\t\t\033[91mYOU CAN'T SORT COMPLEX ARRAY\033[0m\n");
}


void input_direction()
{
    printf("Input direction (increase/decrease): ");
}

void invalid_direction()
{
    printf("Invalid input direction, try again (increase/decrease): ");
}

void added_array()
{
    system("clear");
    printf("\t\t\t\033[92m ARRAY SUCCESFULLY ADDED\033[0m\n");
}

void cated_array()
{
    system("clear");
    printf("\t\t\033[92m   ARRAYS SUCCESFULLY CANCATINATED\033[0m\n");
}

void added_element()
{
    system("clear");
    printf("\t\t\t\033[92m ELEMENT SUCCESFULLY ADDED\033[0m\n");
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

bool string_check(char *string, node_array **database, int count)
{
    if (!string)
    {
        free(string);
        delete_database(database, count);
        return false;
    }
    return true;
}

void status()
{   
    node_array **database = create_database();
    int count = 0;

    char *command_str;
    int command = 0;

    system("clear");
    while (command != 10)
    {
        print_menu();
	    command_input();
        command_str = input_string();

        if (!string_check(command_str, database, count))
        {
            error_completion();
            exit(1);
        }
        
        command = atoi(command_str);
        free(command_str);

        switch (command)
        {
            case 1:
                database = add_array(database, &count);
                added_array();
            break;

            case 2:
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                ID_input();

                char *add_ID_str = input_string();
                if (!string_check(add_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_add = atoi(add_ID_str);

                while(ID_add <= 0 || ID_add > count)
                {
                    free(add_ID_str);
                    invalid_ID_input();

                    add_ID_str = input_string();
                    if (!string_check(add_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_add = atoi(add_ID_str);
                }
                free(add_ID_str);
                
                type_input();

                char *element_type = input_string();
                if (!string_check(element_type, database, count))
                {
                    error_completion();
                    exit(1);
                }

                while(strcmp(element_type, "float") && strcmp(element_type, "complex"))
                {
                    free(element_type);
                    invalid_type_input();

                    element_type = input_string();
                    if (!string_check(element_type, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                }
                
                if (strcmp(element_type, "complex") == 0)
                {
                    free(element_type);

                    complex_xpoint_value_input();

                    char *x_str = input_string();
                    if (!string_check(x_str, database, count))
                    {
                        free(element_type);
                        error_completion();
                        exit(1);
                    }

                    while((!strchr(x_str, '.')) || (strchr(x_str, '.') != strrchr(x_str, '.')) || x_str[0] == '.' || x_str[strlen(x_str) - 1] == '.')
                    {
                        invalid_float_input();

                        free(x_str);
                        x_str = input_string();
                        if (!string_check(x_str, database, count))
                        {
                            error_completion();
                            exit(1);
                        }
                    }
                    float x_point = str_to_float(x_str);
                    free(x_str);

                    complex_ypoint_value_input();

                    char *y_str = input_string();
                    if (!string_check(y_str, database, count))
                    {
                        error_completion();
                        exit(1);
                    }

                    while((!strchr(y_str, '.')) || (strchr(y_str, '.') != strrchr(y_str, '.')) || y_str[0] == '.' || y_str[strlen(y_str) - 1] == '.')
                    {
                        invalid_float_input();

                        free(y_str);
                        y_str = input_string();
                        if (!string_check(y_str, database, count))
                        {
                            error_completion();
                            exit(1);
                        }
                    }
                    float y_point = str_to_float(y_str);
                    free(y_str);

                    if(database[ID_add - 1]->array_info->element_size == (int)sizeof(complex) || !database[ID_add - 1]->array_info->element_size)
                    {
                        database[ID_add - 1]->array_info->add(database[ID_add - 1], complex_class.new((void *)create_complex(x_point, y_point)));
                        added_element();
                    }
                    else
                    {
                        wrong_type();
                    }
                    
                }
                else
                {
                    free(element_type);

                    float_value_input();

                    char *float_val_str = input_string();
                    if (!string_check(float_val_str, database, count))
                    {
                        error_completion();
                        exit(1);
                    }

                    while((!strchr(float_val_str, '.')) || (strchr(float_val_str, '.') != strrchr(float_val_str, '.')) || float_val_str[0] == '.' || float_val_str[strlen(float_val_str) - 1] == '.')
                    {
                        invalid_float_input();

                        free(float_val_str);
                        float_val_str = input_string();
                        if (!string_check(float_val_str, database, count))
                        {
                            error_completion();
                            exit(1);
                        }
                    }
                    float float_val = str_to_float(float_val_str);
                    free(float_val_str);

                    if(database[ID_add - 1]->array_info->element_size == (int)sizeof(float) || !database[ID_add - 1]->array_info->element_size)
                    {
                        database[ID_add - 1]->array_info->add(database[ID_add - 1], float_class.new((void *)create_float(float_val)));
                        added_element();
                    }
                    else
                    {
                        wrong_type();
                    }
                }
            break;

            case 3:
                if (!count)
                {   
                    null_database();
                    break;
                }
                
                print_database(database, count);
                ID_input();

                char *delete_ID_str = input_string();
                if (!string_check(delete_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_delete = atoi(delete_ID_str);

                while(ID_delete <= 0 || ID_delete > count)
                {
                    free(delete_ID_str);
                    invalid_ID_input();

                    delete_ID_str = input_string();
                    if (!string_check(delete_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_delete = atoi(delete_ID_str);
                }

                free(delete_ID_str);
                
                system("clear");
                database[ID_delete - 1]->array_info->print(database[ID_delete - 1]);
                element_ID_input();

                char *element_ID_str = input_string();
                if (!string_check(element_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_element = atoi(element_ID_str);

                while(ID_delete <= 0 || ID_delete > count)
                {
                    free(element_ID_str);
                    invalid_ID_input();

                    element_ID_str = input_string();
                    if (!string_check(element_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_element = atoi(element_ID_str);
                }

                free(element_ID_str);

                database[ID_element - 1]->array_info->delete_by_id(database[ID_delete - 1], ID_element - 1);
            break;

            case 4:
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                ID_input();

                char *print_ID_str = input_string();
                if (!string_check(print_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_print = atoi(print_ID_str);

                while(ID_print <= 0 || ID_print > count)
                {
                    free(print_ID_str);
                    invalid_ID_input();

                    print_ID_str = input_string();
                    if (!string_check(print_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_print = atoi(print_ID_str);
                }

                free(print_ID_str);
                system("clear");
                database[ID_print - 1]->array_info->print(database[ID_print - 1]);
            break;

            case 5:
                if (!count)
                {
                    null_database();
                    break;
                }
                
                print_database(database, count);
            break;

            case 6:
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                first_ID_input();

                char *array1_ID_str = input_string();
                if (!string_check(array1_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_array1 = atoi(array1_ID_str);

                while(ID_array1 <= 0 || ID_array1 > count)
                {
                    free(array1_ID_str);
                    invalid_ID_input();

                    array1_ID_str = input_string();
                    if (!string_check(array1_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_array1 = atoi(array1_ID_str);
                }

                free(array1_ID_str);

                system("clear");
                print_database(database, count);
                second_ID_input();

                char *array2_ID_str = input_string();
                if (!string_check(array2_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_array2 = atoi(array2_ID_str);

                while(ID_array2 <= 0 || ID_array2 > count)
                {
                    free(array2_ID_str);
                    invalid_ID_input();

                    array2_ID_str = input_string();
                    if (!string_check(array2_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_array2 = atoi(array2_ID_str);
                }

                free(array2_ID_str);
                
                if (database[ID_array1 - 1]->array_info->element_size == database[ID_array2 - 1]->array_info->element_size )
                {
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_array1 - 1]->array_info->cancat(database[ID_array1 - 1], database[ID_array2 - 1]);

                    cated_array();
                }
                else wrong_arrays();
            break;

            case 7:
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                ID_input();

                char *sort_ID_str = input_string();
                if (!string_check(sort_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_sort = atoi(sort_ID_str);

                while(ID_sort <= 0 || ID_sort > count)
                {
                    free(sort_ID_str);
                    invalid_ID_input();

                    sort_ID_str = input_string();
                    if (!string_check(sort_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_sort = atoi(sort_ID_str);
                }

                free(sort_ID_str);
                
                input_direction();

                char *direction = input_string();
                if (!string_check(direction, database, count))
                {
                    error_completion();
                    exit(1);
                }

                while(strcmp(direction, "increase") && strcmp(direction, "decrease"))
                {
                    free(direction);
                    invalid_direction();

                    direction = input_string();
                    if (!string_check(direction, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                }
                if (strcmp(direction, "increase") == 0)
                {
                    if (database[ID_sort - 1]->array_info->element_size == (int)sizeof(float))
                    {
                        database[ID_sort - 1]->array_info->sort(database[ID_sort - 1], float_cmp);
                    }
                    else
                    {
                        complex_comparation();
                    }
                }
                else
                {
                    if (database[ID_sort - 1]->array_info->element_size == (int)sizeof(float))
                    {
                        database[ID_sort - 1]->array_info->sort(database[ID_sort - 1], float_cmpr);
                    }
                    else
                    {
                        complex_comparation();
                    }
                }

                free(direction);

            break;

            case 8:
            break;

            case 9:
            break;

            case 10:
                delete_database(database, count);
                completion();
            break;

            default:
                invalid_command();
            break;
        }
        
    }
}