#include<stdio.h>

long long gcd(long long a, long long b)
{
    if (a==0 && b==0)
    {
        return -1;
    }
    if(a<0) a= -a;
    if(b<0)b=-b;

 while(b!=0)
 {
    long long temp = b;
    b= a%b;
    a= temp;
 }
    return a;



}
int main()
{
    long long a,b;
    scanf("%lld %lld",&a,&b);
    long long  result = gcd (a,b);
    if(result == -1)
    {
        return 0;
    }
    else
    {
        printf("%lld",result);
    }
}