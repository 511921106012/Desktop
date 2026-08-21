#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    if(n<0)
    {
        printf("enter the valid number   :");
    }
    int rem =0,rev=0;

    while(n!=0)

    {
        rem = n%10;
        rev = rev * 10 + rem;
        n= n/10;

    }
    printf("%d\n",rev);
}