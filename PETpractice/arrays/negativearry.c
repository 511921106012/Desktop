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
    int k=0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>=0)
        {
            arr[k] = arr[i];
            k++;

        }
    }
    while(k<size)
    {
        arr[k]= -1;
        k++;
    }

    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }


}