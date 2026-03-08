#include<stdio.h>
int main()
{
    int n;
    printf("enter the binary numbers : ");
    scanf("%d",&n);
    int rem=0;
    int power = 1;
    int decimal = 0;

    while(n>0)
    {
        rem = n%10;
        if(rem != 0 && rem != 1)
        {
            printf(" Invalid input number ");
            return 0;
        }
        decimal = decimal + rem * power;
        power  = power*2;

        n= n/10;



    }

    printf("%d",decimal);
}