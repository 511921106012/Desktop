// reverse string

/*#include <stdio.h>
#include <string.h>
#define MAX 50

int main()
{
    char str[MAX];
    printf("Enter the string-> ");
    scanf("%49[^\n]",str);

    printf("before reverse: %s\n",str);

    int len = strlen(str);

    for(int i=0 ;i < len/2 ; i++)
    {
         char temp = str[i];
         str[i] = str[len-i-1];
         str[len-i-1]  = temp;
    }

    printf("After reverse: %s\n",str);

    return 0;
}*/

//number palindrome

#include <stdio.h>

int main()
{
     int num = 0;
     printf("Enter the number: ");
     scanf("%d",&num);

     int temp = num,rev = 0;

     while(num != 0)
     {
         int rem = num %10;
         rev = rev *10 + rem;
         num /= 10;
     }

     if(rev == temp)
     {
         printf("Number is an palindrome\n");
     }
     else
     {
        printf("Not a palindrome\n");
     }

     return 0;
}