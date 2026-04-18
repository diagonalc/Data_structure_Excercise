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
    if (n <= 0)
        return NULL;

    return bt_core(0, n - 1, 0, n - 1);
}

void post_order(node* cur)
{
    if(cur == NULL)
        return;
    post_order(cur->left);
    post_order(cur->right);
    printf("%d ", cur->val);
    return;
}

int main()
{
    n = 6;
    int test_pre[] = {1, 2, 4, 3, 5, 6};
    int test_in[] = {4, 2, 1, 5, 3, 6};

    for (int i = 0; i < n; i++)
    {
        pre[i] = test_pre[i];
        in[i] = test_in[i];
    }

    // 2. Build the tree
    printf("Building tree...\n");
    node *root = build_tree();

    // 3. Verify with Postorder Traversal
    printf("Postorder Traversal (Expected: 4 2 5 6 3 1): \n");
    post_order(root);

    return 0;
}