#include<stdio.h>
int main()
{
    int a,b;
    printf("enter the number : ");
    scanf("%d %d",&a,&b);
    int result = a&b;
    printf(" the result is = %d\n",result);

}