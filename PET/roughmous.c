#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i+j>=n+1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }

        if(i!=0)
        {
            for(int j=1;j<=i-1;j++)
            {
                printf("*");
            }
        }

        printf("\n");
    }

    for(int  i =  n-1;i>=1;i--)
    {
        for(int j=0;j<=n;j++)
        
        {
            if(j+i>=n+1)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
         }

         for(int j=1;j<i;j++)
         {
            printf("*");
         }

         printf("\n");
    }


}