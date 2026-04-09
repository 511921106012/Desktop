#include<stdio.h>
int main()
{
    int n;
    printf("enter the size : ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int* start = arr;
    int * end = arr+n-1;
    
    while(start<end)
        int temp = *start;
        *start = *end ;
        *end = temp;
        start--;
        end++;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}