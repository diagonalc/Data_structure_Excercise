#include <stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n;i++)
        scanf("%d", &arr[i]);
    
    int max=0, sum=0;
    for (int i = 0; i < n;i++){
        sum += arr[i];
        if(sum<=0)
            sum = 0;
        else if (sum > max)
            max = sum;
    }
    printf("%d", max);

        return 0;
}