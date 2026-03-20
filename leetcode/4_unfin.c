#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    double n1m, n2m;
    int flag1 = 0, flag2 = 0;
    if (nums1Size % 2 == 0 && nums1Size !=0)
        n1m = (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
    else if (nums1Size % 2 == 1 && nums1Size != 0)
        n1m = nums1[nums1Size / 2];
    else
        flag1 = 1;

    if (nums2Size % 2 == 0 && nums2Size != 0)
        n2m = (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
    else if (nums2Size % 2 == 1 && nums2Size != 0)
        n2m = nums2[nums2Size / 2];
    else
        flag2 = 1;
    if(flag1 == flag2)
        return (n1m + n2m) / 2.0;
    else if(flag1 == 1)
        return n2m;
    else
        return n1m;
}

int main()
{
    int a1[] = {1, 3, 4, 6};
    int a2[] = {2, 4, 5};
    double result = findMedianSortedArrays(a1, 4, a2, 3);
    printf("%d", 1 % 2);
}