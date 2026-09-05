#include<stdio.h>
int main()
{
    int n,sum=;
    printf("enter the number : ");
    scanf("%d",&n);

    for(int i=1; i<=n;i++)
    {
         sum = sum +i;
    }

    printf("%d",sum);
}