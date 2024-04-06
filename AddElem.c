#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "Object.h"

void AddElem( Object *objects, size_t *length)
{
    printf("Enter text: ");
    refresh();
    scanf("%s", objects[*length].text);

    printf("Enter float number: ");
    refresh();
    scanf("%f", &objects[*length].floatNum);

    printf("Enter integer number: ");
    refresh();
    scanf("%d", &objects[*length].intNum);

    (*length)++;
}
