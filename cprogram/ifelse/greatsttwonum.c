#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the number : ");
    scanf("%d %d %d",&a,&b,&c);

    if(a>b && a>c)
    {
        printf("enter the %d greater then value ",a);

    }
    else if(b>a && b>c)
    {
        printf(" the greater value is %d ",b);

    }
    else if(c>a && c>b)
    {
        printf("the gre valuse is %d",c);
    }

    return 0;

}