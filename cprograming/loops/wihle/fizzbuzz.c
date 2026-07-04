#include<stdio.h>
int main()
{
    int n =1;
    scanf("%d",&n);

  while(n<=100)
  {


    if(n%3==0 && n%5==0)
    {
        printf("fizzbuzz");
        return 0;
    }
    if(n%3 ==0)
    {
        printf("fizz");
    }
    else if(n%5==0)
    {
        printf("buzz");
        
    
    }
   

    return 0;
  }
}