#include <stdio.h>

int power(int rem, int digit)
{
    int result = 1;

    for (int i = 0; i < digit; i++)
    {
        result = result * rem;
    }
    return result;
}

int main()
{
    int n, temp;
    printf("enter the number : ");
    scanf("%d", &n);

    temp = n;
    int digit = 0;

    // Count the number of digits
    while (temp != 0)
    {
        digit++;
        temp = temp / 10;
    }

    temp = n;
    int rem = 0, sum = 0;

    // Calculate sum of powers of digits
    while (temp != 0)
    {
        rem = temp % 10;
        sum = sum + power(rem, digit);
        temp = temp / 10;
    }

    if (sum == n)
    {
        printf("%d is an Armstrong number\n", n);
    }
    else
    {
        printf("%d is not an Armstrong number\n", n);
    }

    return 0;
}