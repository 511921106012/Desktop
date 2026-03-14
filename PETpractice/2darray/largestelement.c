#include<stdio.h>
int main()
{
    int r,c;
    printf("enter the size: ");
    scanf("%d",&r);

    printf("enter the size : ");
    scanf("%d",&c);

    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int max = arr[0][0];


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
            }
        }
    }

    printf("%d",max);

}