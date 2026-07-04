#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main()
{
    char str1[MAX],str2[MAX];
    printf("Enter string 01->\n");
    scanf(" %[^\n]",str1);
    printf("Enter string 02->\n");
    scanf(" %[^\n]",str2);
    
    int len1 = strlen(str1),len2 =strlen(str2);
    int reslen = len1+len2;

    char*output = malloc(reslen+1);
     
    int i = 0,j =0;

     while(i<len1||i<len2)
     {
        if(i < len1)
        {
           output[j++] = str1[i]; 
        }
        if(i < len2)
        {
          output[j++] =str2[i];  
        }
        i++;
     }
     
     output[j] = '\0';

     printf("%s\n",output);

    free(output);
    return 0;
}