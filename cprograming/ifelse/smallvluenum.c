#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the number : ");
    scanf("%d %d %d",&a,&b,&c);

    if(a<b && a<c)
    {
        printf("the smallest value is %d",a);
    }
    else if (b<a && b<c)
    {
        printf("the smallest value is %d",b);
    }
    else if(c<a && c<b)
    {
        printf("the smallest value is %d",c);
    }
    return 0;
}