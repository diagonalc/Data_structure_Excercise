#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct max_heap
{
    int *arr;
    int size;
    int cap;
} heap;

heap *init_heap(int cap);
void build_heap(heap *h, int *arr, int a_size);
void build_heap_opt(heap *h, int *arr, int a_size);
int pop(heap *h);
void percdown(heap *h, int p);
void maxheapify(heap *h, int p);
// void insert(heap *h, int val);

int findKthLargest(int *nums, int numsSize, int k)
{
    heap *h = init_heap(numsSize);
    // build_heap(h, nums, numsSize);
    build_heap_opt(h, nums, numsSize);
    for (int i = 0; i < k - 1; i++)
        pop(h);
    return pop(h);
}

heap *init_heap(int cap)
{
    heap *newheap = (heap *)malloc(sizeof(heap));
    newheap->arr = (int *)malloc((cap + 1) * sizeof(int));
    newheap->size = 0;
    newheap->cap = cap;
    newheap->arr[0] = 9999999;
    return newheap;
}

// no need
// void insert(heap *h, int val)
// {
//     if (h->size == h->cap)
//         return;
//     int i = ++h->size;
//     for (; h->arr[i / 2] < val; i /= 2)
//         h->arr[i] = h->arr[i / 2];
//     h->arr[i] = val;
// }

int pop(heap *h)
{
    if (h->size == 0)
        return -1;
    int top = h->arr[1];
    int last = h->arr[h->size--];
    h->arr[1] = last;
    percdown(h, 1);
    return top;
}

void build_heap(heap *h, int *arr, int a_size)
{
    h->size = a_size;
    for (int i = 0; i < a_size; i++)
        h->arr[i + 1] = arr[i];
    for (int i = h->size; i > 0; i--)
        percdown(h, i);
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);
}

void build_heap_opt(heap *h, int *arr, int a_size)
{
    h->size = a_size;
    for (int i = 0; i < a_size; i++)
        h->arr[i + 1] = arr[i];
    for (int i = h->size / 2; i > 0; i--)
        maxheapify(h, i);
}

void maxheapify(heap *h, int p)
{
    int l = p * 2, r = p * 2 + 1, largest = p;
    if (l <= h->size && h->arr[l] > h->arr[largest])
        largest = l;
    if (r <= h->size && h->arr[r] > h->arr[largest])
        largest = r;
    if (largest != p)
    {
        int temp = h->arr[p];
        h->arr[p] = h->arr[largest];
        h->arr[largest] = temp;
        maxheapify(h, largest);
    }
}

void percdown(heap *h, int p)
{
    int parent = p, child;
    int temp_root = h->arr[p];
    for (; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if ((child != h->size) && (h->arr[child] < h->arr[child + 1]))
            child = child + 1;
        if (h->arr[child] < temp_root)
            break;
        else
            h->arr[parent] = h->arr[child];
    }
    h->arr[parent] = temp_root;
}
int main()
{
    int a[] = {3, 2, 1, 5, 6, 4};
    int result = findKthLargest(a, 6, 2);
    printf("%d", result);
    return 0;
}