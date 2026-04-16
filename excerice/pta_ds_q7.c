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
        return -1;
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

void leaves(int root, node *t)
{
    int first = 0;
    queue *q = create_queue();
    enqueue(root, q);
    while (q->size)
    {
        int re = dequeue(q);
        if (t[re].left != -1)
            enqueue(t[re].left, q);
        if (t[re].right != -1)
            enqueue(t[re].right, q);
        if (t[re].left == -1 && t[re].right == -1)
        {
            if (first == 0)
            {
                printf("%d", re);
                first = 1;
            }
            else
                printf(" %d", re);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node arr[n];
    int check[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;

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

    leaves(root, arr);

    return 0;
}