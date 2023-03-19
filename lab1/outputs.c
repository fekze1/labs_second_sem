#include "outputs.h"
#include "complex.h"
#include "source.h"
#include "dynarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void print_complex(complex number)
{
    if (number.x_point == 0 && number.y_point == 0) printf("z = 0\n");
    else if (number.x_point == 0 && number.y_point != 0) printf("z = %fi\n", number.y_point);
    else if (number.x_point != 0 && number.y_point == 0) printf("z = %f\n", number.x_point);
    else printf("z = %f + (%f)i\n", number.x_point, number.y_point);
}

void print_cmplx_arr(complex_array array)
{   
    if (array.capacity >= 100)
    {
        printf("YOU TRYING TO PRINT ARRAY WITH %d ELEMENTS\n", array.capacity);
        printf("DO YOU WANT TO WRITE IT IN FILE? (yes/no)\n");
        
        char *confirmation;

        input_str(&confirmation);
        //TODO INPUT CHECK

        while ((strcmp(confirmation, "yes") != 0) && (strcmp(confirmation, "no") != 0))
        {	
            free(confirmation);
            input_str(&confirmation);
            //TODO INPUT CHECK
        }

        if (strcmp(confirmation, "no") == 0)
        {
            free(confirmation);
            for (int i = 0; i < array.capacity; i++)
            {
                printf("[%d]: ", i + 1);  
                print_complex(array.data[i]);
            }
        }
        else
        {
            free(confirmation);
            FILE *output_file = fopen("OUTPUT.txt", "w");
            //if (!output_file) //TODO ERROR CHECK

            for (int i = 0; i < array.capacity; i++)
            {
                if (array.data[i].x_point == 0 && array.data[i].y_point == 0) fprintf(output_file, "z = 0\n");
                else if (array.data[i].x_point == 0 && array.data[i].y_point != 0) fprintf(output_file, "z = %fi\n", array.data[i].y_point);
                else if (array.data[i].x_point != 0 && array.data[i].y_point == 0) fprintf(output_file, "z = %f\n", array.data[i].x_point);
                else fprintf(output_file, "z = %f + (%f)i\n", array.data[i].x_point, array.data[i].y_point);
            }

            printf("WROTE SUCCESFULLY\n");
            fclose(output_file);
        }
    }
    else
    {
        for (int i = 0; i < array.capacity; i++)
        {
            printf("[%d]: ", i + 1);  
            print_complex(array.data[i]);
        }
    }
}

void print_flt_arr(float_array array)
{
    for (int i = 0; i < array.capacity; i++) printf("[%d]: %f\n", i + 1, array.data[i]);
}
