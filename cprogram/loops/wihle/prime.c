#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    if(n<=1)
    {
        printf("it is not prime");
        return 0;
    }
    int prime = 1;

    int i=2;
    while(i < n)
    {
        if(n%i==0)
        {
            prime = 0;
            break;
            
        }
        i++;

    
    }
    if(prime == 1)
    {
        printf(" it is prime number %d",n);
    }
    else
    {
        printf("it not prime ");
    }
}