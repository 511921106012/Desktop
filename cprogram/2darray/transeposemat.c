#include<stdio.h>
void transs(int r,int c ,int arr[r][c],int trans[c][r])
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
}
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);

    int arr[r][c];
    int trans[c][r];
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    transs(r,c,arr,trans);
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d",trans[i][j]);
        
        if(j <r-1)
        {
            printf(" ");
        }
        }

        printf("\n");
    }

    return 0;

    
}