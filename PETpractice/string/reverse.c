#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter the string : ");
    scanf("%[^\n]",str);
    int len = strlen(str)-1;
    int temp;



    for(int i=0;i<len/2;i++)
    {
        temp=str[i];

        str[i]=str[len-1-i];
        str[len -1-i]=temp;
        

    }

    printf("%s",str);
}