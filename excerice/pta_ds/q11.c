#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tree[1000] = {0};
int arr[1000] = {0};
int num;

int get_left_size(int left, int right)
{
    int n = right - left + 1;
    int h = 0;
    for (; 1 << h <= n+1; h++)
        ;
    int x = n - (1 << h) + 1;
    x = (x < (1 << (h - 1))) ? x : 1<<h - 1;
    int l = (1 << (h - 1)) - 1 + x;
    return l;
}

void solve(int left, int right, int root)
{
    int n = right - left + 1;
    if (n == 0)
        return;
    int l = get_left_size(left, right);
    tree[root] = arr[left + l];
    int left_root = root * 2 + 1;
    int right_root = left_root + 1;
    solve(left, left + l - 1, left_root);
    solve(left + l + 1, right, right_root);
}

int main()
{

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        scanf(" %d", &arr[i]);
    solve(0, num - 1, 0);
    for (int i = 0; i < num; i++)
        printf("%d ", tree[i]);
}
