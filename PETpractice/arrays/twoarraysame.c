#include<stdio.h>
int main()
{
    int size;
    printf("enter the size : ");
    scanf("%d",&size);
    int arr[size];
    int arr2[size];

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr2[i]);
    }
    int flag =1;



    for(int i=0;i<size;i++)
    {
        if(arr[i]!=arr2[i])
        {
            flag=0;
            break;


        }
    }
    if (flag)
    {
        printf("equal ");
    }
    else
    {
        printf("not equal ");
    }
}