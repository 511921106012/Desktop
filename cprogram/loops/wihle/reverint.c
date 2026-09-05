#include<stdio.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d",&n);

    int rem =0;
    long long rev =0;

    while(n!=0)
    {
        rem = n%10;
        rev = rev *10 +rem;
        n= n /10;
    }

    if(rev > INT_MAX || rev< INT_MIN)
    {
        return 0;
    }

    printf("%lld",rev);
}