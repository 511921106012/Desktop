// set bit 
#include<stdio.h>
int main()
{
    unsigned int n ;
    int i;

    scanf("%d",&n);

    for(i =31;i>=0;i--)
    {
        printf("%d",(n>>i)&1);
    }
}