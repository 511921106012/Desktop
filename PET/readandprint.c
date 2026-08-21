#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");

    for(int i=1;i<=size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=1;i<=size;i++)
    {
        printf("%d ",arr[i]);
    }
}