#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n<=0)
    {
        printf("invalid input : ");
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        printf("%d ",i);
    }

    return 0;
}