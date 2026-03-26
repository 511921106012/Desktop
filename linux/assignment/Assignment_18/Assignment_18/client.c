#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>  
#include<unistd.h>      

int main()
{
    int n1,n2;
    printf("Enter the num1: ");
    scanf("%d",&n1);
    printf("Enter the num2: ");
    scanf("%d",&n2);
    char op;
    printf("Enter Arithmetic Operator: ");
    scanf(" %c",&op);
    //Create socket for agent
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
    //Connect to agent
    int ret=connect(sock_fd,(struct sockaddr*)&agent_info,sizeof(agent_info));
    if(ret==-1)
    {
        perror("agent connect");
        return 1;
    }
    //Sending operator to agent
    send(sock_fd,&op,sizeof(op),0);
    int p_no;
    recv(sock_fd,&p_no,sizeof(p_no),0);
    p_no=ntohl(p_no);
    //Closing Socket of Agent
    close(sock_fd);
    //Create socket for operation
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd==-1)
    {
        perror("operation socket");
        return 1;
    }
    struct sockaddr_in op_info={0};
    op_info.sin_family=AF_INET;
    op_info.sin_port=htons(p_no);
    op_info.sin_addr.s_addr=inet_addr("127.0.0.1");
    //Connect to Operation
    int ret1=connect(sock_fd,(struct sockaddr*)&op_info,sizeof(op_info));
    if(ret1==-1)
    {
        perror("op connect");
        return 1;
    }
    n1=htonl(n1);
    n2=htonl(n2);
    send(sock_fd,&n1,sizeof(n1),0);
    send(sock_fd,&n2,sizeof(n2),0);
    int res;
    recv(sock_fd,&res,sizeof(res),0);
    res=ntohl(res);
    printf("The result is %d\n",res);
    close(sock_fd);
}