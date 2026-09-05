#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    if(n<=0)
    {
        printf("invalid input");
        return 0;
    }

    int rev =0,bin[32],i=0;

    int temp =n;

    while (temp !=0)
    {
        bin[i++]= temp %2;
        temp = temp /2;
    }

    printf("binary  :  ");

    for(int j = i-1;j>=0;j--)
    {
        printf("%d",bin[j]);
    }

    printf("\n");

    printf("binary reverse  :  ");

    for(int j =0;j<i;j++)
    {
        printf("%d",bin[j]);
    }

    printf("\n");

    printf("decimal : ");

    for(int j=0;j<i;j++)
    {
        rev = rev *2 +bin[j];
    }
    printf("%d\n",rev);

    return 0;
}