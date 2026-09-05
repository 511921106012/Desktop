#include<stdio.h>
int main()
{
    int size;
    printf("enter the element : ");
    scanf("%d",&size);
    int arr[size];

    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }


    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j] <arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }


    printf("after sorting the elements are : ");
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);

    }

    
}