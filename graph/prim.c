#include <stdio.h>
#include <stdlib.h>
#define INF 65535
#define MAX_V 10

int graph[MAX_V][MAX_V];
int dist[MAX_V]; // distance between the node and the MST
int parent[MAX_V];

void init_graph()
{
    for (int i = 0; i < MAX_V; i++)
    {
        for (int j = 0; j < MAX_V; j++)
        {
            graph[i][j] = INF;
        }
    }
}

void insert_edge(int v1, int v2, int weight)
{
    graph[v1][v2] = graph[v2][v1] = weight;
}

void prim(int v_num)
{
    int visited[MAX_V]; // Not mandatory, dist[i] = 0; also means that the vertex is visited
    int collected_num = 0;

    for (int i = 0; i < MAX_V; i++)
    {
        dist[i] = INF; // default starting from vertex 0
        parent[i] = -1;
        visited[i] = 0;
    }
    dist[0] = 0;

    while (1)
    {
        int v = -1;
        int min_dist = INF;
        for (int i = 0; i < v_num; i++)
        {
            if (dist[i] < min_dist && visited[i] == 0)
            {
                v = i;
                min_dist = dist[i];
            }
        }

        if (v == -1)
        {
            break;
        }

        visited[v] = 1;
        collected_num++;
        for (int i = 0; i < v_num; i++)
        {
            if (visited[i] == 0 && graph[v][i] < dist[i])
            {
                dist[i] = graph[v][i];
                parent[i] = v;
            }
        }
    }

    if (collected_num != v_num)
    {
        printf("MST does not exist");
        return;
    }
    for (int i = 0; i < v_num; i++)
    {
        if (parent[i] != -1)
        {
            printf("%d -> %d: %d\n", parent[i], i, dist[i]);
        }
    }
}

int main()
{
    init_graph();
    insert_edge(0, 1, 10);
    insert_edge(0, 3, 5);
    insert_edge(1, 2, 1);
    insert_edge(1, 3, 2);
    insert_edge(2, 4, 4);
    insert_edge(3, 1, 3);
    insert_edge(3, 2, 9);
    insert_edge(3, 4, 2);
    insert_edge(4, 2, 6);
    insert_edge(4, 0, 7);
    prim(5);

    return 0;
}