#include<stdio.h>// count the vovwel and contet
int main()
{
    char str[100];
    printf("enter the string : ");
    scanf("%s",str);
     int count1=0;
     int count2=0;

    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i] == 'a' || str[i] =='e'|| str[i] == 'i'|| str[i] == 'o' || str[i] == 'u' ||   str[i] == 'A' || str[i] =='E'|| str[i] == 'I'|| str[i] == 'O' || str[i] == 'U')
        {
             count1 ++;
        }
        else
        
        count2++;
    }

    printf("vowel count = %d  constant =%d",count1,count2);

    




    
    
}