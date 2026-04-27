#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int val;
    struct tree_node *left;
    struct tree_node *right;
    int height;
} node;

node *create_node(int val)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->val = val;
    nn->left = NULL;
    nn->right = NULL;
    nn->height = 1;
    return nn;
}
int max(int a, int b);
int height(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int balance_fac(node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

//         y
//        / \
//       x   o
//      / \ 
//     o   o

node *right_rotate(node *y)
{
    node *x = y->left;
    node *x_right = x->right;
    x->right = y;
    y->left = x_right;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

//          y
//         / \
//        o   x
//           / \ 
//          o   o

node *left_rotate(node *y)
{
    node *x = y->right;
    node *x_left = x->left;
    x->left = y;
    y->right = x_left;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

node *insert(node *r, int val)
{
    if (r == NULL)
        return create_node(val);
    if (val < r->val)
        r->left = insert(r->left, val);
    else
        r->right = insert(r->right, val);

    r->height = 1 + max(height(r->left), height(r->right));
    int bfroot = balance_fac(r);
    int bfl = balance_fac(r->left);
    int bfr = balance_fac(r->right);

    // LL
    if (bfroot == 2 && bfl == 1)
        return right_rotate(r);
    // RR
    else if (bfroot == -2 && bfr == -1)
        return left_rotate(r);
    // LR
    else if (bfroot == 2 && bfl == -1)
    {
        r->left = left_rotate(r->left);
        return right_rotate(r);
    }
    // RL
    else if (bfroot == -2 && bfr == 1)
    {
        r->right = right_rotate(r->right);
        return left_rotate(r);
    }
    return r;
}

int main()
{
    int n;
    node *r = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        r = insert(r, x);
    }
    printf("%d", r->val);

    return 0;
}