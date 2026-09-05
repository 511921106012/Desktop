#include<stdio.h> 
int main()
{
    int  size;
    printf("enter the  size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("the element  are : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }



}