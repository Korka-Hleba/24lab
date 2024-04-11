#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

void Save(Object *objects, size_t *length, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    for (size_t i = 0; i < length; i++) {
        fprintf(file, "%s %f %d\n", objects[i].text, objects[i].floatNum, objects[i].intNum);
    }

    fclose(file);
    printf("Data successfully saved to %s\n", filename);
}
