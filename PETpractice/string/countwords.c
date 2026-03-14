#include<stdio.h>
int main()
{
    char str[100];
    printf("enter the words");
    scanf("%[^\n]",str);
    int count =0;


    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ')
        {
            count++;
        }
    }
    printf(" the word count is %d",count);
}