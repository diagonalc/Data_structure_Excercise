#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 101

typedef struct node
{
    char *name;
    struct node *next;
} node;

node *create_node(char *name)
{
    node *stu = malloc(sizeof(node));
    strcpy(stu->name, name);
    stu->next = NULL;
    return stu;
}

node *insert(node *h, node *n)
{
    if (h == NULL)
    {
        return n;
    }
    node *cur = h;
    while (cur->next)
        cur = cur->next;
    cur->next = n;
    return h;
}

node *pop(node *h)
{
    node *temp = h;
    free(h);
    return temp->next;
}

void bucket_sort(int a[], int n)
{
    node *b[M];
    for (int i = 0; i <= M; i++)
        b[i] = NULL;
    for (int i = 0; i < n; i++)
    {
        int score;
        char *name;
        scanf("%s %d", name, &score);
        node *ns = create_node(name);
        b[score] = insert(b[score], ns);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Score = %d:\n", i);
        while (b[i])
        {
            printf("%s\n", b[i]->name);
            b[i] = pop(b[i]);
        }
    }
}

int main()
{
    int a[5];
    int n = 5;
    char test[10] = "hihi";
    node *h = create_node(test);
    printf("%s", h->name);
    // bucket_sort(a, 5);
}