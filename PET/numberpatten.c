#include<stdio.h>
int main()
{
    int n;
    printf("enter the number  : ");
    scanf("%d",&n);

    int k=1;

    for(int i=0;i<=n;i++)
    {
        int k=1;

        for(int j=0;j<=n;j++)
        {
            if(i>j)
            {
                printf("%d ",k);
                k++;
               
                
                
            }
            

        }
        printf("\n");
        
    }
}