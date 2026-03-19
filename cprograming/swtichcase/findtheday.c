// finding the day this which day of the year 
#include<stdio.h>
int main()
{
    int n;
    printf("enter the number in year : ");
    scanf("%d",&n);

    int y;
    printf("enter the which day you want : ");
    scanf("%d",&y);

    int x= (n+y-1)%7;

    switch(x)
    {
        case 2:
        printf("the day is monday ");
        break;

        case 3 : 
        printf("the days is tuseday  ");
        break;

        case 4:
        printf("the days is wednesday ");
        break;

        case 5:
        printf("the days is thursday ");
        break;

        case 6:
        printf("the day is friday ");
        break;

        case 1:
        printf("the day is sunday ");
        break;

        case 0: 
        printf(" the days is saturday ");


    }


}