#include<stdio.h>
int main()
{
    int n,sec,next;
    printf("enter the number  : ");
    scanf("%d",&n);

    int first ;
    for(int i=0;i<=n;i++)
    {
        next = first + sec;
        first = sec;
        sec = next;

        printf("%d",next);
    }
}