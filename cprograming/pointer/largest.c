#include<stdio.h>
int main()
{
    int n;
    printf("enter the size: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int * ptr = arr;
    int mac = * ptr;


    for(int i=1;i<n;i++)
    {
        if(*(ptr + i)>mac)
        {
            mac= *(ptr+i);
        }
    }
    

    printf("%d ",mac);
}