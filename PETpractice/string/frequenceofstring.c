#include<stdio.h>
int main()
{
    char str[100];
    scanf("%s",str);

    for(int i=0;str[i];i++)
    {
        int count =1;

        if(str[i]=='*')
        {
            continue;
        }

        for(int j=i+1;str[j];j++)
        {
            if(str[i]==str[j])
            {
                count++;
                str[j]='*';
            }
        }

        printf("%c %d\n",str[i],count);
    }
}