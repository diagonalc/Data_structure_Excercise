#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_VERTEX 10

/*
void Dijkstra( Vertex s )
{
    while (1){
        V = 未收录顶点中dist最小者;
        if ( 这样的V不存在 )
            break;
        collected[V] = true;
        for ( V 的每个邻接点 W ){
            if ( collected[W] == false ){
                if ( dist[V]+E<V,W> < dist[W] ) {
                    dist[W] = dist[V] + E<V,W> ;
                    path[W] = V;
                }
            }
        }
    }
}
*/

typedef struct minheap_node hnode;
typedef struct minheap heap;
struct minheap_node
{
    int dist;
    int v_index;
};
struct minheap
{
    struct minheap_node *arr;
    int size;
    int capacity;
};

int graph[MAX_VERTEX][MAX_VERTEX];
int path[MAX_VERTEX];

void init_graph()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            graph[i][j] = INFINITY;
}
void build_graph()
{
    int edge_num;
    scanf("%d", &edge_num);
    printf("Input format: (from) (to) (weight)\n");
    for (int i = 0; i < edge_num; i++)
    {
        int f, t, w;
        scanf("%d %d %d", &f, &t, &w);
        graph[f][t] = w;
    }
}

heap *init_heap(int cap)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->capacity = cap;
    h->size = 0;
    h->arr = (hnode *)malloc(cap * sizeof(hnode));
    h->arr[0].dist = -INFINITY;
    h->arr[0].v_index = 0;
    return h;
}

void h_insert(heap *h, int w, int v_index)
{
    if (h->size == h->capacity)
        return -1;

    int i = ++h->size; // starting from 1 heap
    while (i > 1 && h->arr[i / 2].dist > w)
    {
        h->arr[i].dist = h->arr[i / 2].dist;
        i /= 2;
    }
    h->arr[h->size].v_index = v_index;
    h->arr[h->size].dist = w;
}

hnode h_pop(heap *h)
{
    if (h->size == 0)
    {
        hnode empty = {0, -1};
        return empty;
    }
    hnode top = h->arr[1];
    int parent, child;
    hnode last = h->arr[h->size--]; // h->size--; already
    for (parent = 1; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if ((child != h->size) && (h->arr[child].dist > h->arr[child + 1].dist))
            child += 1;
        if (h->arr[child].dist > last.dist)
            break;
        h->arr[parent] = h->arr[child];
    }
    h->arr[parent] = last;
    return top;
}

void dijkstra(int st)
{
    heap *h = init_heap(10);
    int collected[MAX_VERTEX] = {0};

    for (int i = 0; i < MAX_VERTEX; i++)
        path[i] = -1;
    for (int i = 0; i < MAX_VERTEX; i++)
    {
        if (graph[st][i])
        {
            path[st] = st;
            h_insert(h, graph[st][i], i);
        }
    }

    while (1)
    {
        hnode v = h_pop(h);
        if (v.v_index = -1)
            break;
        collected[v.v_index] = 1;
        for (int i = 0; i < MAX_VERTEX; i++)
        {
            if (graph[v][i] && collected[i] == 0)
            {
                if ((v.dist + graph[v.v_index][i]) <)
                        }
        }
    }
}