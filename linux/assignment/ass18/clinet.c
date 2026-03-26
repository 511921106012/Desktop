// client.c
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int sock;
    struct sockaddr_in server;
    char buffer[100];
    int num1, num2;
    char op;

    printf("Enter num1: ");
    scanf("%d",&num1);
    printf("Enter num2: ");
    scanf("%d",&num2);
    printf("Enter operator: ");
    scanf(" %c",&op);

    // ----------- CONNECT TO AGENT ----------
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock,(struct sockaddr*)&server,sizeof(server));

    // send operator
    send(sock,&op,sizeof(op),0);

    int port;
    recv(sock,&port,sizeof(port),0);

    close(sock);

    // -------- CONNECT TO MAIN SERVER --------
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_port = htons(port);

    connect(sock,(struct sockaddr*)&server,sizeof(server));

    int data[2] = {num1,num2};
    send(sock,data,sizeof(data),0);

    int result;
    recv(sock,&result,sizeof(result),0);

    printf("RESULT: %d\n",result);

    close(sock);
}