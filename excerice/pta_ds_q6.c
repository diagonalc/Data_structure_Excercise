#include <stdio.h>
#include <stdlib.h>
#define MAX_N 15



typedef struct node{
    char name;
    int left;
    int right;
} node;

node b_tree[MAX_N];



int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        char name, left, right;
        scanf("%c %c %c", &name, &left, &right);
        b_tree[i].name = name;
        if(left != '-')
            b_tree[i].left = left;
        else
            b_tree[i].left = -1;
        if (right != '-')
            b_tree[i].right = right;
        else
            b_tree[i].right = -1;
    }
        return 0;
}