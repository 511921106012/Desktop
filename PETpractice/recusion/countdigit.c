#include<stdio.h>

int count(int n)
{
    if(n==0)
    {
        return 0;
    }

    return 1 +count(n);
}
int main()
{
    int n;
    scanf("%d",&n);

    printf("%d",count(n));
}