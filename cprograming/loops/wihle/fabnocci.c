#include<stdio.h>
int main()
{
    int n,a= 0,b = 1;
    printf("enter the number : ");
    scanf("%d",&n);
    if(n>=1)
    printf("%d\n",a);
    if(n>=2)
    printf("%d\n",b);
    
    for(int i=3;i<=n;i++)
    {
        int c =  a+b;
        printf("%d\n",c);

        a=b;
        b=c ;
    }
}