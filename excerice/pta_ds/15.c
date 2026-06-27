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

void init_graph()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        for (int j = 0; j < MAX_VERTEX; j++)
            graph[i][j] = 0;
}

queue *init_queue()
{
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

qnode *create_qnode(int val)
{
    qnode *nn = malloc(sizeof(qnode));
    nn->val = val;
    nn->next = NULL;
    return nn;
}

void enqueue(int val, queue *q)
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

int dequeue(queue *q)
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

bool is_empty(queue *q)
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

int is_first = 1;
void dfs(int cur_v, int vn, int v[MAX_VERTEX])
{
    v[cur_v] = 1;
    if (is_first == 1)
    {
        printf(" %d ", cur_v);
        is_first = 0;
    }
    else
        printf("%d ", cur_v);

    // enqueue(cur_v);
    for (int i = 0; i < vn; i++)
    {
        if (i == cur_v)
            continue;
        // printf("graph[cur_v][i]=%d \ngraph[i][cur_v]=%d \n v[i]=%d\n", graph[cur_v][i], graph[i][cur_v], v[i]);
        if ((graph[cur_v][i] || graph[i][cur_v]) && v[i] == 0)
        {
            dfs(i, vn, v);
        }
    }
}

void bfs(int cur_v, int vn, int v[MAX_VERTEX])
{
    queue *q = init_queue();
    enqueue(cur_v, q);
    while (!is_empty(q))
    {
        int h = dequeue(q);
        if (v[h] == 0)
        {
            if (is_first == 1)
            {
                printf(" %d ", h);
                is_first = 0;
            }
            else
                printf("%d ", h);
        }

        v[h] = 1;
        for (int i = 0; i < vn; i++)
        {
            if (i == h)
                continue;
            if ((graph[h][i] || graph[i][h]) && v[i] == 0)
                enqueue(i, q);
        }
    }
}

int main()
{
    int ver_num, edge_num;

    scanf("%d %d", &ver_num, &edge_num);
    int visited[MAX_VERTEX] = {0};
    init_graph();
    build_graph(ver_num, edge_num);
    for (int i = 0; i < ver_num; i++)
    {
        if (visited[i] == 0)
        {
            printf("{");
            dfs(i, ver_num, visited);
            printf("}\n");
        }
        is_first = 1;
    }
    for (int i = 0; i < ver_num; i++)
        visited[i] = 0;
    is_first = 1;
    for (int i = 0; i < ver_num; i++)
    {
        if (visited[i] == 0)
        {
            printf("{");
            bfs(i, ver_num, visited);
            printf("}\n");
        }
        is_first = 1;
    }

    return 0;
}