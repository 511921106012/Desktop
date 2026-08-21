#include<stdio.h>
int  main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int k='A';

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i>j)
            {
                printf("%c ",k);
                k++;
            }
        }
        printf("\n");
    }
}