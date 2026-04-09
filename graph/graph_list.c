/*
Graph constructed with adjacency list
G[i] -> edge(vertex index, *next) -> edge ...
G[i+1] -> ...
.
.
.

with shortest path function
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct graph graph;
typedef struct vnode vnode;
typedef struct adjnode adjnode;
typedef struct edge edge;
typedef struct queue queue;
typedef struct queue_node qnode;

struct edge
{
    int v1;
    int v2;
    int weight;
};

struct graph
{
    int vertex_num;
    int edge_num;
    vnode *ver_list;
};

struct vnode
{
    // Datatype data;  data within the vertex
    adjnode *edge_head;
};

struct adjnode
{
    int ver_index;
    int weight;
    struct adjnode *next;
};

struct queue
{
    int size;
    struct queue_node *head;
    struct queue_node *tail;
};

struct queue_node
{
    int val;
    struct queue_node *next;
};

// functions:
graph *create_graph(int verNum);
void insert_edge(graph *g, edge e);
graph *build_graph();
void dfs_core(graph *g, int starting_pt, int *v);
void dfs(graph *g, int starting_pt);
void unweighted(graph *g, int v, int *dist, int *path);
queue *init_queue(queue *q);
void q_push(queue *q, int val);
int q_pop(queue *q);

queue *init_queue(queue *q)
{
    queue *newq = (queue *)malloc(sizeof(queue));
    newq->head = NULL;
    newq->tail = NULL;
    newq->size = 0;
    return newq;
}

void q_push(queue *q, int val)
{
    qnode *nqn = (qnode *)malloc(sizeof(qnode));
    nqn->val = val;
    nqn->next = NULL;
    if (q->head == NULL)
    {
        q->head = nqn;
        q->tail = nqn;
        q->size++;
        return;
    }

    q->tail->next = nqn;
    q->tail = nqn;
    q->size++;
    q->tail = nqn;
}

int q_pop(queue *q)
{
    int result = q->head->val;
    qnode *temp = q->head->next;
    free(q->head);
    q->head = temp;
    q->size--;
    return result;
}

graph *create_graph(int verNum)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->edge_num = 0;
    g->vertex_num = verNum;
    g->ver_list = (vnode *)malloc(verNum * sizeof(vnode));
    for (int i = 0; i < verNum; i++)
        g->ver_list[i].edge_head = NULL;
    return g;
}

void insert_edge(graph *g, edge e)
{
    adjnode *nedge1 = (adjnode *)malloc(sizeof(adjnode));
    nedge1->ver_index = e.v2;
    nedge1->weight = e.weight;
    nedge1->next = g->ver_list[e.v1].edge_head;
    g->ver_list[e.v1].edge_head = nedge1;

    adjnode *nedge2 = (adjnode *)malloc(sizeof(adjnode));
    nedge2->ver_index = e.v1;
    nedge2->weight = e.weight;
    nedge2->next = g->ver_list[e.v2].edge_head;
    g->ver_list[e.v2].edge_head = nedge2;
}

graph *build_graph()
{
    int verNum;
    scanf("%d", &verNum);
    graph *g = create_graph(verNum);

    int edge_num;
    scanf("%d", &edge_num);
    for (int i = 0; i < edge_num; i++)
    {
        edge e;
        scanf("%d %d %d", &e.v1, &e.v2, &e.weight);
        insert_edge(g, e);
    }
    return g;
}

void dfs(graph *g, int starting_pt)
{
    int *visited;
    visited = (int *)malloc(g->vertex_num * sizeof(int));
    for (int i = 0; i < g->vertex_num; i++)
        visited[i] = 0;

    dfs_core(g, starting_pt, visited);
    free(visited);
}

void dfs_core(graph *g, int starting_pt, int *v)
{
    v[starting_pt] = 1;
    printf("%d ", starting_pt);
    adjnode *cur = g->ver_list[starting_pt].edge_head;
    while (cur != NULL)
    {
        if (v[cur->ver_index] == 0)
            dfs_core(g, cur->ver_index, v);
        cur = cur->next;
    }
}

void unweighted(graph *g, int v, int *dist, int *path)
{
    for (int i = 0; i < g->vertex_num; i++)
    {
        dist[i] = -1;
        path[i] = -1;
    }
    dist[v] = 0;
    queue *q = init_queue(q);
    q_push(q, v);
    while (q->size != 0)
    {
        int x = q_pop(q);
        adjnode *cur = g->ver_list[x].edge_head;
        while (cur != NULL)
        {
            int w = cur->ver_index;
            int temp_dist = dist[x] + 1;
            if (temp_dist < dist[w] || dist[w] == -1)
            {
                dist[w] = temp_dist;
                path[w] = x;
                q_push(q, w);
            }
            cur = cur->next;
        }
    }
}

void shortest_path(graph *g, int st, int ed, int *dist, int *path)
{
    unweighted(g, st, dist, path);
    if (path[ed] == -1)
    {
        printf("No path exists bewteen vertex %d and %d\n", st, ed);
        return;
    }
    int length = dist[ed];
    int cur = ed;
    printf("%d ", st);
    int *p = (int *)malloc(length * sizeof(int));
    int i = 0;
    while (cur != st)
    {
        p[i] = cur;
        cur = path[cur];
        i++;
    }
    for (int i = length - 1; i >= 0; i--)
        printf("%d ", p[i]);
    free(p);
}

int main()
{
    graph *g = build_graph();
    int *dist = (int *)malloc(g->vertex_num * sizeof(int));
    int *path = (int *)malloc(g->vertex_num * sizeof(int));
    shortest_path(g, 0, 4, dist, path);

    // dfs(g, 0);
    return 0;
}
