#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    if(n<=0 || m <= 0)
    {
        printf("invalid input : ");
        return 0;
    }

    while(m!=0)
    {
        int temp = m;
        m = n%m;
        n = temp;
    }

    printf("the gcd is %d",n);
    return 0;
}