#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

#define MAX_LENGTH 100

void Read(Object **objects, size_t *length, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    *length = 0;
    *objects = malloc(MAX_LENGTH * sizeof(Object));
    if (*objects == NULL) {
        printf("error\n");
        return;
    }

    while(fscanf(file, "%s%f%d", &(*objects)[*length].text, &(*objects)[*length].floatNum, &(*objects)[*length].intNum)==3)
     {
         *length++;
         if(*length>=MAX_LENGTH)
         {
             *objects = realloc(*objects, (*length + 1) * sizeof(Object));
             printf("Exceeded maximum number of objects.\n");
             break;
         }
     }
     fclose(file);
}
