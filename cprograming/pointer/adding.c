#include<stdio.h>


int add(int *x,int *y)
{
    return *x+*y;
}
int main()
{
    int x,y;
    printf("enter the number : ");
    scanf("%d %d",&x,&y);

    

     int sum = add(&x,&y);

    printf(" the sum %d " ,sum);
}