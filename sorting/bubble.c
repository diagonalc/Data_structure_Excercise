#include <stdio.h>
#include <stdlib.h>

void bubble(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    int arr[n];
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    //     scanf(" %d", &arr[i]);
    n = 10;
    int a[10] = {5, 3, 7, 1, 4, 9, 8, 0, 2, 6};
    bubble(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}