#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int tem=n;
    int sum =0;

    while(n>0)
    {
        int rem = n%10;

        sum +=(rem*rem*rem);
        n=n/10;
    }

    if(sum == tem)
    {
        printf("armstrong");
    }
    else
    {
        printf("not ");
    }
}