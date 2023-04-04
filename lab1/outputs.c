#include "outputs.h"
#include "source.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf("\n\t\t\t\033[40m\033[92m     LIST OF COMMANDS     \033[0m\n");
	printf("\t\t\t\033[40m\033[92m1. ADD ARRAY              \033[0m\n");
	printf("\t\t\t\033[40m\033[92m2. ADD ELEMENT TO ARRAY   \033[0m\n");
    printf("\t\t\t\033[40m\033[92m3. DELETE ARRAY           \033[0m\n");
	printf("\t\t\t\033[40m\033[92m4. DELETE ELEMENT IN ARRAY\033[0m\n");
	printf("\t\t\t\033[40m\033[92m5. PRINT ARRAY            \033[0m\n");
    printf("\t\t\t\033[40m\033[92m6. PRINT ALL ARRAYS       \033[0m\n");
	printf("\t\t\t\033[40m\033[92m7. CANCATINATE TWO ARRAYS \033[0m\n");
    printf("\t\t\t\033[40m\033[92m8. SORT ARRAY             \033[0m\n");
    printf("\t\t\t\033[40m\033[92m9. MAP ARRAY              \033[0m\n");
    printf("\t\t\t\033[40m\033[92m10. USE WHERE IN ARRAY    \033[0m\n");
	printf("\t\t\t\033[40m\033[92m11. EXIT                  \033[0m\n");
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

void print_error(ERROR error_thread)
{
    switch (error_thread.code)
    {
    case 1:
        system("clear");
        error_thread.error_message = "PROGRAM ENDS WITH ERROR";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 2:
        system("clear");
        error_thread.error_message = "YOU DON'T HAVE ANY ARRAYS";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 3:
        system("clear");
        error_thread.error_message = "YOU CAN'T DO \"WHERE\" COMPLEX ARRAY";
        printf("\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 4:
        system("clear");
        error_thread.error_message = "INVALID COMMAND";
        printf("\t\t\t\033[91m     %s\033[0m\n", error_thread.error_message);
    break;

    case 5:
        error_thread.error_message = "Invalid ID input, try again: ";
        printf("\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 6:
        system("clear");
        error_thread.error_message = "YOU CAN'T FIND POSITIVE VALUES IN COMPLEX ARRAY";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 7:
        system("clear");
        error_thread.error_message = "YOU CAN'T FIND NEGATIVE VALUES IN COMPLEX ARRAY";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 8:
        system("clear");
        error_thread.error_message = "YOU CAN'T FIND INTEGERS IN COMPLEX ARRAY";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 9:
        system("clear");
        error_thread.error_message = "YOU CAN'T SORT COMPLEX ARRAY";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 10:
        error_thread.error_message = "Invalid type input, try again (complex/float): ";
        printf("\033[91m%s\033[0m", error_thread.error_message);
    break;
    
    case 11:
        error_thread.error_message = "Invalid float input, try again: ";
        printf("\033[91m%s\033[0m", error_thread.error_message);
    break;

    case 12:
        system("clear");
        error_thread.error_message = "ELEMENT TYPE DOESN'T MATCH ARRAY TYPE";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;
    
    case 13:
        system("clear");
        error_thread.error_message = "ARRAYS TYPES DOESN'T MATCH";
        printf("\t\t\t\033[91m%s\033[0m\n", error_thread.error_message);
    break;

    case 14:
        error_thread.error_message = "Invalid direction input, try again (increase/decrease): ";
        printf("\033[91m%s\033[0m", error_thread.error_message);
    break;

    case 15:
        system("clear");
        error_thread.error_message = "YOU CAN'T DELETE ELEMENTS IN VOID ARRAY";
        printf("\t\t\033[91m  %s\033[0m\n", error_thread.error_message);
    break;
    case 16:
        system("clear");
        error_thread.error_message = "YOU TRYING TO INPUT STRING THAT IS TOO LONG";
        printf("\t\033[91m       %s\033[0m\n", error_thread.error_message);
    break;
    
    default:
        return;
    break;
    }
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

void input_direction()
{
    printf("Input direction (increase/decrease): ");
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

void deleted_array()
{
    system("clear");
    printf("\t\t\t\033[92m ARRAY SUCCESFULLY DELETED\033[0m\n");
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