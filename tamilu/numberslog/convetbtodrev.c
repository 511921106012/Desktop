#include<stdio.h>
int main()
{
    int n;
    printf("enter the number : ");
    scanf("%d",&n);

    int arr[32];
    int i=0;

    while(n>0)
    {
        arr[i]=(n%2);
        n=n/2;
        i++;
    }

printf("binary ");
    for(int j= i-1;j>=0;j--)
    {
        printf("%d",arr[j]);
    }

    printf("reversed");
    for(int k=0;k<i;k++)
    {
        printf("%d",arr[k]);
    }



}