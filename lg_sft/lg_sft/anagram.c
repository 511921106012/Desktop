#include <stdio.h>
/*#include <stdbool.h>
bool anagram(char *s, char *t)
{
    int count[26] = {0};
    while(*s)
    {
        count[*s++ - 'a']++;
    }
    while(*t)
    {
        count[*t++ -'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            return false;
        }
    }
    return true;
}*/
int anagram(char s[], char t[])
{
    int count[26] = {0};
    for(int i = 0; s[i] != '\0'; i++)
    {
        count[s[i] - 'a']++;
    }
    for(int i = 0; t[i] != '\0'; i++)
    {
        count[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            return 0;
        }     
    }
    return 1;
}

int main()
{
    char s[100], t[100];
    printf("Enter two strings: ");
    scanf("%s%s",s,t);
    if(anagram(s, t))
    {
        printf("Anagram\n");
    }
    else
    {
        printf("Not anagram\n");
    }
}