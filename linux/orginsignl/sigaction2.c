#include<stdio.h>
#include<unistd.h>
#include<signal.h>
 void handlar(int signum,siginfo_t *info ,void *data)
 {
   if(signum == SIGINT)
   {
      int i=0;
   while(i<=10)
   {
      printf("hello");
      sleep(1);
      i++;
   }
}

   else if(signum == SIGTSTP)
   {
    int i = 1;

    while(i <= 10)
    {
      printf("world");
      sleep(1);
      i++;
    }
   }

    
 }

int main()
{
    printf(" pid of process is %d\n",getpid());
    struct sigaction new_act;
    new_act.sa_sigaction  = handlar;
    new_act.sa_flags = SA_SIGINFO;
  //  new_act.sa_flags= 0;

    // register the signal  here
    sigaddset(&new_act.sa_mask,SIGINT);
    sigaddset(&new_act.sa_mask,SIGTSTP);

   sigaction(SIGINT,&new_act,NULL);
   sigaction(SIGTSTP,&new_act,NULL);

    //(SIGINT,handlar);
    //signal(SIGTSTP,handlar);
    printf("waiting for the signal\n");
    //"ORIN _siganl.c" 26L,579b
    while(1)
    pause();

}