#include <stdio.h>
#include <stdlib.h>
#define M 101

typedef struct node
{
    int val;
    struct node *next;
} node;

int max_digit(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    int digit = 0;
    while (max)
    {
        digit++;
        max /= 10;
    }
    return digit;
}

node *create_node(int val)
{
    node *stu = malloc(sizeof(node));
    stu->val = val;
    stu->next = NULL;
    return stu;
}

node *insert(node *h, node *n)
{

    if (h == NULL)
    {
        return n;
    }
    node *cur = h;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    return h;
}

node *pop(node *h)
{
    if (h == NULL)
        return NULL;
    node *re = h->next;
    free(h);
    return re;
}

void bucket_sort(int n)
{
    node *b[M];
    for (int i = 0; i < M; i++)
        b[i] = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;

        scanf("%d", &val);
        node *ns = create_node(val);
        // b[val] = insert(b[val], ns);
    }

    for (int i = 0; i < M; i++)
    {

        while (b[i])
        {
            printf("%d\n", b[i]->val);
            b[i] = pop(b[i]);
        }
    }
}

int main()
{
    int n = 5;
    int a[5] = {0, 12, 57, 120, 2};
    printf("%d", max_digit(a, 5));
    // bucket_sort(5);
}