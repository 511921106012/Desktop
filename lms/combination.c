#include <stdio.h>
#include <string.h>

int duplicate(char *str)
{
    for(int i=0; str[i]; i++)
        for(int j=i+1; str[j]; j++)
            if(str[i] == str[j])
                return 1;
    return 0;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char *str, int start, int end)
{
    if(start == end)
    {
        printf("%s\n", str);
        return;
    }

    for(int i=start; i<=end; i++)
    {
        swap(&str[start], &str[i]);
        permute(str, start+1, end);
        swap(&str[start], &str[i]);   // backtrack
    }
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if(duplicate(str))
    {
        printf("Error: please enter distinct characters.\n");
        return 0;
    }

    printf("All possible combinations of given string :%s\n", str);
    permute(str, 0, strlen(str)-1);
}