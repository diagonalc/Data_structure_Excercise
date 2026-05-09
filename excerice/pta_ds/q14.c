#include <stdio.h>
#include <stdlib.h>

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

void push_h()

    int main()
{

    return 0;
}