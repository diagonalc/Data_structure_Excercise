#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct h_tree_node
{
    char c;
    int weight;
    struct h_tree_node *left;
    struct h_tree_node *right;
} tnode;

typedef struct min_heap
{
    tnode **arr;

    int size;
    int cap;
} heap;

heap *createheap(int cap)
{
    heap *nh = malloc(sizeof(heap));
    nh->size = 0;
    nh->cap = cap;
    nh->arr = malloc((cap + 1) * sizeof(tnode *));
    tnode *t = malloc(sizeof(tnode));
    t->c = '/';
    t->left = NULL;
    t->right = NULL;
    t->weight = -1;
    nh->arr[0] = t;
    return nh;
}

void push_h(heap *h, tnode *n)
{
    if (h->size == h->cap)
        return;
    int i = ++h->size;
    for (; h->arr[i / 2]->weight > n->weight; i /= 2)
        h->arr[i] = h->arr[i / 2];
    h->arr[i] = n;
}

tnode *pop_h(heap *h)
{
    if (h->size == 0)
        return NULL;
    tnode *top = h->arr[1];
    tnode *last = h->arr[h->size];
    h->size--;
    int parent, child;
    for (parent = 1; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if (child != h->size && h->arr[child]->weight > h->arr[child + 1]->weight)
            child++;
        if (last->weight < h->arr[child]->weight)
            break;
        h->arr[parent] = h->arr[child];
    }
    h->arr[parent] = last;

    return top;
}

tnode *huffman_tree(heap *h)
{
    int loop_num = h->size - 1;
    for (int i = 0; i < loop_num; i++)
    {
        tnode *t = malloc(sizeof(tnode));
        t->left = pop_h(h);
        t->right = pop_h(h);
        t->weight = t->left->weight + t->right->weight;
        push_h(h, t);
    }
    return pop_h(h);
}

void build_heap(heap *h, int n, int f[])
{

    for (int i = 1; i <= n; i++)
    {
        char c;
        int w;
        scanf(" %c %d", &c, &w);
        tnode *t = malloc(sizeof(tnode));
        t->c = c;
        t->weight = w;
        f[i] = w;
        t->left = t->right = NULL;
        push_h(h, t);
    }
}

int wpl(tnode *ht, int depth)
{
    if (ht->left == NULL && ht->right == NULL)
        return (depth * ht->weight);
    else
        return wpl(ht->left, depth + 1) + wpl(ht->right, depth + 1);
}

bool check(char code[][100], int f[], int wpl, int n)
{
    // 1. wpl test
    int total_l = 0;
    for (int i = 1; i <= n; i++)
    {
        // printf("%d %d\n", f[i], strlen(code[i]));
        total_l += f[i] * strlen(code[i]);
    }
    if (total_l != wpl)
        return false;

    // 2. prefix test
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                int min = (strlen(code[i]) < strlen(code[j])) ? strlen(code[i]) : strlen(code[j]);
                if (strncmp(code[i], code[j], min) == 0)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    char c[30];
    char code[30][100];
    heap *h = createheap(70);
    scanf("%d", &n);
    int f[30];
    build_heap(h, n, f);
    tnode *h_tree = huffman_tree(h);
    int w = wpl(h_tree, 0);
    scanf(" %d", &m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            
            scanf(" %c %s", &c[j], code[j]);
            // printf("read, j = %d", j);
        }
        if (check(code, f, w, n))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}