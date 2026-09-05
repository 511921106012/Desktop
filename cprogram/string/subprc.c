#include<stdio.h>
#include <string.h>

int main()
{
    char str[100];
    printf("enter the string ");
    scanf("%[^\n]",str);

    char str1[100];
    printf("enter the substring : ");
    scanf("%[^\n]",str1);

    int len = strlen(str1);


    for(int i=0;str[i];i++)
    {
        if(strncmp(str[i],str1[i],len))
        {
            printf("@");
            i=i+2;
            
        }
         else
    {
        printf("%s",str);
    }
    


    }
    

   // printf("%s \n",str);
}