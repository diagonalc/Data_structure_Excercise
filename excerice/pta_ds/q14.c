#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    nh->arr = malloc(cap * sizeof(tnode));
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
    h->size--;
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

void build_heap(heap *h, int n)
{
    for (int i = 0; i < n; i++)
    {
        char c;
        int w;
        scanf(" %c %d", &c, &w);
        tnode *t = malloc(sizeof(tnode));
        t->c = c;
        t->weight = w;
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

void check(tnode *sol, int sol_w, int n)
{
    // char code[n][n];
    // char chars[n];

    // for (int i = 0; i < n; i++)
    // {
    //     scanf(" %c", &chars[i]);
    //     scanf(" %s", code[i]);
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (code[j] == code[i])
    //         {
    //             printf("No");
    //             return;
    //         }
    //         char ci1[n];
    //         strcpy(code[i], ci1);
    //         ci1[strlen(code[i]) + 1] = 1;
    //         char ci0[n];
    //         strcpy(code[i], ci0);
    //         ci0[strlen(code[i]) + 1] = 0;
    //         if (code[j] == ci1 || code[j] == ci0)
    //         {
    //             printf("No");
    //             return;
    //         }
    //         char ci_m[n];
    //     }
    // }
    //done nothing..........
}

int main()
{
    int n, m;
    heap *h = createheap(100);
    scanf(" %d", &n);
    build_heap(h, n);
    tnode *h_tree = huffman_tree(h);
    scanf(" %d", &m);
    int w = wpl(h_tree, 0);
    printf("%d", w);
    check(h_tree, w, n);
    return 0;
}