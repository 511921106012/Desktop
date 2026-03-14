#include <stdio.h>
void strrev(char *s)
{
    int i = 0, j;
    while(s[i] != '\0') i++;
    j = i - 1;
    for(i = 0; i < j; i++,j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
int main()
{
    char str[20];
    printf("enter the string: ");
    scanf("%[^\n]",str);

    strrev(str);
    printf("%s",str);
}