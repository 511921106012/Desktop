#include<stdio.h>
int power(int rem,int digit)
{
    int result =1;
    for(int i=0;i<digit;i++)
    {
        result =result*rem;

    }
    return result;
}
int main()
{
    int n;
    printf("enter the number :");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("invalid input : ");
    }

    int temp = n;
    int digit =0;
    while(temp != 0)
    {
        digit++;
        temp = temp /10;
    }

    temp =n;
    int rem =0;
    int sum =0;

    while(temp !=0)
    {
        rem = temp%10;

        sum = sum+power(rem,digit);
        temp = temp/10;
    }
    if(sum ==n)
    {
        printf("it is armstrong");
    }
    else
    {
        printf("it is not armstrong");
    }
    return 0;
}