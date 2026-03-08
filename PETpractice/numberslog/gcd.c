#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number ");
    scanf("%d %d",&a,&b);
    int gcd =1;

    int min = (a<b)? a:b;
    int i;

    for ( i=1; i <= min; i++)
    {
        if(a%i==0 && b%i==0)
        {
             gcd  = i;


        }   
         
}
printf("%d",gcd);
}