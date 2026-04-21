#include <stdio.h>
#include <stdlib.h>

void selection(int *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int max = i;
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main()
{
    int arr[10] = {4, 1, 5, 7, 2, 9, 8, 3, 6, 0};
    int n = 10;
    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}