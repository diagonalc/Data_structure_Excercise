#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODE 30

typedef struct bnode
{
    int val;
    struct bnode *left;
    struct bnode *right;
} node;

typedef struct stack
{
    int *arr;
    int size;
    int cap;
} stack;

int pre[MAX_NODE] = {0};
int in[MAX_NODE] = {0};
int post[MAX_NODE] = {0};
int n;

stack *create_stack(int cap)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->arr = (int *)malloc(cap * sizeof(int));
    s->size = 0;
    s->cap = cap;
    return s;
}

void push_s(int val, stack *s)
{
    if (s->size == s->cap)
        return;
    s->arr[s->size++] = val;
}

int pop_s(stack *s)
{
    if (s->size == 0)
        return -1;
    int temp = s->arr[--s->size];
    return temp;
}

node *create_node(int val)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->val = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

node *bt_core(int pre_l, int pre_r, int in_l, int in_r)
{
    int rt_val = pre[pre_l];
    node *r = create_node(rt_val);
    if (pre_l > pre_r || in_l > in_r)
    {
        return NULL;
    }

    int pivot;
    for (pivot = in_l; pivot <= in_r; pivot++)
        if (in[pivot] == rt_val)
            break;

    r->left = bt_core(pre_l + 1, pre_l + pivot - in_l, in_l, pivot - 1);
    r->right = bt_core(pre_l + pivot - in_l + 1, pre_r, pivot + 1, in_r);
    return r;
}

node *build_tree()
{
    if (n <= 0)
        return NULL;

    return bt_core(0, n - 1, 0, n - 1);
}
int first = 0;
void post_order(node *cur)
{
    if (cur == NULL)
        return;
    post_order(cur->left);
    post_order(cur->right);
    if (!first)
    {
        printf("%d", cur->val);
        first = 1;
        return;
    }
    printf(" %d", cur->val);
    return;
}

void get_in_pre()
{
    scanf("%d", &n);
    int ct_pre = 0;
    int ct_in = 0;
    stack *s = create_stack(n);
    while (1)
    {
        char temp[5];
        scanf(" %s", temp);
        if (!strcmp(temp, "Push"))
        {
            int t;
            scanf(" %d", &t);
            pre[ct_pre] = t;
            ct_pre++;
            push_s(t, s);
        }
        else
        {
            in[ct_in] = pop_s(s);
            ct_in++;
        }
        if (ct_in == n)
            break;
    }
}

int main()
{
    get_in_pre();
    node *root = build_tree();
    post_order(root);

    return 0;
}