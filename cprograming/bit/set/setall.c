#include<stdio.h>
int main()
{
    int num =1 ;

    for(int i=0;i<31;i++)
    {
        printf("%d ",num);

        num = num << 1;
    }
}