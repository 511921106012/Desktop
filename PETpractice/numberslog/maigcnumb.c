#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
int sum ;

    while(n>9)

{
    sum = 0;
    while(n>0)
    {
        sum = sum + (n%10);
        n= n/10;
    }
    n=sum;
    
}
if(n==1)
{
    printf("magic number ");
}
else
{
    printf("not magic number ");
}
}
