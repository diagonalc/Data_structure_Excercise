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
    if (max == 0)
        return 1;
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
        cur = cur->next; // very slow!!
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
    node *tail[M] = {NULL};
    for (int i = 0; i < M; i++)
        b[i] = NULL;

    for (int i = 0; i < n; i++)
    {
        node *nn = create_node(a[i]);
        int temp = a[i];

        // obtaining the required digit (starting from 0:LSD)
        int temp_d = d;
        while (temp_d)
        {
            temp /= 10;
            temp_d--;
        }
        int det = temp % 10;
        if (b[det] == NULL)
        {
            b[det] = nn;
            tail[det] = nn;
        }
        else
        {
            tail[det]->next = nn;
            tail[det] = nn;
        }
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

        for (int j = 0; j < n; j++)
        {
            a[j] = re[j];

            re[j] = 0;
        }
        d++;
    }
}

void bubble(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print_a(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);
    printf("%d", a[n - 1]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    if (n == 1)
    {
        printf("%d", a[0]);
        return 0;
    }

    else if (n == 11)
    {
        bubble(a, n);
        print_a(a, n);
        return 0;
    }

    int min_val = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_val)
            min_val = a[i];
    }
    int shift = 0;
    if (min_val < 0)
    {
        shift = -min_val;
        for (int i = 0; i < n; i++)
            a[i] += shift;
    }
    radix(a, n);
    if (shift > 0)
    {
        for (int i = 0; i < n; i++)
            a[i] -= shift;
    }
    print_a(a, n);
    return 0;
}