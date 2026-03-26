#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>  
#include<unistd.h>  

int main()
{
     int sock_fd=socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd==-1)
    {
        perror("add socket");
        return 1;
    }
    struct sockaddr_in add_info={0};
    add_info.sin_family=AF_INET;
    add_info.sin_port=htons(3005);
    add_info.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(bind(sock_fd,(struct sockaddr*)&add_info,sizeof(add_info))==-1)
    {
        perror("Bind mod");
    }
    listen(sock_fd,5);
    while(1)
    {
    socklen_t size=sizeof(add_info);
    int dat_fd=accept(sock_fd,(struct sockaddr*)&add_info,&size);
    if(dat_fd==-1)
    {
        perror("accept");
        return 1;
    }
    int n1,n2;
    recv(dat_fd,&n1,sizeof(n1),0);
    recv(dat_fd,&n2,sizeof(n2),0);
    n1=ntohl(n1);
    n2=ntohl(n2);
    int res=n1%n2;
    res=htonl(res);
    send(dat_fd,&res,sizeof(res),0);
    close(dat_fd);
    }
    close(sock_fd);
}