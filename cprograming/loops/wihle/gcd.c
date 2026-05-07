#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the number : ");
    scanf("%d %d",&n,&m);

    if(n<=0 || m<=0 )
    {
        printf("invalid input ");

    }
/*  */
    while(m!=0)
    {
        int temp =m;
        m= n%m;
        n = temp;
    }

    printf("the gcd %d",n);
    return 0;
}