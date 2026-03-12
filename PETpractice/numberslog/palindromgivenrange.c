// largest number of given range palndrome ;
#include<stdio.h>
int pali(int n)
{
    int temp =n;
    int rem=0;
    int rev =0;

    while(n>0)
    {
        rev=rev*10+(n%10);
        n=n/10;
    }

  return rev == temp;
}
int main()
{
    int high,low;
    printf("enter the given range : ");
    scanf("%d %d",&high,&low);

    for(int i=high;i>=low;i--)
    {
        if(pali(i))
        {
            printf("largest palindrome is %d",i);
            break;
        }
    }
}