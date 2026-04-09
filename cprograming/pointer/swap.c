#include<stdio.h>
int main()
{
    int x ,y ;
    printf("enter the two number : ");
    scanf("%d %d",&x,&y);
    int *p1 = &x;
    int *p2 = &y;

    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("%d %d",*p1,*p2);
    return 0;
}