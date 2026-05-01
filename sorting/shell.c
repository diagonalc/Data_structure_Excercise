#include <stdio.h>

void shell(int *arr, int n)
{
    for (int d = n / 2; d > 0; d /= 2)
    {
        for (int p = d; p < n; p++)
        {
            int temp = arr[p];
            int i;
            for (i = p; i >= d && arr[i - d] > temp; i -= d)
                arr[i] = arr[i - d];
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[10] = {9, 6, 4, 8, 3, 5};
    shell(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}