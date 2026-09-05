#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int left =0;
    int right = size-1;

    while(left<right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right]= temp;
        left ++;
        right--;
    }

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}