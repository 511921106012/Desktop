#include<stdio.h>
int main()
{
    char str[100];
    scanf("%s",str);
    int count =0;

    for(int i=0;str[i];i++)
    {
        count++;
    }
    printf(" the string length is %d",count);
}