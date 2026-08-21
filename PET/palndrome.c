#include<stdio.h>
int main()
{
    int n,rem =0,rev=0;
    printf("enter the number  :");
    scanf("%d",&n);

    int temp =n;
    while(n!=0)
    {
        rem = n%10;
        rev = rev * 10 + rem;
        n=n/10;
    }

    if(rev == temp)
    {
        printf(" the palindrome %d",rev);
    }
    else
    {
        printf(" not palindrome");
    }


}