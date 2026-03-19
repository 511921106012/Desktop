#include<stdio.h>
int main()
{
    int base,expo;
    printf("enter the base : ");
    scanf("%d",&base);

    printf("enter the expo : ");
    scanf("%d",&expo);
    int value =1;
  int i=0;
    while(i<=expo)
    {
        printf("%d ",value);
        value=value*base;
        
        i++;

    }
}