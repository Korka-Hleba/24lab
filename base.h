#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include "Object.h"


void Table(Object* objects, size_t *length);

void AddElem(Object **objects, size_t *length);

void RemoveElem(Object *objects, size_t *length, size_t index);

void Save(Object *objects, size_t *length);

void Read(Object **objects, size_t *length, const char *filename);

void Sort(Object* objects, size_t length, int order, int (*compare)(const void *, const void *));

int SortText(const void *a, const void *b);

int SortInt(const void *a, const void *b);

int SortFloat(const void *a, const void *b);

void PieChart(Object* data, size_t length, int fieldIndex);

void BarChart( Object *objects, size_t length, int selectedField);


#endif // BASE_H_INCLUDED
