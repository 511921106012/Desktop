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
        perror("agent socket");
        return 1;
    }
    struct sockaddr_in agent_info={0};
    agent_info.sin_family=AF_INET;
    agent_info.sin_port=htons(3000);
    agent_info.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(bind(sock_fd,(struct sockaddr*)&agent_info,sizeof(agent_info))==-1)
    {
        perror("Bind");
        return 1;
    }
    listen(sock_fd,5);
    while(1)
    {
    socklen_t size=sizeof(agent_info);
    int dat_fd=accept(sock_fd,(struct sockaddr*)&agent_info,&size);
    if(dat_fd==-1)
    {
        perror("accept");
        return 1;
    }
    char ch;
    recv(dat_fd,&ch,sizeof(ch),0);
    switch(ch)
    {
        case '+':
        {
            int p_no=htonl(3001);
            send(dat_fd,&p_no,sizeof(p_no),0);
            break;
        }
        case '-':
        {
            int p_no=htonl(3002);
            send(dat_fd,&p_no,sizeof(p_no),0);
            break;
        }
        case '*':
        {
            int p_no=htonl(3003);
            send(dat_fd,&p_no,sizeof(p_no),0);
            break;
        }
        case '/':
        {
            int p_no=htonl(3004);
            send(dat_fd,&p_no,sizeof(p_no),0);
            break;
        }
        case '%':
        {
            int p_no=htonl(3005);
            send(dat_fd,&p_no,sizeof(p_no),0);
            break;
        }
        default:
        {
            int p_no=htonl(-1);
            send(dat_fd,&p_no,sizeof(p_no),0);
        }   
    }
    close(dat_fd);
    }
    close(sock_fd);

}