#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr1[size];
    int arr2[size];

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr1[i]);
    }

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr2[i]);
    }

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr1[i]);
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr2[i]);
    }
}