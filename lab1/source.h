#ifndef SOURCE_H
#define SOURCE_H

#include "array.h"

typedef enum code
{
    NO_ERROR = 0,
    COMPLETION_ERROR,
    NULL_DATABASE,
    INVALID_COMMAND,
    INVALID_ID,
    INVALID_ARRAY_COMPLEX_POS,
    INVALID_ARRAY_COMPLEX_NEG,
    INVALID_ARRAY_COMPLEX_INT,
    INVALID_ARRAY_COMPLEX_SORT,
    INVALID_ARRAY_EMPTY_POS,
    INVALID_ARRAY_EMPTY_NEG,
    INVALID_ARRAY_EMPTY_QUAD,
    INVALID_ARRAY_EMPTY_INT,
    INVALID_ARRAY_EMPTY_SORT,
    INVALID_ELEMENT_TYPE,
    INVALID_FLOAT,
    INVALID_ELEMENT_AND_ARRAY_MATCH,
    INVALID_ARRAY_AND_ARRAY_MATCH,
    INVALID_DIRECTION,
    NULL_ARRAY_DELETE,
    INVALID_SET,
}error_code;

typedef struct thread
{
    error_code code;
    char *error_message;
}ERROR;

static ERROR error_thread;

char *input_string();

float str_to_float(char *string);

node_array **create_database();

node_array **add_array(node_array **database, int *count);

void delete_database(node_array **database, int count);

node_array **delete_array_in_database(node_array **database, int *count, int array_id);

void print_database(node_array **database, int count);

bool input_check(char *input);

bool string_check(char *string, node_array **database, int count);

void status();

#endif