#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the number : ");
    scanf("%d %d %d",&a,&b,&c);

    if(a<b && b<c)
    {
        printf("the middle is   b is  %d",b);
    }
      else if( a>b && b<c)
    {
        printf("the middle a of this  number is %d",a);
    }

      else if (a<c && b>c)
    {
        printf("the middle of  c is the number is %d",c);
    }
}