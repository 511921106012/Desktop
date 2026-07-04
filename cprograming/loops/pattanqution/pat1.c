#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 100000)
    {
        printf("invalid input : ");
        return 0;
    }

    int start = 1;

    for (int i = 1; i <= n; i++)
    {
        int num = start;

        for (int j = 1; j <= i; j++)
        {
            if (j > 1)
            {
                printf(" ");
            }

            printf("%d", num);
            num++;
        }

        printf("\n");

        start = num -1;
    }

    return 0;     
}