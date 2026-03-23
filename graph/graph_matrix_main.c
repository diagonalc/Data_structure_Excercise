#include<stdio.h>
#include<stdlib.h>

#include "graph_matrix.h"
#include "tarjan.h"

int main()
{
    stack *s = create_stack(6);
    graph *g = create_graph(5);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 3);
    insert_edge(g, 1, 3);

    for (int i = 0; i < g->size; i++)
        if (dfn[i] == 0)
            tarjan(g, i, s);
    for (int i = 0; i < g->size; i++)
        printf("%d ", dfn[i]);
    printf("\n");
    for (int i = 0; i < g->size; i++)
        printf("%d ", low[i]);
    return 0;
}