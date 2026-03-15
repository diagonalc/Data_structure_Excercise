#include <stdio.h>
#include <stdlib.h>

//General Set
typedef struct set_node
{
    int val;
    int parent;
} node;

int find_root(node *s, int target, int maxsize)
{
    int i = 0;
    while (i < maxsize)
    {
        if (s[i].val == target)
            break;
        i++;
    }
    if (i == maxsize)
        return -1;
    while (s[i].parent != -1)
        i = s[i].parent;
    return i;
}

void union_combine(node *s, int r1, int r2)
{
    if (r1 == r2)
        return;
    s[r2].parent = r1;
}

//Simplified Set
//using the index as the data space

int find_root_s(int *s, int target, int maxsize){
    int i = s[target];
    while(i>=0)
        i = s[i];
    return i;
}
