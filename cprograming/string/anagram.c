#include<stdio.h>
int anagram (char str)

int main()
{
    char str1[100];
    char str2[100];

    printf("enter the str1 anagram  : ");
    scanf("%s",str1);

    printf("enter the number str2 : ");
    scanf("%s",str2);

   if( anagram(str1,str1))
   {
    printf("it is an anagram ")
   }
   else
   {
    printf("it is not anagram ");
   }

    

}