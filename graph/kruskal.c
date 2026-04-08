#include <stdio.h>
#include <stdlib.h>
#define MAX_E 20
#define MAX_V 10
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
    edge edges[MAX_E]; // a bit similar to adjacency list, but storing the edges directly instead of the connected node
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
    newheap->edges[0].weight = -INF; // guard Min heap: -inf!
    newheap->edges[0].v1 = -1;
    newheap->edges[0].v2 = -1;
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
    h->size--; // need to be in front of the for loop!
    int parent, child;
    for (parent = 1; parent * 2 <= h->size; parent = child)
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

graph *create_graph(int v_n)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->edge_num = 0;
    g->vertex_num = v_n;
    return g;
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
        parent[v] = find(parent[v], parent);
    return parent[v];
}

void union_set(int v1, int v2, int *parent, int *rank)
{
    int root1 = find(v1, parent);
    int root2 = find(v2, parent);
    if (rank[root1] > rank[root2])
    {
        parent[root2] = root1;
    }
    else if (rank[root1] < rank[root2])
    {
        parent[root1] = root2;
    }
    else
    {
        parent[root2] = root1;
        rank[root1]++; // rank is the tree height, when heights of root1 and root2 are the same, the height of the merged tree will increase
    }
}

void kruskal(graph *g)
{
    // Union find set
    int parent[g->vertex_num];
    int rank[g->vertex_num];
    for (int i = 0; i < g->vertex_num; i++)
    {
        parent[i] = i; // cannot be -1, or else "find" func. will break
        rank[i] = 0;
    }

    edge mst[MAX_E];
    heap *h = create_heap();
    int edge_count = 0;
    int total_weight = 0;

    for (int i = 0; i < g->edge_num; i++)
        push_heap(h, g->edges[i]);

    while ((edge_count < g->vertex_num - 1) && h->size)
    {
        edge e = pop_heap(h);
        if (find(e.v1, parent) != find(e.v2, parent))
        {
            mst[edge_count] = e;
            edge_count++;
            total_weight += e.weight;
            union_set(e.v1, e.v2, parent, rank);
        }
    }

    if (edge_count != g->vertex_num - 1)
    {
        printf("MST does not exist");
        return;
    }

    for (int i = 0; i < edge_count; i++)
        printf("%d -> %d: %d\n", mst[i].v1, mst[i].v2, mst[i].weight);
    printf("Total Weight: %d", total_weight);
    free(h);
}

int main()
{

    graph *g = create_graph(5);
    g->edges[g->edge_num++] = (edge){0, 1, 2};
    g->edges[g->edge_num++] = (edge){0, 3, 6};
    g->edges[g->edge_num++] = (edge){1, 2, 3};
    g->edges[g->edge_num++] = (edge){1, 4, 1};
    g->edges[g->edge_num++] = (edge){2, 4, 4};
    g->edges[g->edge_num++] = (edge){3, 4, 4};
    kruskal(g);
    free(g);

    return 0;
}