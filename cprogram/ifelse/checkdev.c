#include<stdio.h>
int main()
{
    char str[100];
    printf("enter the number : ");
    scanf("%[^\n]",str);

    printf("\n%s\n",str);
}