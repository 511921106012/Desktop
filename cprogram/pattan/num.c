#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    int arr[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }

    }

    int first =1;
    for(int j=0;j<c;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<r;i++)
            {
            if(!first)
            {
                printf(" ");
            }
            printf("%d",arr[i][j]);
            first =0;
        }
        }
        else
        {
            for(int i=r-1;i>=0;i--)
            {
            if(!first)
            {
                printf(" ");


            }
            printf("%d",arr[i][j]); 
            first =0;
        }
        }
    }
}