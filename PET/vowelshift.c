#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int isvowel(char ch)
{
    char *vowel ="AEIOUaeiou";
    for (int i=0;vowel[i]!='\0';i++)
    {
        if(vowel[i]==ch)
        {
          return 1;
        }
    }

    return 0;
    
}

int main()
{
    char str[MAX];
    printf("Enter any string->\n");
    scanf(" %99[^\n]",str);

    int left = 0,right = strlen(str)-1;

    while(left < right)
    {
        while(left<right && !isvowel(str[left]))
          left++;
        while(left<right && !isvowel(str[right]))
          right--;
          
        if(left<right)
        {
           char temp = str[left];
           str[left] = str[right];
           str[right] = temp;

           left++;
           right--;
        }          
    }

    printf("After->\n");
    printf("%s\n",str);

    return 0;

}