#include<stdio.h>
int main()
{
    int num,pos,n;
    printf("enter the number  : ");
    scanf("%d",&num);

    printf("enter the postion : ");
    scanf("%d",&pos);

    printf("enter the how many digit you want : ");
    scanf("%d",&n);


    int mask = ((1<<n)-1) << (pos -n +1);
    int res = (num & num ) >> (pos -n +1);

    printf("%d",res);

   /* for(int i=7;i>=0;i--)
    {
        printf("%d",(res >> i) &1);
    }
*/
}