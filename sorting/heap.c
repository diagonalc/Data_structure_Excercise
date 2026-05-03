#include <stdio.h>
#include <stdlib.h>
#define IMAX 65535

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
    nh->arr[0] = -IMAX;
    nh->size = 0;
    nh->cap = cap;
    return nh;
}

void insert(int val, heap *h)
{
    if (h->size == h->cap)
        return;
    int i = h->size + 1;
    for (; h->arr[i / 2] > val; i /= 2)
        h->arr[i] = h->arr[i / 2];
    h->arr[i] = val;
    h->size++;
}

int pop(heap *h)
{
    int re = h->arr[1];
    int last = h->arr[h->size];
    int parent, child;

    for (parent = 1; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if (child != h->size && h->arr[child] > h->arr[child + 1])
            child += 1;
        if (h->arr[child] >= last)
            break;
        h->arr[parent] = h->arr[child];
    }
    h->arr[parent] = h->arr[h->size];
    h->size--;
    return re;
}

int main()
{
    int arr[10] = {8, 6, 4, 3, 2, 9, 7, 0};
    int re[10];
    heap *h = create_heap(10);
    for (int i = 0; i < 8; i++)
        insert(arr[i], h);
    for (int i = 0; i < 8; i++)
    {
        re[i] = pop(h);
        printf("%d ", re[i]);
    }

    return 0;
}