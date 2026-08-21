#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the element : ");
    for(int i=1;i<=size-1;i++)
    {
        scanf("%d",&arr[i]);
    }

     printf("the even number is : ");
     for(int i=1;i<=size;i++)
     {
        if(i%2==0)
        {
            printf("%d ",i);
        }
     }

     printf("\n");

     printf("the odd number is : ");
     for(int i=1;i<=size;i++)
     {
        if(i%2==1)
        {
            printf("%d ",i);
        }
     }
}