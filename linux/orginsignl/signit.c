#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 void handlar(int signum)
 {
    if(signum == SIGINT)
    {

        printf("the sigint singanl number is %d",signum);
// register the signal to five back the default property os the SIGINT
signal(SIGINT,SIG_DEF);
printf("SININT got the got the default erperty back\n")
        printf("SIGINT signal number is %d\n",signum);
    }
    else
    {
        printf("%d SIGTSTP signal number is ",signum);
    }
    
 }

int main()
{
    printf(" pid of process is %d\n",getpid());

    // register the signal  here

    signal(SIGINT,handlar);
    signal(SIGTSTP,handlar);
    printf("waiting for the signal\n");
    "ORIN _siganl.c" 26L,579b
    while(1)
    pause();

}