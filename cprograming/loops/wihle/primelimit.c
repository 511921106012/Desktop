#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int num =2 ;
    while(num <= n) // 
    {
        int i=2;
        int prime = 1;
        while(i*i <= num)
        {
            if(num %i==0)
            {
                prime = 0;
                break;
            }
            i++;
        }

        if(prime==1)
        {
            printf("%d",num);
        }
        num++;
        
    }


}