#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
    PtrToNode h = (PtrToNode)malloc(sizeof(struct Node));

    PtrToNode c1 = L1->Next, c2 = L2->Next;
    PtrToNode cur = h;
    while (c1 != NULL && c2 != NULL)
    {
        if (c1->Data < c2->Data)
        {
            cur->Next = c1;
            c1 = c1->Next;
        }
        else
        {
            cur->Next = c2;
            c2 = c2->Next;
        }
        cur = cur->Next;
    }

    cur->Next = (c1 != NULL) ? c1 : c2;
    L1->Next = NULL;
    L2->Next = NULL;
    return h;
}