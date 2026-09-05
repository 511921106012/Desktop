#include<stdio.h>
int main()
{
    int n,m;
    printf("enter the size row : ");
    if(scanf("%d",&n)!=1)
    {
        return 1;
    }

    printf("enter the size of col : ");
    if(scanf("%d",&m)!=1)
    {
        return 1;
    }

    if(n<=0 ||m<=0 )
    {
        return 0;
    }

    int arr[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(scanf("%d",&arr[i][j])!=1)
            {
                return 1;
            }
        }
    }

    int sum;


    for(int i=0;i<n;i++)
    {
        sum = 0;
       // printf("%d");
      

        for(int j=0;j<m;j++)
        {
              sum = sum + arr[i][j];
               

        }

        printf(" the row is %d\n",sum);
    }


    return 0;




}