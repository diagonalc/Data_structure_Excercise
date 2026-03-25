#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char add[6];
    int val;
    char n_add[6];
} node;

int main()
{
    int n, k;
    char f_add[6];
    scanf("%s %d %d", f_add, &n, &k);
    node arr[n];
    for (int i = 0; i < n; i++)
        scanf(" %s %d %s", arr[i].add, &arr[i].val, arr[i].n_add);

    node s_arr[n];
    char cur[6];
    strcpy(cur, f_add);
    int i = 0;
    while (strcmp(cur, "-1") != 0)
    {

        for (int j = 0; j < n; j++)
        {
            if (strcmp(arr[j].add, cur) == 0)
            {
                s_arr[i] = arr[j];
                strcpy(cur, arr[j].n_add);

                break;
            };
        }
        i++;
    }
    i = 0;
    if (n > k)
    {
        for (; i+k < n-1; i += k)
        {
            for (int j = i + k - 1; j > i - 1; j--)
            {
                printf("%s %d %s\n", s_arr[j].add, s_arr[j].val, s_arr[j].n_add);
            }
        }
        

    }
    else{
        for (int i = 0; i < n;i++)
            printf("%s %d %s\n", s_arr[i].add, s_arr[i].val, s_arr[i].n_add);
    }

    return 0;
}