#include<stdio.h>
int main()
{
    int n;
    printf("enter the comer : ");
    scanf("%d",&n);

    int check = n%10;
    n= n/10;

    while(n>0)
    {
        int comp = n%10;

        if(comp > check)
        {
            printf("not acc oder");
            return 0;
        }

        check = comp;
        n= n/10;
    }

    printf(" %d it is oder ",check);
}