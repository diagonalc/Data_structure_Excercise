#include <stdio.h>
#include <stdlib.h>
// kind of werid implementaion

void merge(int a[], int l, int r, int r_end)
{
    int ini_l = l;
    int l_end = r - 1;
    int temp = l; // the location of the array in result_array
    int num = r_end - l + 1;
    int tmp[99999];
    while (l <= l_end && r <= r_end)
    {
        if (a[l] < a[r])
            tmp[temp++] = a[l++];
        else
            tmp[temp++] = a[r++];
    }

    while (l <= l_end)
        tmp[temp++] = a[l++];
    while (r <= r_end)
        tmp[temp++] = a[r++];

    for (int i = ini_l; i < ini_l + num; i++)
        a[i] = tmp[i];
}

int main()
{
    int arr[10] = {6, 7, 8, 9, 1, 2, 3, 4};
    merge(arr, 0, 4, 7);
    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);

    return 0;
}