#include<stdio.h>
int main()
{
    int n,count=0;
    printf("enter the number : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        if(n%i ==0)
        {
            count++;
        }
    }

    if(count ==2)
    {
        printf("the number is prime number : ");
    }
    else
    {
        printf("the number is not prime : ");
    }


}