#include<stdio.h>
int main()
{
    int num =29;

    int n=1;
int set= num | (1<<3);
int clar = num & ~(1<<n);
int tag = num ^ (1<<n);


    printf("the set bit is %d\n",set);
    printf("the clear bit is %d\n",clar);
    printf("tag is %d\n",tag);
}