#include <stdio.h>

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

int main()
{
    int a[10] = {5, 3, 7, 2, 1, 0, 6};
    insertion(a, 7);
    for (int i = 0; i < 7; i++)
        printf("%d ", a[i]);
}