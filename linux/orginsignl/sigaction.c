#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 void handlar(int signum)
 {
    if(signum == SIGINT)
    {

        printf("the sigint signal number is %d",signum);
// register the signal to five back the default property os the SIGINT
signal(SIGINT,SIG_DFL);
printf("SININT got the got the default proper back\n");
       // printf("SIGINT signal number is %d\n",signum);
       printf("SIGINT signal sending by the process pid is %d\n",info->si_pid);
    }
    else if(signum=SIGTSTP)
    {
       // printf("hello WORLD\n");
          printf(" SISTSTP  signal sending by the process pid is %d\n",info->si_pid);
    }
   
    
 }

int main()
{
    printf(" pid of process is %d\n",getpid());
    struct sigaction new_act;
    new_act.sa_handler = handlar;
    new_act.sa_flags = SA_SIGINFO;
  //  new_act.sa_flags= 0;

    // register the signal  here
    sigaction(SIGINT,&new_act,NULL);
    sigaction(SIGTSTP,&new_act,NULL);

    signal(SIGINT,handlar);
    signal(SIGTSTP,handlar);
    printf("waiting for the signal\n");
    //"ORIN _siganl.c" 26L,579b
    while(1)
    pause();

}