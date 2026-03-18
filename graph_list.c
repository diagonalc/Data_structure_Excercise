#include <stdio.h>
#include <stdlib.h>

typedef struct graph graph;
typedef struct vnode vnode;
typedef struct adjnode adjnode;
typedef struct edge edge;

struct edge
{
    int v1;
    int v2;
    int weight;
};

struct graph
{
    int vertex_num;
    int edge_num;
    vnode *ver_list;
};

struct vnode
{
    // Datatype data;  data within the vertex
    adjnode *edge_head;
};

struct adjnode
{
    int ver_index;
    int weight;
    struct adjnode *next;
};

graph *create_graph(int verNum)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->edge_num = 0;
    g->vertex_num = verNum;
    g->ver_list = (vnode *)malloc(verNum * sizeof(vnode));
    for (int i = 0; i < verNum; i++)
        g->ver_list[i].edge_head = NULL;
    return g;
}

void insert_edge(graph *g, edge e)
{
    adjnode *nedge1 = (adjnode *)malloc(sizeof(adjnode));
    nedge1->ver_index = e.v2;
    nedge1->weight = e.weight;
    nedge1->next = g->ver_list[e.v1].edge_head;
    g->ver_list[e.v1].edge_head = nedge1;

    adjnode *nedge2 = (adjnode *)malloc(sizeof(adjnode));
    nedge2->ver_index = e.v1;
    nedge2->weight = e.weight;
    nedge2->next = g->ver_list[e.v2].edge_head;
    g->ver_list[e.v2].edge_head = nedge2;
}

graph *build_graph()
{
    int verNum;
    scanf("%d", &verNum);
    graph *g = create_graph(verNum);

    int edge_num;
    scanf("%d", &edge_num);
    for (int i = 0; i < edge_num; i++)
    {
        edge e;
        scanf("%d %d %d", &e.v1, &e.v2, &e.weight);
        insert_edge(g, e);
    }
    return g;
}
void dfs_core(graph *g, int starting_pt, int *v);

void dfs(graph *g, int starting_pt)
{
    int *visited;
    visited = (int *)malloc(g->vertex_num * sizeof(int));
    for (int i = 0; i < g->vertex_num; i++)
        visited[i] = 0;

    dfs_core(g, starting_pt, visited);
    free(visited);
}

void dfs_core(graph *g, int starting_pt, int *v)
{
    v[starting_pt] = 1;
    printf("%d ", starting_pt);
    adjnode *cur = g->ver_list[starting_pt].edge_head;
    while (cur != NULL)
    {
        if (v[cur->ver_index] == 0)
            dfs_core(g, cur->ver_index, v);
        cur = cur->next;
    }
}

int main()
{
    graph *g = build_graph();
    dfs(g, 0);
    return 0;
}
