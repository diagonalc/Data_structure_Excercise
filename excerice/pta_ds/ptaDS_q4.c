#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int add;
    int data;
    int next;
} node;

int main()
{
    int first_add, n, k;
    scanf("%d %d %d", &first_add, &n, &k);
    node arr[n];

    for (int i = 0; i < n; i++)
    {
        int ta, td, tn;
        scanf("%d %d %d", &ta, &td, &tn);
        arr[i].add = ta;
        arr[i].data = td;
        arr[i].next = tn;
    }
    int cur = first_add;
    node sorted[n];

    int s = 0;
    int ct = 0;
    while (cur != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i].add == cur)
            {
                sorted[s] = arr[i];
                s++;
                cur = arr[i].next;
                ct++;
                break;
            }
        }
    }

    int reverse_num = ct / k;

    for (int i = 0; i < reverse_num; i++)
    {
        int start = i * k;
        int end = (i + 1) * k - 1;
        while (start < end)
        {
            node temp = sorted[start];
            sorted[start] = sorted[end];
            sorted[end] = temp;
            start++;
            end--;
        }
    }
    for (int i = 0; i < ct - 1; i++)
        sorted[i].next = sorted[i + 1].add;
    sorted[ct - 1].next = -1;
    for (int i = 0; i < ct - 1; i++)
    {
        printf("%.5d %d %.5d\n", sorted[i].add, sorted[i].data, sorted[i].next);
    }
    printf("%.5d %d %d\n", sorted[ct - 1].add, sorted[ct - 1].data, sorted[ct - 1].next);
}