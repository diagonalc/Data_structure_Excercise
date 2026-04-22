#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 65535

typedef struct heap
{
    int *arr;
    int size;
    int cap;
} heap;

heap *create_heap(int cap)
{
    heap *nh = (heap *)malloc(sizeof(heap));
    nh->arr = (int *)malloc(cap * sizeof(int));
    nh->arr[0] = -INT_MAX;
    nh->size = 0;
    nh->cap = cap;
    return nh;
}

void insert(int val, heap *h)
{
    if (h->size == h->cap)
        return;
    int i = h->size + 1;
    for ()
}