#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the number : ");
    scanf("%d %d %d",&a,&b,&c);


    if(a*a + b*b == c*c)
    {
        printf("right angle is triangle : ");
    }
    else
    {
        printf("not if right angle is right angle ");
    }

    return 0;

}