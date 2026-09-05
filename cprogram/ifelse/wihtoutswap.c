#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number : ");
    scanf("%d %d",&a,&b);

    a= a+b;
    b= a-b;
    a= a-b;

    printf("the swap num %d %d",a,b);
}