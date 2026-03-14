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
    int sum =0;
    int element=0;
    int avarage =0;

    for(int i=0;i<n;i++)
    {
        element++;
    }

    for(int i=0;i<n;i++)
    {
        sum +=arr[i];

         avarage = sum/element;
    }

    printf(" the avarage is %d",avarage);
}