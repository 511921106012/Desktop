#include<stdio.h>
int main()
{
    int a,b,gcd;
    printf("enter the number: ");
    scanf("%d %d",&a,&b);

    int c,d;
    c= a;
    d=b;


   while(b!=0)
   {
    gcd = b;
    b= a%b;
    a = gcd;

   }

   int hcf = a;

  // int lec = (c*d)/hcf;

   printf("%d",hcf);

}