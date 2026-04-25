#include<stdio.h>
int main()
{
    int a,b;
    char ch;

    printf("enter the number : ");
    scanf("%d %c %d",&a,&ch,&b);
    

    switch(ch)
    {
        case '+':
        printf("the addition is %d",a+b);
        break;
        case '-':
        printf(" the supp is %d",a-b);
        break;
        case '*' :
        printf("the multiple is %d",a*b);
        break;
        case '/':
        printf("the division is %d",a/b);
        break;


    }
}