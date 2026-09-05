#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    if(n<0)
    {
        return 0;
    }


    if(n%2 == 0)
    {
        printf("%d this number is even number : ",n);
    }
    else
    {
        printf(" this number is odd number %d",n);
        return 0;
    }
}