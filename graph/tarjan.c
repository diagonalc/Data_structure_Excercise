// Acually tarjan is designed for directed graph, but the implementation here is for a undirected graph, the logic is similar though

#include <stdio.h>
#include <stdlib.h>
#include "tarjan.h"
#include "graph_matrix.h"

int time = 1;
int dfn[MAX_VERTEX_NUM] = {0};
int low[MAX_VERTEX_NUM] = {0};

stack *create_stack(int cap)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->arr = (int *)malloc(cap * sizeof(int));
    for (int i = 0; i < cap; i++)
        s->arr[i] = -1;
    s->size = 0;
    s->capacity = cap;
    return s;
}

void s_push(stack *s, int val)
{
    if (s->capacity == s->size)
        return;
    s->arr[s->size] = val;
    s->size++;
}

int s_pop(stack *s)
{
    if (s->size == 0)
        return -1;
    int temp = s->arr[s->size - 1];
    s->arr[s->size - 1] = -1;
    s->size--;
    return temp;
}

int find(stack *s, int target)
{
    for (int i = 0; i < s->size; i++)
        if (s->arr[i] == target)
            return 1;
    return 0;
}

void tarjan(graph *g, int v, stack *s)
{
    dfn[v] = time;
    low[v] = time;
    time++;
    s_push(s, v);
    for (int i = 0; i < g->size; i++)
    {
        if (i == v)
            continue;
        int edge_index;
        edge_index = (i < v) ? (v * (v + 1) / 2 + i) : (i * (i + 1) / 2 + v);
        if (g->arr[edge_index] != 0)
        {
            if (dfn[i] == 0)
            {
                tarjan(g, i, s);
                low[v] = (low[v] > low[i]) ? low[i] : low[v];
            }
            else if (find(s, i)) // check if its within the same strongly connected component
            {
                low[v] = (low[v] > low[i]) ? low[i] : low[v];
            }
        }
    }

    if (low[v] == dfn[v])
    {
        int cur = -1;
        while (cur != v)
        {
            cur = s_pop(s);
            printf("%d ", cur);
        }
        printf("\n");
    }
}
