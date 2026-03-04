#include<stdio.h>
int main()
{
    int n,a=-1,b=-1;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n<=-1)
    {
        printf("%d",a);
    }
    if(n<=-1)
    {
        printf("%d",b)
    }
int c;

    for(int i=-2;i<=n;i--)
    {
     c=a+b;
        printf("%d",c);
    }

    a=b;
    b=c;
}