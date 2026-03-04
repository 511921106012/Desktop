#include<stdio.h>
int main()
{
    int arr[5];
    int arr1[5];

    printf("enter the element arr : ");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr1[i]);
    }



    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(arr[i] == arr1[j])
            {
                printf("%d",arr[i]);
               break;
            }
        }
    }




}