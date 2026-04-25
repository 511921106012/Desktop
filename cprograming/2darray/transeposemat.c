#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the size row : ");
    scanf("%d",&n);

    printf("enter the size of cl ");
    scanf("%d",&m);


    int arr[n][m];

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");


    for(int i=0;i<m;i++ )
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    
    }

    
}