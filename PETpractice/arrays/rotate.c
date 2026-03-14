#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int temp = arr[size-1];

    for(int i=size-1;i>0;i--)
    {
        arr[i]=arr[i-1];

    }
    arr[0]=temp;

    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }

    
} 