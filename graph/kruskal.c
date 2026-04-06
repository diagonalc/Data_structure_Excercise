#include <stdio.h>
#include <stdlib.h>
#define MAX_E 20
#define MAX_V 5
#define INF 65535

typedef struct Edge edge;
typedef struct Graph graph;
typedef struct Min_heap heap;

struct Edge
{
    int from;
    int to;
    int weight;
};

struct Graph
{
    int vertex_num;
    int edge_num;
    edge edges[MAX_E];
};

struct Min_heap
{
    int size;
    edge edges[MAX_E];
};

heap *create_heap(int max_size)
{
    heap *newheap = (heap *)malloc(sizeof(heap));
    newheap->size = 0;
    newheap->edges[0].weight = INF; // guard
    return newheap;
}

void push_heap(heap *h, edge e)
{
    int i = ++(h->size);
    for (; h->edges[i / 2].weight > e.weight; i /= 2)
        h->edges[i] = h->edges[i / 2];
    h->edges[i] = e;
}

edge pop_heap(heap *h)
{
    edge top = h->edges[1];
    edge last = h->edges[h->size];
    int parent, child;
    for (int parent = 1; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if (child != h->size && h->edges[child].weight > h->edges[child + 1].weight)
            child += 1;
        if (h->edges[child].weight > last.weight)
            break;
        else
            h->edges[parent] = h->edges[child];
    }
    h->edges[parent] = last;
    return top;
}

void free_heap(heap* h){
    free(h->edges);
    free(h);
}