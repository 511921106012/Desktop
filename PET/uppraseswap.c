#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main()
{
   
    char str[MAX];
    printf("Enter any string->\n");
    scanf(" %99[^\n]",str);

    int len = strlen(str);
    int right= len-1,left=0;
    
    while(left<right)
    {
        while(left<right && !isupper(str[left]))
        left++;

        while(left<right && !isupper(str[right]))
        right--;
        
        if(left<right)
        {
            char temp =str[left];
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