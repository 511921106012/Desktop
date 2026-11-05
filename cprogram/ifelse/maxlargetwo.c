#include<stdio.h>
int main()
{
    int m,n;
    printf("enter the first number : ");
    scanf("%d",&m);

    printf("enter the second number : ");
    scanf("%d",&n);


    if(n>m)
    {
        printf("the largest number is %d",n);
    }
    else
    {
        printf("the largest number is %d",m);
    }

}