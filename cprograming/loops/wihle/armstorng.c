#include<stdio.h>
int power(int rem,int digit)
{
    int result=1;
    for(int i=0;i<digit;i++)
    {
        result *= rem;
        
    }
    return result;
}
int main()
{
    int n;
    printf("enter the number : ");
    if(scanf("%d",&n)<=0)
    {
        return 0;
    }
    int temp = n;



    int sum =0;
    int rem = 1;

    int digit=0;
    while(temp>0)
    {
        digit++;
        temp=temp/10;
    }
    if(n==0)
    {
        digit =1;
    }
     temp = n;

    while(temp>0)
    {
        rem= temp%10;
        sum +=power(rem,digit);
        temp=temp/10;
    }
    

    if(sum == n)
    {
        printf("it is armstrong aother ");
    }
    else
    {
        printf("it is not armstrong");
    }
    
}