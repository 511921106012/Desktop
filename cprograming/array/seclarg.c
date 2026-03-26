#include<stdio.h>
int main()
{
    int size;
    int seclar = -1;
    printf("enter the number : ");
    scanf("%d",&size);


    if(size <= 0)
    {
        printf("invalid size : ");
        return 0;
    }
    if(size ==1 )
    {
        printf("no sec largest : ");
        return 0;
    }

    int arr[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }


    int temp = arr[0];

    for(int i=0;i<size;i++)
    {
        if(arr[i] > temp)
        {
            seclar = temp;

            temp = arr[i];

            
        }
        else if(arr[i]>seclar && arr[i] != temp)
        {
            seclar = arr[i];
        }
    }

    printf("%d",seclar);


}