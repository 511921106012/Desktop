#include<stdio.h>
#include<ctype.h>
int main()
{
    char str[100];
    int arr[26]={0};

    scanf("%[^\n]",str);
    int  count =0;


    for(int i=0;str[i]!='\0';i++)
    {
        if(isalpha (str[i]))
        {
            int index = tolower(str[i])- 'a';
            if(arr[index] == 0)
            {
                arr[index]=1;
                count++;
            }
        }
    }
    if (count==26)
    {
        printf("pangram");
    }
    else
    printf("not pangram");
    return 0;

}