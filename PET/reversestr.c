#include <stdio.h>
#include <string.h>
#define MAX 50

void reverse_str(char*str,int len)
{
   for(int i=0;i<len/2;i++)
   {
      char temp = str[i];
      str[i] = str[len-i-1];
      str[len -i-1] = temp;
   }
}
void reverse_word(char *str)
{
   
    int i=0,inword=0,start = 0;

    while(str[i]!='\0')
    {
      
        if(str[i]!=' '&&inword == 0)
        {
            start = i;
            inword = 1;
        }
        else if((str[i]==' '||str[i+1]=='\0')&&inword==1)
        {
              int end = (str[i]==' ') ? i-1:i;
              reverse_str(str+start,end-start+1);
              inword = 0;
        }

       i++;
    }
}

int main()
{
    char str[MAX];
    printf("Enter any string->\n");
    scanf(" %[^\n]",str);
    
    int len = strlen(str);

    reverse_str(str,len);
    reverse_word(str);
    printf("%s\n",str);

    return 0;
}