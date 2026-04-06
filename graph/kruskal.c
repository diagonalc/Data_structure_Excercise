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
    int v1; // undirected graph
    int v2;
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

heap *create_heap()
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
    h->size--;
    return top;
}

void free_heap(heap *h)
{
    free(h->edges);
    free(h);
}

// Both methods applied path compression

// Method 1:
// int find(int v, int *parent)
// {
//     while (parent[v] != v)
//     {
//         parent[v] = parent[parent[v]];
//         v = parent[v];
//     }
//     return v;
// }

// Method 2:
int find(int v, int *parent)
{
    if (parent[v] != v)
        parent = find(parent[v], parent);
    return parent[v];
}

void merge_tree(int v1, int v2, int *parent)
{
}

void kruskal(graph *g)
{
    int parent[g->vertex_num];
    edge mst[MAX_E];
    heap *h = create_heap();
    int edge_count = 0;
    int total_weight = 0;

    for (int i = 0; i < g->edge_num; i++)
        push_heap(h, g->edges[i]);

    while ((edge_count <= g->edge_num - 1) && h->size)
    {
        edge e = pop_heap(h);
        if (find(e.v1, parent) != find(e.v2, parent))
        {
            mst[edge_count] = e;
            edge_count++;
        }
        else
        {
        }
    }
}