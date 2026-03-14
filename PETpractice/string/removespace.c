#include<stdio.h>
int main()
{
    char str[100];
    printf("enter the number : ");
    scanf("%[^\n]",str);
    int j=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            str[j]=str[i];
            j++;
            
        }
    }

    printf("%s",str);
}