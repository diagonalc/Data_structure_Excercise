#include<stdio.h>
#include<stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    returnSize = (int *)malloc(2 * sizeof(int));
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;
                return returnSize;
            }
        }
    }
    return returnSize;
}

int main(){
    int arr[4] = {2, 7, 11, 15};
    int *re;
    int *return1 = twoSum(arr, 4, 9, re);
    printf("%d %d", return1[0], return1[1]);
}