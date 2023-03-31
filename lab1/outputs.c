#include "outputs.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf("\n\t\t\t\033[40m\033[92m     LIST OF COMMANDS     \033[0m\n");
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

void print_map_menu()
{
    system("clear");
    printf("\n\t\t    \033[40m\033[92m     LIST OF MAPPING COMMANDS     \033[0m\n");
	printf("\t\t    \033[40m\033[92m1. FIND ABSOLUTE VALUE            \033[0m\n");
	printf("\t\t    \033[40m\033[92m2. DOUBLE VALUE                   \033[0m\n");
	printf("\t\t    \033[40m\033[92m3. FIND VALUES SQUARE             \033[0m\n");
}

void print_where_menu()
{
    system("clear");
    printf("\n\t\t    \033[40m\033[92m       LIST OF WHERE COMMANDS     \033[0m\n");
	printf("\t\t    \033[40m\033[92m1. FIND POSITIVE VALUES           \033[0m\n");
	printf("\t\t    \033[40m\033[92m2. FIND NEGATIVE VALUES           \033[0m\n");
    printf("\t\t    \033[40m\033[92m3. FIND INTEGERS                  \033[0m\n");
	printf("\t\t    \033[40m\033[92m4. FIND VALUES IN FIRST QUADRANT  \033[0m\n");
    printf("\t\t    \033[40m\033[92m5. FIND VALUES IN SECOND QUADRANT \033[0m\n");
    printf("\t\t    \033[40m\033[92m6. FIND VALUES IN THIRD QUADRANT  \033[0m\n");
    printf("\t\t    \033[40m\033[92m7. FIND VALUES IN FOURTH QUADRANT \033[0m\n");
}

void command_input()
{
    printf("Input command: ");
}

void map_command_input()
{
    printf("Input mapping command: ");
}

void where_command_input()
{
    printf("Input where command: ");
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

void null_array()
{
    system("clear");
    printf("\t\t\033[91m   YOU CAN'T DO \"WHERE\" COMPLEX ARRAY\033[0m\n");
}

void complex_positive()
{
    system("clear");
    printf("\t\t\033[91mYOU CAN'T FIND POSITIVE VALUES IN COMPLEX ARRAY\033[0m\n");
}

void complex_negative()
{
    system("clear");
    printf("\t\t\033[91mYOU CAN'T FIND NEGATIVE VALUES IN COMPLEX ARRAY\033[0m\n");
}

void complex_integers()
{
    system("clear");
    printf("\t\t\033[91m   YOU CAN'T FIND INTEGERS IN COMPLEX ARRAY\033[0m\n");
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

void mapped_array()
{
    system("clear");
    printf("\t\t\t\033[92m ARRAY SUCCESFULLY MAPPED\033[0m\n");
}

void cated_array()
{
    system("clear");
    printf("\t\t\033[92m   ARRAYS SUCCESFULLY CANCATINATED\033[0m\n");
}


void filtered_array()
{
    system("clear");
    printf("\t\t\033[92m      ARRAY SUCCESFULLY FILTERED\033[0m\n");
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