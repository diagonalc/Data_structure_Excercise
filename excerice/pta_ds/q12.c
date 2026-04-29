#include <stdio.h>
#include <stdlib.h>
#define MAX 65535

typedef struct heap
{
    int size;
    int *arr;
    int cap;
} heap;

heap *create_heap(int cap)
{
    heap *nh = (heap *)malloc(sizeof(heap));
    nh->size = 0;
    nh->cap = cap;
    nh->arr = (int *)malloc((cap + 1) * sizeof(int));
    nh->arr[0] = -MAX;
    return nh;
}

void insert(int val, heap *h)
{
    int i = ++h->size;
    for (; val < h->arr[i / 2]; i /= 2)
        h->arr[i] = h->arr[i / 2];
    h->arr[i] = val;
}

void print_path(int i, heap *h)
{

    while (1)
    {
        if (i != 1)
        {
            printf("%d ", h->arr[i]);
            i /= 2;
        }
        else
        {
            printf("%d", h->arr[i]);
            return;
        }
    }
}

int main()
{
    int n, m;
    heap *h = create_heap(1000);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf(" %d", &temp);
        insert(temp, h);
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        print_path(temp, h);
        printf("\n");
    }
}