#include <stdio.h>

int main()
{
    int number;
    printf("Enter the number->\n");
    scanf("%d",&number);
  
    int sum = 0,temp = number;
    
    for(int i=1;i<=number/2;i++)
    {
        if(number%i == 0)
        {
           sum += i;
        }
    }

    if(temp == sum)
    printf("%d is a perfect number\n",temp);
    else
    printf("%d is not a perfect number\n",temp);

    return 0;
}