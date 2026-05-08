#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int *tmp, int l, int r, int r_end)
{
    int ini_l = l;
    int l_end = r - 1;
    int temp = l; // the location of the array in result_array
    int num = r_end - l + 1;

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

void msort_core(int a[], int *tmp, int l, int r_end)
{
    if (l < r_end)
    {
        int center = (l + r_end) / 2;
        msort_core(a, tmp, l, center);
        msort_core(a, tmp, center + 1, r_end);
        merge(a, tmp, l, center + 1, r_end);
    }
}

void msort(int a[], int n)
{
    int *tmp = malloc(n * sizeof(int)); // only need to create and free tmp array for once within the entire sorting, if tmp is created within msort_core then it will be created and freed for many times
    if (tmp != NULL)
    {
        msort_core(a, tmp, 0, n - 1);
        free(tmp);
        return;
    }
    else
    {
        printf("Malloc unsuccessful");
        return;
    }
}

int main()
{
    int arr[10] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    msort(arr, 9);
    for (int i = 0; i < 9; i++)
        printf("%d ", arr[i]);

    return 0;
}