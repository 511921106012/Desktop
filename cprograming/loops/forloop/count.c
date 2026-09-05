// count the digit in a number : 
#include<stdio.h>
int main()
{
    int count=0,n,rem;
    printf("enter the number : ");
    scanf("%d",&n);

    while(n!=0)
    {
         rem = n%10;

         count++;
         n=n/10;
    }
    printf("%d",count);
}