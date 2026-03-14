#include<stdio.h>
int main()
{
    int size;
    printf("enter the number : ");
    scanf("%d",&size);

    int arr[size];

    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }


    int max=arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    printf("%d",max);
}