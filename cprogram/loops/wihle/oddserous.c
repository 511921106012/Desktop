#include<stdio.h>
int main()
{
    int i=0,n;
    scanf("%d",&n);
    
    while(i<=n)
    {
        if(i%2==1)
        {
            printf("%d ",i);
        }

        i++;
    }
    return 0;
}