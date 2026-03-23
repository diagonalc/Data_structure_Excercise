#ifndef GRAPH_MATRIX
#define GRAPH_MATRIX

typedef struct graph graph;
typedef struct queue_node qnode;
typedef struct queue queue;

struct graph
{
    int *arr;
    int size;
};

struct queue_node
{
    int index;
    struct queue_node *next;
};

struct queue
{
    struct queue_node *head;
    struct queue_node *tail;
    int size;
};

void dfs_core(graph *g, int vertex, int *v);
void q_push(queue *q, int index);
int q_pop(queue *q);
queue *init_queue(queue *q);
qnode *create_node(int index);
void bfs(graph *g, int vertex);
void dfs_core(graph *g, int vertex, int *v);
void dfs(graph *g, int vertex);
void insert_edge(graph *g, int n1, int n2);
graph *insert_vertex(int val, graph *g);
graph *create_graph(int size);

#endif