#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);
    int temp = n;
    int sum =0;
    while(n>0)
    {
        int rem = n%10;
        sum = sum + (rem*rem*rem);
        n=n/10;
        
    }
    

    if(sum == temp)
    printf("%d",sum);
    else
    {
        printf("it is not arms");
    }
}