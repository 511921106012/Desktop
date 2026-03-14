#include<stdio.h>
int main()
{
    char str[100];
    printf("enter the elements : ");
    scanf("%s",str);

    int flag =1;

    for(int i=0;str[i];i++)
    {
        if(str[i]< '0'|| str[i]>'9')
        {
            flag =0;
            break;
        }
    }
    if(flag == 1)
    {
        printf("valid ");
    }
    else
    {
        printf("  in valid");
    }
}