#include<stdio.h>
int main()
{
    int n,num=2,flag,count=0;
    printf("enter ther number : ");
    scanf("%d",&n);

    while(count<n)
    {
        flag=1;
        for(int i=2;i<num;i++)
        {
            if(num % i==0)
            {
            flag =0;
            break;
            }
        }
         if(flag == 1)
    {
        count++;
      
        
            printf("%d",num);
        
        
    }
    num++;

    }
   
}