#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX];

void init_graph()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            graph[i][j] = INT_MAX;
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

void floyd(int dist[MAX_VERTEX][MAX_VERTEX], int path[MAX_VERTEX][MAX_VERTEX])
{
    for (int i = 0; i < MAX_VERTEX; i++)
    {
        for (int j = 0; i < MAX_VERTEX; j++)
        {
            dist[i][j] = graph[i][j];
            path[i][j] = -1; // path[i][j] stores the vertex before j within the shortest path from i to j
                             // path[i][j] = -1 means vertex i and j are either connected directly or not connected
        }
    }

    for (int k = 0; k < MAX_VERTEX;k++){    //finding the shortest path that get though k
        for (int i = 0; i < MAX_VERTEX;i++){
            for (int j = 0; j < MAX_VERTEX;j++){
                if(dist[i][k]+ dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                    /*There are two main ways to construct the path:
                    1. Store the previous directly connected node of j on the shortest path from i to j
                    path[i][j] = path[k][j];

                    2. Store one of the intermediate node on the shortest path from i to j
                    path[i][j] = k;

                     */
                }
            }
        }
    }
}

void print_mid_vertex(int path[MAX_VERTEX][MAX_VERTEX], int st, int ed){
    int k = path[st][ed];
    if(k == -1)
        return;
    printf()
}

    void print_path(int dist[MAX_VERTEX][MAX_VERTEX], int path[MAX_VERTEX][MAX_VERTEX], int st, int ed)
{
    if(dist[st][ed] == INT_MAX){
        printf("Vertices are not connected");
        return;
    }

    printf("%d -> ", st);
}