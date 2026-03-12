#include<stdio.h>
int main()
{
    char str[100];
    char ch;
    printf("enter the string words : ");
    scanf("%[^\n]",str);

    printf("enter the which do want remove : ");
    scanf(" %c",&ch);

    for(int i=0;str[i]!='\0';i++)
    {
        if (str[i]!=ch)
        {
            printf("%c",str[i]);
        }
    }
}