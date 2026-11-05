#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("it is zero ");
    }
    else if(n%2==0)
    {
        printf(" it is even number : %d ",n);
    }
    else{
        printf("it is odd number : %d ",n);
    }

}