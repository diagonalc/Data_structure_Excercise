#ifndef TARJAN
#define TARJAN

#include "graph_matrix.h"
#define MAX_VERTEX_NUM 5

extern int time;
extern int dfn[MAX_VERTEX_NUM];
extern int low[MAX_VERTEX_NUM];

typedef struct stack stack;

struct stack
{
    int *arr;
    int size;
    int capacity;
};

stack *create_stack(int cap);
int s_pop(stack *s);
void s_push(stack *s, int val);
int find(stack *s, int target);
void tarjan(graph *g, int v, stack *s);

#endif