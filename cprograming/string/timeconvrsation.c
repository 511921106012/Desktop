#include<stdio.h>
void time(int h,int m)
{
    char *num[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen",
        "seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three",
    "twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};

    if(m==0)
    {
        printf(" %s o' clock\n",num[h]);
    }
    else if( m == 15)
    {
        printf("quarter past %s\n",num[h]);
    }
    else if(m== 30)
    {
        printf("half past %s\n",num[h]);
    }

    else if(m<30)
    {
        if(m==1)
        {
            printf("%s minute past %s\n",num[m],num[h]);
        }
        else
        {
            printf("%s minutes past %s\n",num[m],num[h]);
        }
    }
    else
    {
        int rem = 60 - m;
        if(rem == 15)
        {
            printf("quarter to %s",num[rem],num[h+1]);
        }
        else if(rem ==1 )
        {
            printf("%s minute to %s\n",num[rem],num[h+1]);
        }
        else
        {
             printf("%s minutes to %s\n",num[rem],num[h+1]);
        }

    }
}
int main()
{
     int h,m;
     printf(" enter the hour and mints : ");
     scanf("%d %d",&h,&m);
     time( h, m);
     return 0;
}