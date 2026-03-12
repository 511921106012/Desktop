#include<stdio.h>
#include<string.h>

int isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' 
    || c == 'E' || c == 'I' || c=='O' || c == 'U' )
    return 1;
    else
    return 0;
}
int main()
{
    char str[100];
    printf("enter the word : ");
    scanf("%s",str);
    int left =0;
    int right = strlen(str)-1;

    while(left<right)
    {
        if(!isVowel(str[left]))
        {
            left++;
        }

        else if(!isVowel(str[right]))
        {
            right--;
        }


        while(left<right)
        {
            int temp = str[left];
            str[left]=str[right];
            str[right]=temp;
            left++;
            right--;
        }

        printf("%s",str);
    }
}