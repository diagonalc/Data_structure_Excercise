#include <stdio.h>
#include <stdlib.h>
#define M 10

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

void bucket_sort(int a[], int n, int d, int re[])
{
    node *b[M];
    for (int i = 0; i < M; i++)
        b[i] = NULL;

    printf("temp: ");
    for (int i = 0; i < n; i++)
    {
        node *nn = create_node(a[i]);
        int temp = a[i];
        printf("%d ", a[i]);
        // obtaining the required digit (starting from 0:LSD)
        int temp_d = d;
        while (temp_d)
        {
            temp /= 10;
            temp_d--;
        }
        int det = temp % 10;
        b[det] = insert(b[det], nn);
    }

    // reading the sorted data and store them into the return array in order
    int j = 0;
    for (int i = 0; i < M; i++)
    {
        while (b[i])
        {
            re[j] = b[i]->val;
            j++;
            b[i] = pop(b[i]);
        }
    }
}

void radix(int a[], int n)
{
    int max_d = max_digit(a, n);
    int d = 0;
    int re[n];
    for (int i = 0; i < max_d; i++)
    {
        bucket_sort(a, n, d, re);
        printf("\na: ");
        for (int j = 0; j < n; j++)
        {
            a[j] = re[j];
            printf("%d ", a[j]);
            re[j] = 0;
        }
        d++;
        printf("d++ \n");
    }
    printf("Sorted Result:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int n = 5;
    int a[5] = {8, 8, 12312318, 1208, 9};
    radix(a, n);
}