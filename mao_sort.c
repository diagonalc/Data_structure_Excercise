#include <stdio.h>
#include <stdlib.h>

void mao_sort(int *arr, int size)
{
    int bank = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 1)
        {
            bank += arr[i] - 1;
            arr[i] = 1;
        }
    }
    
    for (int i = 0; i < size; i++)
        arr[i] += bank/size;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    mao_sort(arr, 5);
    print_arr(arr, 5);

    return 0;
}