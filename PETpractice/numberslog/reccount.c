#include<stdio.h>
int count (int n)
{
    if (n==0)
       return 0;

    return 1 + count(n/10);
}
int main()
{
    int n;
    scanf("%d",&n);

    if(n<0)
    {
        n= -n;
    }
else if(n==0)
{
    printf(digit = 1);
}
else
{
    printf("%d digit ",count(n));
}
}