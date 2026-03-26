#include<stdio.h>
int main()
{
    char str[100];
    scanf("%s",str);

    int len =0;
    while(str[len]!='\0')
    len++;



    int left=0;
    int right =len-1;

  while(left<right)
  {
    int temp=str[left];
    str[left]=str[right];
    str[right]=temp;

    right--;
    left++;
  }

    printf("%s",str);
}