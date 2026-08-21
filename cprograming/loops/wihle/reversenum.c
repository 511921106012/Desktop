#include<stdio.h>
int main()
{
  int  num,rem =0,rev=0 ;
  printf("enter the number :");
  scanf("%d",&num);

  int temp;
  temp =num;

  while(temp != 0)
  {
    rem = temp  % 10 ;
    rev = rev *10 + rem ;
    temp  = temp /10;


  }

  if(num == rev)
  {
    printf("%d is palindrome ",rev);
  }
  else
  {
    printf("not is palindrome");
  }

 
}