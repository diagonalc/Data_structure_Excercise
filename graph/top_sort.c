#include <stdio.h>
#include <stdlib.h>
#define MAX_V 10

typedef struct graph
{
    int arr[MAX_V][MAX_V];
    int ver_num;
} graph;

int in_degree[MAX_V] = {0};

typedef struct qnode
{
    int val;
    struct qnode *next;
} qnode;

typedef struct queue
{
    struct qnode *head;
    struct qnode *tail;
    int length;
} queue;

qnode *create_qnode(int val)
{
    qnode *newqnode = (qnode *)malloc(sizeof(qnode));
    newqnode->val = val;
    newqnode->next = NULL;
    return newqnode;
}

queue *create_queue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
    return q;
}

void push_q(int val, queue *q)
{
    qnode *newqn = create_qnode(val);
    if (q->length)
    {
        q->tail->next = newqn;
        q->tail = newqn;
    }
    else
    {
        q->head = newqn;
        q->tail = newqn;
    }
    q->length++;
}

int pop_q(queue *q)
{
    if (q->length == 0)
        return -1;
    int result = q->head->val;
    qnode *temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->length--;
    if (q->head == NULL)
        q->tail = NULL;
    return result;
}

graph *create_graph(int ver_num)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->ver_num = ver_num;
    return g;
}

void build_graph(graph *g)
{
    int n, vn;
    scanf("%d %d", &n, &vn);
    g = create_graph(vn);

    for (int i = 0; i < n; i++)
    {
        int from, to;
        scanf("%d %d", &to, &from);
        if (from != -1)
        {
            g->arr[from][to] = 1;
            in_degree[to]++;
        }
    }
}

int main()
{
    queue *q = create_queue();
    push_q(1, q);
    push_q(2, q);
    push_q(3, q);
    pop_q(q);
    push_q(4, q);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", pop_q(q));
    }
    return 0;
}