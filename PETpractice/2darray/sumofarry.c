// sum of 2 d array
#include<stdio.h>

int main()
{
    int arr[10][10];
    int r,c;
    scanf("%d %d",&r,&c);
    int sum =0;
    printf("enter the numberbers : ");

    for(int i=0;i<r;i++)
    {
        for(int j=0 ;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i =0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            sum = sum + arr[i][j];
        }
    }

    printf("%d",sum);
    
}