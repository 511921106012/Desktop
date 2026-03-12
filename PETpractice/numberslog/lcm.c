#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number ");
    scanf("%d %d",&a,&b);
    int gcd = 1;

    int min =0;
    if(a>b)
    {
        min = a;
    }
    else
    {
        min = b;
    }


    for(int i=1;i<=min;i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
        }
    }
    int lcm = (a*b)/gcd;
    printf(" the gcd is %d",lcm);
}