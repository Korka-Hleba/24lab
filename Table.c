#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"


void Table( Object *objects, size_t length) {
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "string", "float", "int");
    printf("--------------------------------------------------\n");
    for (size_t i = 0; i < length; i++) {
        printf("| %-20s | %-10f | %-10d |\n", (objects + i)->text, (objects + i)->floatNum, (objects + i)->intNum);
    }
    printf("--------------------------------------------------\n");

}


