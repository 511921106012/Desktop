// print the power of n serious 
#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the power : ");
    scanf("%d",&n);

    
    printf("enter the number : ");
    scanf("%d",&m);

    int j=1;

    for(int i=0;i<=m;i++)
    {
        printf("%d ",j);
        j=j*n;
    }
}