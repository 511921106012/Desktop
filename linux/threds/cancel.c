#include<stdio.h>
#include<pthread.h>

void *thread(void * data)
{
 //   printf("thread cancellation state is changed to disable\n");
   // pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
 /*print("thread cancellation state is changed to enable and asynchronous type \n");
 pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
 pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);*/

 printf("pthread cancellation astate is changed to enable and deferred type\n");
 pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
 pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);



/*for(int i=0;i<10;i++)
    {
        printf("inside the thread function\n");
        sleep(1);
    }  */


    while(1);
}

int main()
{
     pthread_t tid;
     pthread_create(&tid,NULL,thread,NULL);
     sleep(3);
     printf("sending the cancellation request to the thread.....\n");
     pthread_cancel(tid);
     pthread_join(tid,NULL);

}