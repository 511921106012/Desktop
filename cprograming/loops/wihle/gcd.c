#include<stdio.h>
// gcd qution

long long gcd(long long a, long long b)
{
    if(m==0)
    {
        return n;
    }
    else
    {
        return gcd(m,n%m);
    }
}
int  main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d",gcd(n,m));
    return 0;
}