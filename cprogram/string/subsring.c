#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sub_string(char *mainstr ,char *find,char *rep,char *result)
{

    int i=0,r=0,k;
    if(mainstr==NULL || find == NULL  || rep == NULL || result == NULL)
    {
        return ;
    }

    int findlen = strlen(find);
    int replace = strlen(rep);

    if(findlen == 0)
    {
        strcpy(result,mainstr);
        return ;
    }

    if(mainstr[0] == '\0')
    {
        result[0] = '\0';
        return ;
    }


    while(mainstr[i] != '\0')
    {
        if(strncmp(&mainstr[i],find,findlen)==0)
        {
             for(k=0;k<replace;k++)
             {
                result[r++] = rep[k];
             }
             i= i+findlen;
        }
        else
        {
            result[r++]=mainstr[i++];
        }
    }
    result[r] = '\0';


}

int  main()
{
    char mainstr[100],find[100],rep[100];
    
    if(scanf(" %[^\n]",mainstr)!=1)
    {
        printf("invalid input\n");
        return 1 ;
    }

    if(scanf(" %[^\n]",find)!=1)
    {
        printf("invalid input\n");
        return 1 ;
    }

    if(scanf(" %[^\n]",rep)!=1)
    {
        printf("invalid input\n");
        return 1 ;
    }

    int mainlen = strlen(mainstr);
    int findlen = strlen(find);
    int repl = strlen(rep);


    int max;

    if(mainlen ==0)
    {
        max = mainlen +1;
    }
    else if(findlen ==1)
    {
        max = mainlen * repl + 1;
        
    }
    else if(findlen>0)
    {
        max = mainlen + (repl - findlen) * (mainlen / findlen) + 100;
    }

    char * result = (char *)malloc(max);
    if(!result)
    {
        printf("the memory not there\n");
        return 1;
    }


    sub_string(mainstr,find,rep,result);
    printf("%s\n",result);
    free(result);
    return 0 ;
}
