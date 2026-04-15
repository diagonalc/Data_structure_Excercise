#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int index;
    int left;
    int right;
} node;

typedef struct q_node
{
    int val;
    struct q_node *next;
} q_node;

typedef struct queue
{
    int size;
    struct q_node *head;
    struct q_node *tail;
} queue;

queue *create_queue()
{
    queue *newq = (queue *)malloc(sizeof(queue));
    newq->size = 0;
    newq->head = NULL;
    newq->tail = NULL;
    return newq;
}

q_node *create_qnode(int val)
{
    q_node *n = (q_node *)malloc(sizeof(q_node));
    n->val = val;
    n->next = NULL;
    return n;
}

void enqueue(int val, queue *q)
{
    q_node *n = create_qnode(val);
    if (q->head == NULL)
    {
        q->head = n;
        q->tail = n;
        q->size++;
        return;
    }
    q->tail->next = n;
    q->tail = n;
    q->size++;
    return;
}

int dequeue(queue *q)
{
    if (q->size == 0)
        return;
    int re = q->head->val;
    q_node *temp = q->head->next;
    free(q->head);
    q->head = temp;
    q->size--;

    if (q->size == 0)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    return re;
}

int main()
{
    int n;
    scanf("%d", &n);
    node arr[n];
    int check[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].index = i;
        char left, right;
        scanf(" %c %c", &left, &right);
        if (left != '-')
        {
            arr[i].left = left - '0';
            check[left - '0'] = 1;
        }

        else
            arr[i].left = -1;
        if (right != '-')
        {
            arr[i].right = right - '0';
            check[right - '0'] = 1;
        }
        else
            arr[i].right = -1;
    }
    int root;
    for (root = 0; root < n; root++)
        if (check[root] == 0)
            break;

    return 0;
}