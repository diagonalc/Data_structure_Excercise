#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX_V 100

typedef struct adjacent_node{
    int ver_index;
    struct adjacent_node *next;
} adjn;

typedef struct node
{
    int x;
    int y;
    adjn *next;
} node;

struct node graph[MAX_V];

void init_graph()
{
    for (int i = 0; i < MAX_V; i++)
    {
        graph[i].x = 0;
        graph[i].y = 0;
        graph[i].next = NULL;
    }
}

adjn* create_adjn(int vertex_index){
    adjn *nn = malloc(sizeof(adjn));
    nn->ver_index = vertex_index;
    nn->next = NULL;
    return nn;
}

void* insert(int v, int vi){
    adjn* nn = create_adjn(vi);
    if(graph[v].next == NULL)
        graph[v].next = nn;
    else{
        adjn *cur = graph[v].next;
        while(cur->next !=NULL)
            cur = cur->next;
        cur->next = nn;
    }

    adjn *nn2 = create_adjn(v);
    if (graph[vi].next == NULL)
        graph[vi].next = nn2;
    else
    {
        adjn *cur = graph[vi].next;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = nn2;
    }
}

bool prox(node a, node b, int d)
{
    if ((pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) < pow(d, 2))
        return true;
    return false;
}

void build_graph(int n, int d)
{
    for (int i = 0; i < n; i++)
        scanf(" %d %d", &graph[i].x, &graph[i].y);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; i < n; j++)
        {
            if (i == j)
                continue;
            if (prox(graph[i], graph[j], d)){
                insert(i, j);
            }
        }
    }
}

bool dfs(){}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    return 0;
}