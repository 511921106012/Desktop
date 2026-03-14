#include<stdio.h>
int main()
{
    char s1[100],s2[100];
    scanf("%s",s1);
    scanf("%s",s2);
    int len1=0;
    int len2=0;

    int count=0;
    for(int i=0;i<s1[i];i++)
    {
        len1++;
    }
    for(int i=0;i<s2[i];i++)
    {
        len2++;
    }


    for(int i=0;i<s1[i];i++)
    {
        for(int j=0;j<s2[j];j++)
        {
            if(s1[i] == s2[j])
            {
                count++;
                s2[j]='*';
            }
        }
    }

    if(count == len1)
    {
        printf("anagram");

    }
    else
    {
    printf("not anagram ");
    }
}