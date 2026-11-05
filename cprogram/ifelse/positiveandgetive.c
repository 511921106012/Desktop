// positive and neg and zer checking 
#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    if(n>0)
    {
        printf(" %d it is positive number",n);

    }
    else if(n<0)
    {
        printf(" %dit negative number ",n);
    }
    else
    {
        printf("it is zero");
    }

    return 0;

}