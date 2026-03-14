#include<stdio.h>
int main()
{
    int start,end;
    scanf("%d %d",&start,&end);
    



    for(int i=start;i<end;i++)
    {
       int count=0;
       for(int j=1;j<=i;j++)
       {
        if(i%j==0)

        {
            count++;
        }
       }

       if(count == 2)
       {
        printf("%d \n",i);
       }
    }
}