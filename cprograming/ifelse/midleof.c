#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the number : ");
    scanf("%d %d %d",&a,&b,&c);

    if(a>b && a<c)
    {
        printf("the mid values is %d",a);
    }
    else if(a<b && b<c)
    {
        printf("the mid number is %d",b);
    }
    else if(a<c && b>c)
    {
        printf("the mid number is %d",c);
    }

    return 0;
}