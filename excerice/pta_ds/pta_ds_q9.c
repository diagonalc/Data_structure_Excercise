#include <stdio.h>
#include <stdlib.h>

typedef struct b_node
{
    int val;
    struct b_node *left;
    struct b_node *right;
} node;

node *create_node(int val)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->val = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

node *insert(int val, node *root)
{
    if (root == NULL)
        return create_node(val);
    else if (val < root->val)
        root->left = insert(val, root->left);
    else if (val > root->val)
        root->right = insert(val, root->right);
    return root;
}

node *build_tree(int *arr, int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(arr[i], root);
    return root;
}

int pre_i = 0;
void preorder(node *root, int *arr)
{
    if (root == NULL)
        return;
    arr[pre_i] = root->val;
    pre_i++;
    preorder(root->left, arr);
    preorder(root->right, arr);
}

int check_arr(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return 1;
    return 0;
}

int main()
{
    int a[10];
    int b[10];
    int ap[10];
    int bp[10];
    int n, l;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        scanf(" %d", &l);
        for (int i = 0; i < n; i++)
            scanf(" %d", &a[i]);
        node *ar = build_tree(a, n);
        pre_i = 0;
        preorder(ar, ap);

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
                scanf(" %d", &b[j]);
            node *br = build_tree(b, n);
            pre_i = 0;
            preorder(br, bp);
            if (check_arr(ap, bp, n) == 0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
