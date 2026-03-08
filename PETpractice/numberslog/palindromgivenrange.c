#include<stdio.h>

int plan(int n)
{
    int temp;
    int  sum=0;
    temp =n;

    while(n>0)
    {
        sum = sum + (n%10);
        n=n/10;


    }
if(temp == sum)
{
    return 1;

}
else
{
    return 0 ;
}
    
}
int main()
{
    int high,low;
    printf("enter the number : ");
    scanf("%d %d",&high,&low);

    for(int i = high;i>=low;i--)
    {
        if(plan(i))
        {
            printf("%d",i);
            break;
        }

    }
}