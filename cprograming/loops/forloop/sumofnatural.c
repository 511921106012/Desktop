#include<stdio.h>
int main()
{
    int n,sum =0;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n<=0)
    {
        printf("invalid input : ");
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        sum = sum +i;
    }

    printf("%d\n",sum);

    return 0;
}