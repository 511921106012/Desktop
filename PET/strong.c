#include <stdio.h>

int fact(int num);

int main()
{
    int num;
    printf("Enter the number->\n");
    scanf("%d",&num);
   
    int temp = num,sum = 0;

    while(num!=0)
    {
        sum = sum + fact(num%10);
        num = num/10;
    }

    if(temp == sum)
    printf("%d is a strong number\n",temp);
    else
    printf("%d is not a strong number\n",temp);

    return 0;
}

int fact(int num)
{
   int f= 1;

   for(int i=num;i>0;i--)
   {
       f = f *i;
   }

   return f;
}