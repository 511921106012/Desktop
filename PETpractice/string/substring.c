#include<stdio.h>
#include<string.h>

int main()
{
    char s1[100],s2[100];
    printf("enter the string : ");
    scanf("%s",s1);

    printf("enter the sub string : ");
    scanf("%s",s2);


    int n=strlen(s1);
    int m=strlen(s2);

    int flag=1;


    for(int i=0;i<=n-m;i++)
    {
        int j;
        for( j=0;j<m;j++)
        {
            if(s1[i+j]!=s2[j])
            {
                break;

            }
        }
        if(j==m)
        {
            flag=1;
            break;

        }
    }

    if(flag)
    {
        printf("found");
    }
    else
    {
     printf("not found ");
    }
}