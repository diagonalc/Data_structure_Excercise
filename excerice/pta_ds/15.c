#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX];

typedef struct queue_node
{
    int val;
    struct queue_node *next;
} qnode;

typedef struct queue
{
    struct queue_node *head;
    struct queue_node *tail;
    int size;
} queue;
queue *q;

void init_graph()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            graph[i][j] = 0;
}

void init_queue()
{
    q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

qnode *create_qnode(int val)
{
    qnode *nn = malloc(sizeof(qnode));
    nn->val = val;
    nn->next = NULL;
    return nn;
}

void push_q(int val)
{
    qnode *nn = create_qnode(val);
    if (q->head == NULL)
    {
        q->head = q->tail = nn;
        q->size++;
        return;
    }
    q->tail->next = nn;
    q->tail = nn;
    q->size++;
}

int pop_q()
{
    if (q->head == NULL)
        return -1;
    else if (q->size == 1)
    {
        int temp = q->head->val;
        free(q->head);
        q->head = q->tail = NULL;
        q->size--;

        return temp;
    }
    qnode *temp = q->head->next;
    int re = q->head->val;
    free(q->head);
    q->head = temp;
    q->size--;
    return re;
}

bool is_empty()
{
    if (q->size == 0)
    {
        return true;
    }
    return false;
}

void build_graph(int vn, int en)
{
    for (int i = 0; i < en; i++)
    {
        int from, to;
        scanf(" %d %d", &from, &to);
        graph[from][to] = graph[to][from] = 1;
    }
}

void dfs(int cur_v, int vn, int v[MAX_VERTEX])
{
    v[cur_v] = 1;
}

int main()
{
    // int ver_num, edge_num;
    // scanf("%d %d", &ver_num, &edge_num);
    // init_graph();
    // build_graph(ver_num, edge_num);
    init_queue();
    
    return 0;
}