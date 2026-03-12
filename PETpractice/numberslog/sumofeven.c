#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int rem =0;
    int sum =0;

    while(n>0)
    {
        rem = n%10;
        if(rem%2==0)
        {
            sum = sum + rem;
            
        }
        n=n/10;
        

    }

    printf(" the even sum is %d",sum);
}