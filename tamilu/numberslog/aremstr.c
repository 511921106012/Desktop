#include<stdio.h>
int main()
{
    int n;
    printf("enter the number ");
    scanf("%d",&n);
    int rem =0;
    int sum =0;
    int temp = n;


    while(n>0)
    {
        rem = n % 10;

        sum = sum + (rem * rem * rem);

        n = n/10;




    }
    if(temp == sum )
    {
        printf("%d the number is armstrong : ",sum);
    }
    else
    {
        printf("not armstrong");
    }
}