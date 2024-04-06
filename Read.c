#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

void Read(Object *objects, size_t *length, char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (size_t i = 0; i < length; i++) {
        fscanf(file, "%s %f %d", objects[i].text, &objects[i].floatNum, &objects[i].intNum);
    }
    fclose(file);

}
