#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node llnode;

struct linked_list_node
{
    int data;
    struct linked_list_node *next;
};

llnode *create_node(int val)
{
    llnode *newnode = (llnode *)malloc(sizeof(llnode));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insert_tail(llnode **h, int val)
{
    llnode *newnode = create_node(val);
    if (*h == NULL)
    {
        *h = newnode;
        return;
    }
    llnode *cur = *h;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = newnode;
}

void delete(llnode **h, int target)
{
    llnode **cur = h; // pointing to the entire node
    while((*cur)->data != target)
        cur = &(*cur)->next; //the address of the variable that store the address of the next node
    llnode *temp = *cur;
    *cur = (*cur)->next;
    free(temp);
}

void print_ll(llnode *h)
{
    llnode *cur = h;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main()
{
    llnode *h = NULL;
    insert_tail(&h, 4);
    insert_tail(&h, 5);
    print_ll(h);
    return 0;
}