#include <stdio.h>
#include <stdlib.h>
#define MAX_N 15

typedef struct node
{
    char name;
    int left;
    int right;
} node;

node b_tree1[MAX_N];
node b_tree2[MAX_N];

int is_empty(int idx)
{
    return idx == -1;
}

int check(int r1, int r2)
{
    if (is_empty(r1) && is_empty(r2)) // both empty
        return 1;
    else if (is_empty(r1) || is_empty(r2)) // one is empty while the other is not
        return 0;
    else if (b_tree1[r1].name != b_tree2[r2].name)
        return 0;

    int t1_left = b_tree1[r1].left;
    int t2_left = b_tree2[r2].left;
    int t1_right = b_tree1[r1].right;
    int t2_right = b_tree2[r2].right;

    if (is_empty(t1_left) && is_empty(t2_left))
        return check(t1_right, t2_right);

    if (is_empty(t1_left) == 0 && is_empty(t2_left) == 0)
        if (b_tree1[t1_left].name == b_tree2[t2_left].name)
            return check(t1_left, t2_left) && check(t1_right, t2_right);
        else
            return check(t1_left, t2_right) && check(t1_right, t2_left);
}

int build_tree(int n, node *arr)
{
    int check[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;

    for (int i = 0; i < n; i++)
    {
        char name, left, right;
        scanf(" %c %c %c", &name, &left, &right);
        arr[i].name = name;
        if (left != '-')
        {
            arr[i].left = left - '0';
            check[arr[i].left] = 1;
        }

        else
            arr[i].left = -1;
        if (right != '-')
        {
            arr[i].right = right - '0';
            check[arr[i].right] = 1;
        }
        else
            arr[i].right = -1;
    }
    for (int i = 0; i < n; i++)
        if (!check[i])
            return i;
}

int main()
{
    int n1;
    int n2;
    scanf("%d", &n1);
    int r1 = build_tree(n1, b_tree1);
    scanf("%d", &n2);
    int r2 = build_tree(n2, b_tree2);
    if (n2 != n1)
    {
        printf("No");
        return 0;
    }
    else if (n1 == 0 && n2 == 0)
    {
        printf("Yes");
        return 0;
    }

    if (check(r1, r2))
        printf("Yes");
    else
        printf("No");
    return 0;
}