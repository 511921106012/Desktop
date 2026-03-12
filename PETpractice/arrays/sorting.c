#include<stdio.h>
int main()
{

    int size;
    printf("enter the size : ");
    scanf("%d",&size);

    int arr[size];
    printf("enter the number ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    int c1=0,c2=0,c3=0;

   for(int i=0;i<size;i++)
   {
    if(arr[i]==0)
    {
        c1++;
    }
    else if(arr[i]==1)
    {
        c2++;
    }
    else if(arr[i]==2)
    {
        c3++;
    }
    }
    int i=0;
    while(c1--)
    arr[i++]=0;
    while(c2--)
    arr[i++]=1;
    while(c3--)
    arr[i++]=2;



    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }

   
}