#include<stdio.h>
int main()
{
    int a;
    printf("enter the mark : ");
    scanf("%d",&a);
    

    if(a>= 100 && a<=80)
    {
        printf("these student are A grade student : ");
    }
    else if(a>=79 && a<=65)
    {
        printf("these student are B grade student ");
    }
    else if(a>=64 && a<=50)
    {
        printf("these student are C grade student ");
    }
    else if(a>= 49 && a<=35)
    {
        printf("these student are D grade student ");

    }
    else
    {
        printf("these the student fail");
    }
    return 0;
}