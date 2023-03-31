#include "source.h"
#include "complex.h"
#include "outputs.h"
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
    printf("\n");

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
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                ID_input();

                char *map_ID_str = input_string();
                if (!string_check(map_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_map = atoi(map_ID_str);

                while(ID_map <= 0 || ID_map > count)
                {
                    free(map_ID_str);
                    invalid_ID_input();

                    map_ID_str = input_string();
                    if (!string_check(map_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_map = atoi(map_ID_str);
                }

                free(map_ID_str);

                print_map_menu();

                map_command_input();

                char *map_command_str = input_string();
                if (!string_check(map_command_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int command_map = atoi(map_command_str);
                free(map_command_str);

                switch (command_map)
                {
                case 1:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_map - 1]->array_info->map(database[ID_map - 1], abs_val_map);

                    mapped_array();
                break;

                case 2:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_map - 1]->array_info->map(database[ID_map - 1], double_val_map);

                    mapped_array();
                break;

                case 3:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_map - 1]->array_info->map(database[ID_map - 1], square_val_map);

                    mapped_array();
                break;
                
                default:
                break;
                }

            break;

            case 9:
                if (!count)
                {   
                    null_database();
                    break;
                }

                print_database(database, count);
                ID_input();

                char *where_ID_str = input_string();
                if (!string_check(where_ID_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int ID_where = atoi(where_ID_str);

                while(ID_where <= 0 || ID_where > count)
                {
                    free(where_ID_str);
                    invalid_ID_input();

                    where_ID_str = input_string();
                    if (!string_check(where_ID_str, database, count))
                    {   
                        error_completion();
                        exit(1);
                    }
                    ID_where = atoi(where_ID_str);
                }

                free(where_ID_str);

                print_where_menu();

                where_command_input();

                char *where_command_str = input_string();
                if (!string_check(where_command_str, database, count))
                {
                    error_completion();
                    exit(1);
                }

                int command_where = atoi(where_command_str);

                switch (command_where)
                {
                case 1:
                    if (database[ID_where - 1]->array_info->element_size == (int)sizeof(float))
                    {
                        database = add_array(database, &count);

                        database[count - 1]->array_info->delete(database[count - 1]);

                        database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], poistive_where);

                        filtered_array();
                    }
                    else if (database[ID_where - 1]->array_info->element_size == (int)sizeof(complex))
                    {
                        complex_positive();
                    }
                    else
                    {
                        null_array();
                    }
                break;

                case 2:
                    if (database[ID_where - 1]->array_info->element_size == (int)sizeof(float))
                    {
                        database = add_array(database, &count);

                        database[count - 1]->array_info->delete(database[count - 1]);

                        database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], negative_where);

                        filtered_array();
                    }
                    else if (database[ID_where - 1]->array_info->element_size == (int)sizeof(complex))
                    {
                        complex_negative();
                    }
                    else
                    {
                        null_array();
                    }
                break;

                case 3:
                    if (database[ID_where - 1]->array_info->element_size == (int)sizeof(float))
                    {
                        database = add_array(database, &count);

                        database[count - 1]->array_info->delete(database[count - 1]);

                        database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], integers_where);

                        filtered_array();
                    }
                    else if (database[ID_where - 1]->array_info->element_size == (int)sizeof(complex))
                    {
                        complex_integers();
                    }
                    else
                    {
                        null_array();
                    }
                break;

                case 4:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], first_quad_where);

                    filtered_array();
                break;

                case 5:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], second_quad_where);

                    filtered_array();
                break;

                case 6:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], third_quad_where);

                    filtered_array();
                break;

                case 7:
                    database = add_array(database, &count);

                    database[count - 1]->array_info->delete(database[count - 1]);

                    database[count - 1] = database[ID_where - 1]->array_info->where(database[ID_where - 1], fourth_quad_where);

                    filtered_array();
                break;
                
                default:
                break;
                }
                free(where_command_str);
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