#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int add;
    int val;
    int n_add;
    struct node *next;
} node;

int main()
{
    int f_add, n, k;
    scanf("%d %d %d", &f_add, &n, &k);
    node arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[n].add, &arr[n].val, &arr[n].n_add);

    node s_arr[n];
    int cur = f_add;
    while (cur != -1)
    {
        int i = 0;
        for(int j=i; j < n; j++)
        {
            if (arr[j].add == cur)
            {
                s_arr[i] = arr[j];
                cur = arr[j].n_add;
                break;
            };
        }
        i++;
    }

    for (int i = 0; i < n;i++)
        printf("%d %d %d\n", s_arr[i].add, s_arr[i].val, s_arr[i].n_add);

            return 0;
}