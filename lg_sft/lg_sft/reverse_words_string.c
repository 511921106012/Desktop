#include <stdio.h>
#include <string.h>
char* revstring(char* s, int size)
{
    int l = 0, r = size - 1;
    while(l < r)
    {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
} 
int main()
{
    char str[200];
    printf("Enter the string: ");
    scanf("%[^\n]",str);
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    char *res = revstring(str, len);
    printf("%s",res);
    
}