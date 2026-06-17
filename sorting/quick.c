#include <stdio.h>
#include <stdlib.h>

#define CUTOFF 1

void insertion(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i]; // the newly drawed card
        int j;           // finding a suitable location for the new card
        for (j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1]; // feels a bit similar to percolation
        // moving to the right
        a[j] = temp;
    }
}

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int a[], int l, int r)
{
    // if (l - r <= CUTOFF)
    // {
    if (l >= r)
        return;
    int pivot = a[l];
    int i = l;
    int j = r + 1; // as it condition is --j,
    for (;;)
    {
        while (i < r && a[++i] < pivot)
        {
        }
        while (j > l && a[--j] > pivot)
        {
        }

        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            break;
    }
    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, r);
    // }

    // else
    // {
    //     insertion(a, l - r);
    // }
}
int main()
{
    int a[10] = {8, 6, 4, 3, 7, 5, 2, 1};
    quick_sort(a, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", a[i]);
    }
}