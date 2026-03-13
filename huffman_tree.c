#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// strutures:
typedef struct Min_heap heap;
typedef struct tree_node tnode;

struct Min_heap
{
    tnode **arr;
    int size;
    int capacity;
};
struct tree_node
{
    int weight;
    struct tree_node *left;
    struct tree_node *right;
};

// functions:
heap *init_heap(int maxsize);
void insert(heap *h, tnode *n);
tnode *pop(heap *h);
void build_heap(heap *h, tnode **arr, int a_size);
tnode *create_node(int weight);
tnode *huffman_tree(heap *h);
void print_tree_pre(tnode *root);
void print_tree_mid(tnode *root);

heap *init_heap(int maxsize)
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->arr = (tnode **)malloc((maxsize + 1) * sizeof(tnode *));
    h->size = 0;
    h->capacity = maxsize;
    tnode *t = (tnode *)malloc(sizeof(tnode));
    t->weight = -1;
    h->arr[0] = t;
    return h;
}

void insert(heap *h, tnode *n)
{
    if (h->size == h->capacity)
    {
        printf("Heap is full");
        return;
    }
    int i = ++h->size;
    while (i > 1 && n->weight < h->arr[i / 2]->weight)
    {
        h->arr[i] = h->arr[i / 2];
        i /= 2;
    }
    h->arr[i] = n;
}

tnode *pop(heap *h)
{
    if (h->size == 0)
    {
        printf("Empty heap");
        return NULL;
    }
    tnode *top = h->arr[1];
    int parent, child;
    tnode *last = h->arr[h->size--];
    for (parent = 1; parent * 2 <= h->size; parent = child)
    {
        child = parent * 2;
        if ((child != h->size) && (h->arr[child]->weight > h->arr[child + 1]->weight))
            child++;
        if (last->weight < h->arr[child]->weight)
            break;
        else
            h->arr[parent] = h->arr[child];
    }
    h->arr[parent] = last;
    return top;
}

void build_heap(heap *h, tnode **arr, int a_size)
{
    for (int i = 0; i < a_size; i++)
        insert(h, arr[i]);
}

tnode *huffman_tree(heap *h)
{
    int loop_num = h->size - 1;
    for (int i = 0; i < loop_num; i++)
    {
        tnode *t = (tnode *)malloc(sizeof(tnode));
        t->left = pop(h);
        t->right = pop(h);
        t->weight = t->left->weight + t->right->weight;
        insert(h, t);
    }
    return pop(h);
}

tnode *create_node(int weight)
{
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    newnode->weight = weight;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void print_tree_pre(tnode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->weight);
    print_tree_pre(root->left);
    print_tree_pre(root->right);
}

void print_tree_mid(tnode *root)
{
    if (root == NULL)
        return;
    print_tree_mid(root->left);
    printf("%d ", root->weight);
    print_tree_mid(root->right);
}

int main()
{
    tnode *a = create_node(1);
    tnode *b = create_node(2);
    tnode *c = create_node(3);
    tnode *d = create_node(4);
    tnode *arr[] = {a, b, c, d};
    heap *h = init_heap(4);
    build_heap(h, arr, 4);
    tnode *h_tree = huffman_tree(h);
    print_tree_pre(h_tree);
    printf("\n");
    print_tree_mid(h_tree);
    return 0;
}
