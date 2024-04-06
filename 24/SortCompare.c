#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Object.h"

int SortText(const void *a, const void *b) {
    return strcmp(((Object *)a)->text, ((Object *)b)->text);
}

int SortFloat(const void *a, const void *b) {
    return (int)(((Object *)a)->floatNum - ((Object *)b)->floatNum);
}

int SortInt(const void *a, const void *b) {
    return ((Object *)a)->intNum - ((Object *)b)->intNum;
}
