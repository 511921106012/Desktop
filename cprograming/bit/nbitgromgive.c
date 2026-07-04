#include<stdio.h>
int main()
{
    int n;
    int pos,num ;

    printf("enter the number : ");
    scanf("%d",&n);

    printf("enter the postion and and num : ");
    scanf("%d %d",&pos,&num);

    if(pos<n || n<=0 || pos>100000)
    {
        return 0;
    }



    unsigned int mask = ((1<<i) -1) << (pos -n +1);
    unsigned int bit = (num&mask) >> (pos -n +1);

    printf("the nth  bit postion ");

    for(int i = n-1;i>=0;i--)
    {
        printf("%d",(bit>>i) & 1);
    }

    return 0;
}
















/*#include<stdio.h>
int main()
{
    int n;
    int pos,num;

    printf("enter the num : ");
    scanf("%d",&num);

    printf("enter the pos and n value");
    scanf("%d %d",&pos,&n);


    if(pos < n || n <= 0 || pos>32)
    {
        printf("input invalid ");
        return 0;
    }

    unsigned int  mask = ((1 << n)-1) << (pos -n +1);
    unsigned int  bit = (num  & mask ) >> (pos -n +1);

    printf("nth bit of postion ");
    for(int i = n-1;i>=0;i--)
    {
        printf("%d",(bit>>i)&1);
    }
}  */