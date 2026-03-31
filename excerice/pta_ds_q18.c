#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_V 100
int g[MAX_V][MAX_V];
int dist[MAX_V][MAX_V];

int vn, en;

void buildgraph()
{
    // init
    for (int i = 1; i <= vn; i++)
    {
        for (int j = 1; j <= vn; j++)
        {
            g[i][j] = INT_MAX;
            g[j][i] = INT_MAX;
            dist[i][j] = -1;
            dist[j][i] = -1;
        }
    }
    // insert edges
    scanf("%d %d", &vn, &en);
    for (int i = 1; i <= en; i++)
    {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        g[from][to] = w;
        g[to][from] = w;
    }
}

void floyd()
{
    for (int i = 1; i <= vn; i++)
    {
        for (int j = 1; j <= vn; j++)
        {
            dist[i][j] = g[i][j];
            dist[j][i] = g[i][j];
        }
    }

    for (int i = 1; i <= vn; i++)
    {
        for (int j = 1; j <= vn; j++)
        {
            for (int k = 1; k <= vn; k++)
            {
                if ((dist[i][k] + dist[k][j]) < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void find_animal()
{
    floyd();
    int arr[vn + 1];
    for (int i = 1; i <= vn; i++)
    {
        int max = -1;
        for (int j = 1; j <= vn; j++)
        {
            if ((dist[i][j] > max) && (dist[i][j] != INT_MAX))
                max = dist[i][j];
        }
        arr[i] = max;
    }
    int min_ver = 1;

    for (int i = 1; i <= vn; i++)
    {
        if (arr[i] < arr[min_ver])
            min_ver = i;
    }
    printf("%d %d\n", min_ver, arr[min_ver]);
}

int main()
{
    buildgraph();
    find_animal();
    for (int i = 1; i <= vn; i++)
    {
        for (int)
    }
    return 0;
}