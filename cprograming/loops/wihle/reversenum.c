#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int rev =0;

    if(n<=0)
    {
        printf("the number is negative enter the pos");
    }

    while(n>0)
    {
        rev= rev *10 + (n%10);
        n=n/10;
    }

    printf("%d",rev);

    
}