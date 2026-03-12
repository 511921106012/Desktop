#include<stdio.h>
int main()
{
    int num = 29;
    int clear = num & ~(1<<num);
    printf("%d",clear);
}