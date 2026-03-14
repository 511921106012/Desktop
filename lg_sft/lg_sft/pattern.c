#include <stdio.h>

int main()
{

    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            if(i == 1)
                printf("%d ", j);
            else if(j == 1)
                printf("%d ", i);
            else
                printf("%d ", i + j + (i - 2));
        }
        printf("\n");
    }

    return 0;
}