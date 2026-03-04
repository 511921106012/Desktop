#include<stdio.h>
#include<signal.h>

int main()
{
// orign of the signels
    //int *ptr = 100;
    //*ptr = 10;
    //printf("%d",*ptr);   



    // 2 orgin of the signals
 //   while(1)


    int ret =fork();
    if(ret ==0)
    {
        printf("child pid %d\n",getpid());
        sleep(10);
        printf("child is terminated");
    } 
    if(ret > 0)
    {
        sleep(3);
        printf("sending to the sigint signal to child\n");
      //  kill(ret,SIGINT);
    }
}