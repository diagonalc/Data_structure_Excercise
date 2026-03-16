#include <stdio.h>
#include <stdlib.h>

// adjacency matrix interpretation
// G[i][j] in A: i*(i+1)/2+j

typedef struct map
{
    int *arr;
    int size;
} map;

map *create_map(int size)
{
    map *m = (map *)malloc(sizeof(map));
    m->arr = (int *)malloc((size * (size + 1) / 2) * sizeof(int));
    for (int i = 0; i < size * (size + 1) / 2; i++)
        m->arr[i] = 0;
    m->size = size;
    return m;
}

map *insert_vertex(int val, map *m)
{
    map *enlarged_map = create_map(m->size + 1);
    for (int i = 0; i < m->size * (m->size + 1) / 2; i++)
        enlarged_map->arr[i] = m->arr[i];
    free(m->arr);
    free(m);
    return enlarged_map;
}

void insert_edge(map *m, int n1, int n2)
{
    if (n1 > n2)
        m->arr[(n1 - 1) * n1 / 2 + n2] = 1;
    else if (n1 < n2)
        m->arr[n2 * (n2 + 1) / 2 + n1] = 1;
}

void dfs(map *m, int vertex)
{
    int *visited = (int *)malloc(m->size * sizeof(int));
    for (int i = 0; i < m->size; i++)
        visited[i] = 0;
    dfs_core(m, vertex, visited);
    free(visited);
}

void dfs_core(map *m, int vertex, int *v)
{
    v[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < m->size; i++)
    {
        if (i == vertex)
            continue;
        int edge_index;
        edge_index = (i < vertex) ? (vertex * (vertex + 1) / 2 + i) : (i * (i + 1) / 2 + vertex);
        if (v[i] == 0 && m->arr[edge_index] == 1)
            dfs_core(m, i, v);
    }
}
