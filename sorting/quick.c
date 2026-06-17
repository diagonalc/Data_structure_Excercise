#include <stdio.h>
#include <stdlib.h>
#include "insertion.c"
#define CUTOFF 10

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort(int a[], int l, int r)
{
    if (l - r <= CUTOFF)
    {
        int pivot = a[l];
        int i = l+1;
        int j = r;
        for (;;)
        {
            while(a[++i] < pivot){
            }
            while(a[j--] > pivot){
            }
            if(i<j){
                exchange(a[i], a[j]);
            }
            else
                break;
        }
    }
    else
    {
        insertion(a, l - r);
    }
}