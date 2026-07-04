#include<stdio.h>
int main()
{
    int n;
    int mask;
    int pos;

    printf("enter the position ");
    scanf("%d",&pos);

    printf("enter the mask  : ");
    scanf("%d",&mask);
    


    int num = num | (mask << pos );
    printf("the set bit is %d",num);
   return 0;
    
}