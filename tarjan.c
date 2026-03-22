#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.c"
#define MAX_VERTEX_NUM 5

int time = 1;
int dfn[MAX_VERTEX_NUM] = {0};
int low[MAX_VERTEX_NUM] = {0};

typedef struct stack stack;

struct stack
{
    int *arr;
    int size;
    int capacity;
};

// functions:
stack *create_stack(int cap);
int s_pop(stack *s);
void s_push(stack *s, int val);
int find(stack *s, int target);

stack *create_stack(int cap)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->arr = (int *)malloc(cap * sizeof(int));
    for (int i = 0; i < cap; i++)
        s->arr[i] = -1;
    s->size = 0;
    s->capacity = cap;
    return s;
}

void s_push(stack *s, int val)
{
    if (s->capacity == s->size)
        return;
    s->arr[s->size] = val;
    s->size++;
}

int s_pop(stack *s)
{
    if (s->size == 0)
        return -1;
    int temp = s->arr[s->size - 1];
    s->arr[s->size - 1] = -1;
    s->size--;
    return temp;
}

int find(stack *s, int target)
{
    for (int i = 0; i < s->size; i++)
        if (s->arr[i] == target)
            return i;
    return -1;
}

int tarjan(graph *g, )
{
}

int main()
{
    stack *s = create_stack(5);

    return 0;
}