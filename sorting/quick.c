#include <stdio.h>
#include <stdlib.h>

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int key = l;
    l++;
    
}