#include<stdio.h>
int main()
{
    int n;
    printf("enter the array size : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array elements : ");
    for(int i=0; i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum =0;

    for(int i=0;i<n;i++)
    {
        sum += arr[i];

    }

    printf("the sum of array is %d\n",sum);
}