#include<stdio.h>
int main()
{
    int num = 29;
    int n=1;
    int tag = num ^ (1<<n);
    printf("%d",tag);
}