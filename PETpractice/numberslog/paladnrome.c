#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int temp = n;

    int rem=0;
   int  rev=0;

    while(n>0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n= n/10;

    }

    if(rev == temp)
    {
        printf("it is palindrome ");
    }
    else
    {
        printf(" it is not palindrome ");
    }
}