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

void reverse_ll(head *h, int k)
{
    node *dummy = create_node(-1);
    dummy->next = h->first_node;
    node *st, *ed;
    st = ed = dummy; // while st is the end of last group
    while (1)
    {
        for (int i = 0; i < k && ed; i++)
            ed = ed->next;       // ed is the original tail of the current group, which will become the first one after inverted, which the left boundary
        node *ori_st = st->next; // original start of the current group will become the last one after inverted, which the right boundary
        node *next_gp_st = ed->next;
        ed->next = NULL;              // disconnect the current group from the rest of the list
        st->next = reverse(st->next); // connecting the left boundary
        ed->next = next_gp_st;
        st = ed;
    }
}

node *reverse(node *h)
{
    node *cur = h;
    node *pre = NULL;
    while (cur)
    {
        node *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
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