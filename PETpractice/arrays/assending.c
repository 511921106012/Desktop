#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    int prev=10;
    int digit;


    while(n>0)
    {
        digit = n % 10;
        if(digit>prev)
        {
            printf("not asending ");
            return 0;
        }

        prev = digit;
        n = n/10;
    }

    printf(" digi it asending odder asending ");

}