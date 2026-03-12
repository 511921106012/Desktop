#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],par[100];
    int j,i;
    printf("enter the elements  : ");
    scanf("%s",str);

    printf("enter the which word do u want : ");
    scanf("%s",par);
    int n=strlen(str);
    int m = strlen(par);

for( i=0;i<=n-m;i++)
{
    for( j=0;j<m;j++)
    {
        if(str[i+j]!=par[j])
        {
            break;
        }
    }
    if(j==m)
    {
        printf("%d",i+1);
    }
}

   
}