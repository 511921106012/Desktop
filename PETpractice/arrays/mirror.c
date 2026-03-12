#include<stdio.h>
int main()
{
    int n;
    printf("enter the size : ");
    scanf("%d",&n);
    int a[n],b[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    int flag=1;


    for(int i =0;i<n;i++)
    {
        if(a[i]!=b[n-1-i])
        {
            flag =0;
            break;

        }
    }

    if(flag)
    {
        printf("the mirror is \n");
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        
        }
        printf("\n")
         for(int i=0;i<n;i++)
        {
            
            printf("%d ",b[i]);
        }
    }
    else
    {
        printf("it is not mirror");
    }
}