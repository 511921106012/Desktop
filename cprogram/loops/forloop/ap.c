#include<stdio.h>
int main()
{
    int start,diff ,end;
    printf(" enter the start number : ");
    scanf("%d",&start);

    printf("enter the diff : ");
    scanf("%d",&diff);

    printf("upto where u want :  ");
    scanf("%d",&end);


    while(start<=end)
    {
        printf("%d ",start);
        start+=diff;
    }

    return 0;

}