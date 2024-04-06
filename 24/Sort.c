#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

void Sort(Object* objects, size_t length, int order, int (*compare)(const void *, const void *))
{

    if (order == 1)
    {
        qsort(objects, length, sizeof(Object), compare);
    }
    else if (order == 2)
    {
        qsort(objects, length, sizeof(Object), compare);
        // –азворот массива дл€ убывающей сортировки
        for (size_t i = 0; i < length / 2; i++)
        {
            Object swap = objects[i];
            objects[i] = objects[length - i - 1];
            objects[length - i - 1] = swap;
        }
    }
    else
    {
        printf("Invalid order selection\n");
    }
}
