#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int x = (n-m)/2;

    for(int i=1;i<=x;i++)
    {
        printf("$");
    }
    for(int j=1;j<=m;j++)
    {
        printf("*");
    }
    for(int i=1;i<=x;i++)
    {
        printf("$");
    }
}