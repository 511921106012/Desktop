#include<stdio.h>
void sum (int a[],int b[],int temp[])
{

    *temp = *a+*b;
    return temp;
}


int main()
[
    int *a,*b;
    
    printf("enter the number : ");
    scanf("%d %d",&a,&b);
    int temp;
    sum(&a,&b,&temp);

    printf("%d",temp);
    
]