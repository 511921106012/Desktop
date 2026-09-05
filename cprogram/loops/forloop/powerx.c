#include<stdio.h>
int main()
{
    int base,expo,result=1;
    printf("enter the base : ");
    scanf("%d",&base);

    printf("enter the expo : ");
    scanf("%d",&expo);

    for(int i=0;i<expo;i++)
    {
        result = result * base;

    }

    printf("%d",result);
}