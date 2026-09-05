#include<stdio.h>
int main()
{
    char str[100];
    printf("enter the string ");
    scanf("%s",str);

    int len=0;
    while(str[len]!='\0')
    len++;


   int  left=0;
    int right = len -1;


    while(left <right)
    {
        if(str[left]!=str[right])
        {
            printf(" not palindrome");
            return 0;

        }

        left++;
        right--;
    }

    printf("palindrome");
}