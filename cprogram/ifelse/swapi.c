#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the two number : ");
    scanf("%d %d",&n,&m);
    int c = n;
    n=m;
    m=c;

    printf("\n%d %d\n",n,m);
}