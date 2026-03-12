#include<stdio.h>
int main()
{
    int n;
    printf("enter the size");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            arr[k]=arr[i];
            k++;
        }
    }

    while(k<n)
    {
        arr[k]=0;
        k++;
    }


    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }


}