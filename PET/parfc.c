#include<stdio.h>
int main()
{
    int n,s=0;
    printf("enter the number : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("invalid input");
        return 0;
    }
    int temp = n;

    for(int i=1;i<n;i++)
    {
        if(n%i== 0)
        {
            s= s+i;
        }
    }

    if(s == temp)
    {
        printf(" it is perfect number %d",s);

    }
    else
    {
        printf("it is not perfect number ");
    }


}