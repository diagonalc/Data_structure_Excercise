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

void enqueue(int val, queue *q)
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

int dequeue(queue *q)
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
    for (int i = 0; i < MAX_V; i++)
        for (int j = 0; j < MAX_V; j++)
            g->arr[i][j] = 0;
    g->ver_num = ver_num;
    return g;
}

graph *build_graph()
{
    int n, vn;
    scanf("%d %d", &n, &vn);
    graph *g = create_graph(vn);

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
    return g;
}

void topological_sort(graph *g)
{
    queue *q = create_queue();
    int ct = 0;
    for (int i = 0; i < g->ver_num; i++)
        if (in_degree[i] == 0)
            enqueue(i, q);

    while (q->length)
    {
        int v = dequeue(q);
        printf("%d ", v);
        ct++;
        for (int i = 0; i < g->ver_num; i++)
        {
            if (g->arr[v][i])
            {
                in_degree[i]--;
                if (in_degree[i] == 0)
                    enqueue(i, q);
            }
        }
    }
    if (ct != g->ver_num)
    {
        printf("Circuit exists");
        return;
    }
}

int main()
{
    graph *g = build_graph();
    topological_sort(g);
    free(g);
    return 0;
}