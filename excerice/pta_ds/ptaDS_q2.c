#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max = 0, sum = 0;
    int st, ed;
    int flag = 0;
    int cursum, curstart=0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;curstart = i+1;
            continue;
            
        }
        else if (sum > max)
        {
            max = sum;
            st = curstart;
            ed = i;
        }
        
    }
    // int temps = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     temps = arr[i];
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         temps += arr[j];
    //         if (temps == max)
    //         {
    //             st = i;
    //             ed = j;
    //             printf("%d %d %d", max, arr[st], arr[ed]);
    //             return 0;
    //         }
    //     }
    // }
    
    if (max == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                st = i;
                ed = i;
                printf("%d %d %d", max, arr[st], arr[ed]);
                return 0;
            }
        }
        max = 0;
        st = 0;
        ed = n - 1;
    }
    printf("%d %d %d", max, arr[st], arr[ed]);

    return 0;
}