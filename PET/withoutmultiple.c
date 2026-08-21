#include<stdio.h>
int main()
{
    int x=0,j,n;
    scanf("%d %d",&j,&n);

    for(int i=1;i<=n;i++)
    {
        x=x+j;
         printf("%d\n",x);
    }

   // printf("%d",x);
}