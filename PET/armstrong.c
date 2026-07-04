#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    printf("Enter the number->\n");
    scanf("%d",&num);
     int digits = 0;
     int temp = num,sum = 0;

    for(int i=num;i>0;i/=10)
    {
         digits++;
    }

    while(num>0)
    {
        sum =sum + pow(num%10,digits);
        num/=10;
    }

    if(temp == sum)
    printf("%d is an armstrong number\n",temp);
    else
    printf("%d is not an armstorng number\n",temp);

    return 0;
}