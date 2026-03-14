#include<stdio.h>
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }

    return (n%10) + sum(n/10);
}
int main()
{
      int n;
      printf("enter the number : ");
      scanf("%d",&n);

      int result = sum(n);
      printf("%d",result);
      return 0;
}