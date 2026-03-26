// agent.c
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int sock, client;
    struct sockaddr_in server, client_addr;
    socklen_t len = sizeof(client_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock,(struct sockaddr*)&server,sizeof(server));
    listen(sock,5);

    printf("Agent running...\n");

    while(1)
    {
        client = accept(sock,(struct sockaddr*)&client_addr,&len);

        char op;
        recv(client,&op,sizeof(op),0);

        int port;

        switch(op)
        {
            case '+': port=6000; break;
            case '-': port=6001; break;
            case '*': port=6002; break;
            case '/': port=6003; break;
            case '%': port=6004; break;
            default: port=0;
        }

        send(client,&port,sizeof(port),0);

        close(client);
    }
}