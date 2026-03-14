#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* shoutNumber(char *s)
{
    int n = strlen(s);
    char *res = (char *)malloc(2 * n + 1);
    int ind = 0;

    for(int i = 0; i < n; i++)
    {
        int count = 1;
        while(i + 1 < n && s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        res[ind++] = count + '0';
        res[ind++] = s[i];
    }
    res[ind] = '\0';
    return res;
}
int main()
{
    char input[] = "112223";

    char *output = shoutNumber(input);

    printf("Input : %s\n", input);
    printf("Output: %s\n", output);

    free(output);   // very important to avoid memory leak
    return 0;
}


