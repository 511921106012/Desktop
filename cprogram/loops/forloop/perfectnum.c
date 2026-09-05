#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n<=1)
    {
        printf("invalid input :");
    }

    int add =0;


    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
             add =add + i;
        }
    }

    if(n==add)
    {
        printf("it is perfect number ");
    }
    else
    {
        printf("it is not perfect number :");
    }
    return 0;

    
}