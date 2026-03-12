#include<stdio.h>
int main()
{
    int num = 29;
    int mask=1;
   int  set = num | (1<<mask);
    printf("%d set ",set);
}