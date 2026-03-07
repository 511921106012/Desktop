#include<stdio.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    int shmid = shmget('A',10,0766)
    if(shmid==-1)
    {
        perror("shmget");
        return -1;
    }
    char *ptr = shmget(shmid,NULL,NULL);
    if(ptr == (void*)-1)
    {
        perror("shamat");
        return -1;
    }

    printf("process got the access to shm \n");
    char [100] = {'\0'};
    printf("enter the masg to share in to shm");
    scanf("%s",buffer);
    strcpy(ptr,buffer);

    // temp shc
    sleep(10);
    //read
    printf("shm data = %s\n",ptr);
    shmdt(ptr);// detach
    shmctl(shmid,IPC_RMID,NULL);
    




}