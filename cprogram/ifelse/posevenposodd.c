#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n>0)
    {
        if(n%2==0)
        {
            printf("%d is positive even  number : ",n);
        }
        else
        {
            printf("%d is positive odd number : ",n);
        }
    }
    else
    {
        if(n%2 ==0)
        {
            printf("%d is negative even number : ",n);
        }
        else
        {
            printf(" %d negative odd number : ",n);
        }

    }

    return 0;
}