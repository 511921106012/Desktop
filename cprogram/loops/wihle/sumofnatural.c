#include<stdio.h>
int main()
{
    int n,i=0;
    printf("enter the number : ");
    scanf("%d",&n);
int sum =0;
    while(i<=n)
    {
         sum = sum +i;
        i++;
    }
      printf("%d",sum);
}