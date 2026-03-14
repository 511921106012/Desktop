#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* countandsay(int n)
{
    char *cur = malloc(5000);
    char *next = malloc(5000);
    strcpy(cur, "1");
    for(int i = 2; i <= n; i++)
    {
        int ind = 0;
        int count = 1;
        for(int j = 1; cur[j - 1] != '\0'; j++)
        {
            if(cur[j] == cur[j - 1])
            {
                count++;
            }
            else
            {
                ind = ind + sprintf(next + ind, "%d%c", count, cur[j - 1]);
                count = 1;
            }
        }
        next[ind] = '\0';
        strcpy(cur, next);
    }
    free(next);
    return cur;
}
int main()
{
    int n;
    scanf("%d",&n);

    char *result = countandsay(n);
    printf("%s",result);
    free(result);
    return 0;
}