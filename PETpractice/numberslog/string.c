#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int temp =n;
    int digit =0;


    while(n>0)
    {

        digit=n%10;
        int fact =1;

        for(int i=1;i<digit;i++)
        {
            fact = fact *i;
        }

        int sum =sum +fact;

        n=n/10;

    }


    if(sum ==temp)
    {
        printf("it is strong number :");
    }
}