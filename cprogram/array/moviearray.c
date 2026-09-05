// zero to the end
#include<stdio.h>
int main()
{
    int size,pos=0;
    printf("enter the size ");
    scanf("%d",&size);
    int arr[size];

    printf("enter the element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            arr[pos]=arr[i];
            pos++;

        }

    }
    
        for(int i=pos;i<size;i++)
        {
            arr[i]=0;
        }



    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}