#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int cap;
    int *arr;

} stack;

stack *init_s(int capacity)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->arr = (int *)malloc(capacity * sizeof(int));
    s->cap = capacity;
    s->size = 0;
    return s;
}

int push(int val, stack *s)
{
    if (s->cap == s->size)
    {
        printf("Overflow!");
        return -1;
    }
    s->arr[s->size++] = val;
    return 0;
}

int pop(stack *s)
{
    if (s->size == 0)
        return -1;
    int temp = s->arr[--(s->size)];
    return temp;
}

void print_stack(stack *s)
{
    int loop_num = s->size;
    for (int i = 0; i < loop_num; i++)
        printf("%d ", pop(s));
}

int find(int target, stack *s)
{
    int size = s->size;
    for (int i = 0; i < size; i++)
    {
        if (target == s->arr[i])
            return 1;
    }
    return 0;
}

int check_if_possible(int m, int n)
{
    int arr[1000];
    int popped[10000] = {0};
    int result[1000];
    stack *s = init_s(m);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf(" %d", &temp);
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        if (find(arr[i], s))
        {
            int val = pop(s);
            popped[val] = 1;
            if (val != arr[i])
                return -1;
            continue;
        }
        for (int j = 1; j <= arr[i]; j++)
        {
            if (!find(j, s) && !popped[j])
            {
                int c = push(j, s);
                if (c == -1)
                {
                    return -1;
                }
            }
        }
        int temp = pop(s);
        popped[temp] = 1;
    }
    free(s->arr);
    free(s);
    return 0;
}

int main()
{
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k; i++)
    {
        if (check_if_possible(m, n) == -1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}