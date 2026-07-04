#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  
  if(n<0)
  {
    return 0;

  }

  int rem=0;
  int rev=0;

  while(n!=0)
  {
    rem = n %10;
    rev = rev * 10 +rem;
    n= n/10;
  }

  printf("%d",rev);
}