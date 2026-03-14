#include <stdio.h>
#include <stdbool.h>
bool isvalidanagram(char *s, char *t)
{
    int count[26] = {0};
    while(*s)
    {
        count[*s++ - 'a']++;
    }
    while(*t)
    {
        count[*t++ - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(count[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char s[200], t[200];
    printf("Enter two strings: ");
    scanf("%s%s",s,t);
    if(isvalidanagram(s, t))
    {
        printf("anagram\n");
    }
    else
    {
        printf("not anagram\n");
    }
}
/*
int isvalidanagram(char s[], char t[])
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
}*/