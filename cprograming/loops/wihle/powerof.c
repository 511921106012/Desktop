#include<stdio.h>
int main()
{
    int n;
    printf("enter the number ");
    scanf("%d",&n);

    int a=1;
    int i=0;
    while(i!=n)
    {
        printf("%d ",a);
        a=a*2;
        i++;
    }
}