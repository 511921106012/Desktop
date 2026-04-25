#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    if(scanf("%d",&n)<=0)
    {
        return 0 ;
    }

    if(n>=50 && n<= 100)
    {
        printf("the number is given range : ");
    }
    else
    {
        printf("it not given range");
    }
}