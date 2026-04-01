#include <stdio.h>
#include <stdlib.h>

typedef struct llnode node;

typedef struct llh head;
struct llh
{
    struct llnode *first_node;
    int length;
};

struct llnode
{
    int val;
    struct llnode *next;
};

node *create_node(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

void insert_tail(head *h, int val)
{
    node *nn = create_node(val);
    if (h->first_node == NULL)
    {
        h->first_node = nn;
        h->length++;
        return;
    }
    node *cur = h->first_node;

    while (cur->next != NULL)
        cur = cur->next;
    cur->next = nn;
    h->length++;
}

void print_ll(head *h)
{
    node *cur = h->first_node;
    while (cur != NULL)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

void inverse_ll(head *h, int k)
{
    node *st, *ed, *cur, *cn, *temp;
    int ct = 0;
    node *dummy = (node *)malloc(sizeof(node));
    dummy->next = h->first_node;
    st = dummy;
    cur = h->first_node;

    int loop_num = h->length / k;
    for (int i = 0; i < loop_num; i++)
    {
        ed = cur;
        cn = cur->next;
        node *temp = NULL;
        while (ct < k)
        {
            cn->next = cur;
            cur = cn;
            cn = temp;
            temp = temp->next;
            ct++;
        }
        st->next = cur;
        ed->next = cn;
        st = ed;
        ed = ed->next;
        cur = ed;
        cn = cur->next;
        temp = cn->next;
        ct = 0;
        if (flag == 0)
        {
            flag = 1;
            h->first_node = st;
        }
    }
}

int main()
{
    head *h = (head *)malloc(sizeof(head));
    h->first_node = NULL;
    h->length = 0;
    insert_tail(h, 1);
    insert_tail(h, 2);
    insert_tail(h, 3);
    insert_tail(h, 4);
    insert_tail(h, 5);
    insert_tail(h, 6);
    insert_tail(h, 7);
    insert_tail(h, 8);
    insert_tail(h, 9);
    insert_tail(h, 10);
    inverse_ll(h, 4);
    print_ll(h);

    return 0;
}