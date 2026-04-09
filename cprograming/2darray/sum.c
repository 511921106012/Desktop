#include<stdio.h>
int main()
{
    int x,y;
    printf("enter the size1 : ");
    scanf("%d",&x);
    printf("enter the size2 : ");
    scanf("%d",&y);

    int arr[x][y];

    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int sum =0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            sum = sum + arr[i][j];
        }
    }

    printf("%d\n",sum);



    }