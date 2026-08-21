#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the first num : ");
    scanf("%d",&a);

    printf("enter the  diff num : ");
    scanf("%d",&b);

    printf("enter the last number : ");
    scanf("%d",&c);

    for(int i=1;i<=c;i++)
    {
        printf("%d\n",a);
        a = a*b;

    }
}