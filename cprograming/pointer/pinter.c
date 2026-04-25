#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);

    int *p = &x;
    printf("%d %d",x,*p);

}