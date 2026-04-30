#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 10000

int parent[MAX_NODE];
int rank[MAX_NODE] = {0};
int n;

int find(int v)
{
    if (parent[v] != v)
        parent[v] = find(parent[v]); // path compression
    return parent[v];
}

void union_sets(int v1, int v2)
{
    int r1 = find(v1);
    int r2 = find(v2);
    if (r1 == r2)
        return;
    else if (rank[r1] > rank[r2])
    {
        parent[r2] = r1;
    }
    else if (rank[r2] > rank[r1])
    {
        parent[r1] = r2;
    }
    else if (rank[r1] == rank[r2])
    {
        parent[r2] = r1;
        rank[r1]++;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    while (1)
    {
        char c;
        scanf(" %c", &c);
        switch (c)
        {
            int v1, v2;
        case 'I':

            scanf(" %d %d", &v1, &v2);
            union_sets(v1, v2);
            break;

        case 'C':

            scanf(" %d %d", &v1, &v2);
            if (find(v1) == find(v2))
                printf("yes\n");
            else
                printf("no\n");
            break;

        case 'S':
        {
            int ct = 0;
            for (int i = 0; i < n; i++)
                if (parent[i] == i)
                    ct++;
            if (ct == 1)
                printf("The network is connected.\n");
            else
                printf("There are %d components.\n", ct);
            return 0;
        }
        }
    }
    return 0;
}