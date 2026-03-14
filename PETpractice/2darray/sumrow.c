// sum of row
#include<stdio.h>
int main()
{
    int r,c;
    printf("enter the row size : ");
    scanf("%d",&r);

   printf("enter the col size : ");
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
    int sum =0;
    for(int j=0;j<c;j++)
    {
        sum = sum + arr[i][j];
    }

    printf("row%d = %d\n",i+1,sum);

   }
}