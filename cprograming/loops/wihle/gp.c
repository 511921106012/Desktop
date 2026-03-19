#include<stdio.h>
int main()
{
    int start,ratio,end;
    printf("enter the start num : ");
    scanf("%d",&start);

    printf("enter the diff num : ");
    scanf("%d",&ratio);

    printf("enter the end : ");
    scanf("%d",&end);


    while(start<=end)
    {

        printf("%d ",start);
        start *= ratio;
    }
    return 0;
}