#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    int r,c;
    printf("Enter rows and cols: ");
    scanf("%d%d",&r,&c);
    int arr[r][c];
    printf("Enter the elements: ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int result = abs(arr[0][0]);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            result = gcd(result, abs(arr[i][j]));
            if(result == 1)
            {
                printf("1\n");
                return 0;
            }
        }
    }
    printf("%d\n",result);
}
