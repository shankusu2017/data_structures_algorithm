#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#define arrayLen(x) \
    sizeof(x)/sizeof(x[1])

void quick_sort(int *start, int *tail, unsigned depth);
void quick_sort20(int *arr,int begin,int end, unsigned depth);
void quick_sort21(int *a, int left, int right, unsigned depth);

#include "property.h"

#endif // QUICK_SORT_H
