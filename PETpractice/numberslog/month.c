#include<stdio.h>
int main()
{
    int month;
    printf("enter the month number  : ");
    scanf("%d",&month);


    if(month == 2)
    {
        printf("feb has 28 and 29 month is there");
    }
    else if(month == 4 || month == 6 || month == 9 ||month == 11)
    {
        printf("month has 30 days is there ");
    }
    else if(month >= 1 && month <=12)
    {
        printf("month has 31 days is there :");
    }
}