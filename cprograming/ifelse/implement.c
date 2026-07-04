// implement calculation 
#include<stdio.h>
int main()
{
    

    char n;
    printf("enter the operation  : ");
    scanf("%c",&n);


     int a,b;
    printf("enter the number : ");
    scanf("%d %d",&a,&b);



    if(n == '+')
    {
        printf("%d\n",a+b);
    }
    else if(n=='-')
    {
        printf("%d\n",a-b);
    }
    else if(n=='*')
    {
        printf("%d\n",a*b);
    }
    else if(n == '/')
    {
        printf("%d\n",a/b);
    }

    return 0;



}