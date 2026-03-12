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

    int largest = arr[0];
    int second = -1;


    for(int i=1;i<size;i++)
    {
        if(arr[i]>largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i]>second && arr[i] != largest)
        {
            second = arr[i];
        }
    }
    printf("%d",second);
}