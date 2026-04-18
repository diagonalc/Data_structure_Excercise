#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE 30

typedef struct bnode
{
    int val;
    struct bnode *left;
    struct bnode *right;
} node;

int pre[MAX_NODE] = {0};
int in[MAX_NODE] = {0};
int post[MAX_NODE] = {0};
int n;

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
    int root_val = pre[0];
    int pivot;
    for (pivot = 0; in[pivot] != root_val; pivot++)
        ;
    int in_l = 0, pre_l = 0, in_r = n, pre_r = n;
    node *r = create_node(root_val);
    r->left = bt_core(pre_l + 1, pre_l + pivot - in_l, in_l, pivot - 1);
    r->right = bt_core(pre_l + pivot - in_l + 1, pre_r, pivot + 1, in_r);
    return r;
}

int main()
{

    return 0;
}