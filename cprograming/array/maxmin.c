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

    int  large = arr[size-1];
    int small = arr[size-1];

    for(int i=0;i<size;i++)
    {
        if(large<arr[i])
        {
            large = arr[i];
        }
        else if(small  > arr[i])
        {
            small = arr[i];

        }
    }


    printf("%d %d",large, small );


}