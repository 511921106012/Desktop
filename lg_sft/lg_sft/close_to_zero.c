#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int closetoZero(int arr[], int n)
{
    qsort(arr, n, sizeof(int), cmp);
    int left = 0, right = n - 1;
    int minAbs = 1e9;
    int result = 0;
    while(left < right)
    {
        int sum = arr[left] + arr[right];
        int absSum = abs(sum);
        if(absSum < minAbs)
        {
            minAbs = absSum;
            result = sum;
        }
        else if(absSum == minAbs)
        {
            if(sum > result)
            {
                result = sum;
            }
        }
        if(sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return result;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int result = closetoZero(arr, n);
    printf("%d\n",result);
    return 0;
}