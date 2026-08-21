#include<stdio.h>
int main()
{
    int n, c,a=0,b=1;
    printf("enter the upto where u want : ");
    scanf("%d",&n);

    for(int i=1;i<n;i++)
    {
        printf("%d ",a);
        c= a+b;
        a=b;
        b=c;
    }
    
}