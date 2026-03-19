#include<stdio.h>
int main()
{
    int n;
    printf("enter the number  : ");
    scanf("%d",&n);
    int arr[1000]={0};

    int sum ;
    int digit;

    while(n!=1)
    {
        int sum =0;
        while(n>0)
        {
            digit=n%10;
            sum += digit*digit;
            n=n/10;

            

            
            


        }
        n=sum;
         if(arr[sum]==1)
            {
                printf("it not happy number : ");
                return 0;
            }
             arr[sum]=1;
    }
    printf("it is happy number : ");
            
}