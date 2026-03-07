#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
   int  pid = fork();
  
    if(pid>0)
    {
           printf(" parent or child you should decide first  = %d\n",pid);
           sleep(10);
    printf("childs is zombie");

    pid2 = fork();
    if(pid1>0)
    {
        sleep(1);

    }
    if(pid1 ==0)
    {
        sleep(1);
        int ppid2 = getppid();
        if(pid1 != ppid2)
        {
             printf("child is zombie");33   
        }
    }
    



   
    }
    if(pid==0)
    {
        printf("child is runing ");
    sleep(5);
    printf("parent is runing");
   
}
}