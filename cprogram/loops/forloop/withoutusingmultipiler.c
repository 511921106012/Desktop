#include<stdio.h>

int main()
{
    int n,x,m=0,sign=1;

    printf("Enter two numbers: ");
    scanf("%d %d",&n,&x);

    if(n < 0)
    {
        n = -n;
        sign = -sign;
    }

    if(x < 0)
    {
        x = -x;
        sign = -sign;
    }

    for(int i=1;i<=x;i++)
    {
        m += n;
    }

    m = m * sign;

    printf("Result = %d\n",m);
}