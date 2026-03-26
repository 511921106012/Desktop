// mod_server.c
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
    server.sin_port = htons(6004);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock,(struct sockaddr*)&server,sizeof(server));
    listen(sock,5);

    printf("Mod server running...\n");

    while(1)
    {
        client = accept(sock,(struct sockaddr*)&client_addr,&len);

        int data[2];
        recv(client,data,sizeof(data),0);

        int result;

        if(data[1] == 0)
            result = 0;
        else
            result = data[0] % data[1];

        send(client,&result,sizeof(result),0);

        close(client);
    }
}