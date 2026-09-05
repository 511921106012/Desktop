// without using lib convert the uppercase
#include<stdio.h>
void fun (char *str)
{
    for(int i=0;str[i];i++)
    {
        if(str[i] >='A'  && str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
    }
}

int main()
{
    char str[100];
    printf("enter the character : ");
    scanf("%[^\n]",str);
    fun(str);
    printf("%s",str);

}
