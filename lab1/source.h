#ifndef SOURCE_H
#define SOURCE_H

#include "array.h"

typedef enum code
{
    NO_ERROR = 0,
    COMPLETION_ERROR,
    NULL_DATABASE,
    COMPLEX_WHERE,
    INVALID_COMMAND,
    INVALID_ID,
    INVALID_ARRAY_TYPE_POS,
    INVALID_ARRAY_TYPE_NEG,
    INVALID_ARRAY_TYPE_INT,
    INVALID_ARRAY_TYPE_SORT,
    INVALID_ELEMENT_TYPE,
    INVALID_FLOAT,
    INVALID_ELEMENT_AND_ARRAY_MATCH,
    INVALID_ARRAY_AND_ARRAY_MATCH,
    INVALID_DIRECTION,
    NULL_ARRAY_DELETE,
    BUFFER_OVERFLOW
}error_code;

typedef struct thread
{
    error_code code;
    char *error_message;
}ERROR;

static ERROR error_thread;

char *input_string();

void status();

#endif