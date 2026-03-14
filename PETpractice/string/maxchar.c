#include<stdio.h>
int main()
{
    char str[100];
    scanf("%s",str);

    int count =0;
    int max=0;
    char max_char;

    for(int i=0;str[i];i++)
    {
        int count =0;
        for(int j=0;str[j];j++)
        {
            if(str[i]==str[j])
            {
                count++;

            }
        }

        if(count>max)
        {
            max = count;
            max_char = str[i];

        }
    }

    printf("count is = %d char is  = %c",max,max_char);
}