#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX];

void init_graph()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            graph[i][j] = 0;
}

void build_graph(int vn, int en)
{
    for (int i = 0; i < en;i++){
        int from, to;
        scanf(" %d %d", &from, &to);
        graph[from][to] = graph[to][from] = 1;
    }
}

void dfs(int cur_v, int vn, int v[MAX_VERTEX]){
    v[cur_v] = 1;
    
}

int main(){
    int ver_num, edge_num;
    scanf("%d %d", &ver_num, &edge_num);
    init_graph();
    build_graph(ver_num, edge_num);

    return 0;
}