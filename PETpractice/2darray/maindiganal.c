#include<stdio.h>
int main()
{
    int r,c;
    printf("enter the row : ");
    scanf("%d",&r);


    printf("enter the col : ");
    scanf("%d",&c);


    int arr[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(j>i)
            {
                printf("%d 
                    ",arr[i][j]);
            }
        }
    }

}