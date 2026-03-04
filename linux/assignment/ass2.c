#include<stdio.h>
#include<fcntl.h>


int main(int count,char * argv[])
{
   int ret ;
   while((ret = getopt(argc ,argv,"abc"))!=-1)
   switch(ret)
   {
   case'?':
          printf("%c is invalid\n");
          break;
   case'a':
   printf("a si a option");
   break;

   case 'b';
   printf("b is an option ");
   break;
   case:
   printf("c is an option  ");
   break;

   for(int i=0;i<argc;i++)
   {
    printf("[%d] -> %s\n",argv[i]);// return chearacter print panrom [%d];
   }

   }

   printf("%d is an option \n");


}