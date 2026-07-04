#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n%5 ==0)
    {
        printf("the number is div %d",n);

    }
    else
    {
        printf("it is not divs ");
    }
    return 0;
}