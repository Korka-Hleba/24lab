#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

void RemoveElem( Object *objects, size_t *length, size_t index) {
    if (index < 0 || index >= *length) {
        printf("wrong index\n");
        return;
    }

    for (int i = index; i < *length - 1; i++) {
        objects[i] = objects[i + 1];
    }
    (*length)--;
}
