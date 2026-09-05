#include<stdio.h>
int main()
{
    int start,diff,end;

    printf("enter the start : ");
    scanf("%d",&start);

    printf("enter the diff : ");
    scanf("%d",&diff);

    printf("enter the end : ");
    scanf("%d",&end);

   


    while(start<=end)
    {
         float term = 1.0/start;
        printf("%.2f ",term);
        start += diff;
    }
}