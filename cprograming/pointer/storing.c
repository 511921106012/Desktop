#include<stdio.h>
int main()
{
    int n=10;
    int *ptr = &n;

    printf("%d\n",n);

    *ptr = 20;
    printf("%d",n);
}