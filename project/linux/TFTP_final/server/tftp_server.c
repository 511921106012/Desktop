#include "tftp.h"    /* tftp_packet, PORT, BUFFER_SIZE ellam idha irundhu varudu */
#include <stdio.h>   /* printf, perror use pannanum */
#include <stdlib.h>  /* exit() use pannanum */
#include <string.h>  /* memset use pannanum */
#include <unistd.h>  /* close() use pannanum */
#include <arpa/inet.h> /* socket functions, htons, INADDR_ANY */

/* handle_client function - main ku munnaadi declare panrom - forward declaration */
void handle_client(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, tftp_packet *packet);

int main()
{
    /* Socket file descriptor - oru phone number maari - socket identify pannuradhu */
    int sockfd;

    /* server_addr = server own address, client_addr = client enna address irundhu connect aachunu */
    struct sockaddr_in server_addr, client_addr;

    /* client_addr size - recvfrom ku kondupora parameter */
    socklen_t client_len = sizeof(client_addr);

    /* Incoming packet store pannuradhu */
    tftp_packet packet;

    /* UDP socket create panrom - SOCK_DGRAM = UDP, SOCK_STREAM = TCP aagum */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket() failed"); /* Socket create fail - program exit */
        exit(1);
    }

    /* Timeout set panrom - client reply varaama TIMEOUT_SEC seconds wait pannudu */
    struct timeval tv;
    tv.tv_sec  = TIMEOUT_SEC; /* 5 seconds wait */
    tv.tv_usec = 0;           /* microseconds = 0 */

    /* setsockopt - socket options set pannuradhu - SO_RCVTIMEO = receive timeout */
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt() failed");
        close(sockfd);
        exit(1);
    }

    /* Server address setup - enna IP, enna port la listen pannanum */
    memset(&server_addr, 0, sizeof(server_addr)); /* Zero fill - garbage clear */
    server_addr.sin_family      = AF_INET;         /* IPv4 use panrom */
    server_addr.sin_addr.s_addr = INADDR_ANY;      /* Any network interface irundhu accept */
    server_addr.sin_port        = htons(PORT);      /* Port 6969 - htons = host to network byte order */

    /* Bind - socket ku address assign panrom - "idha PORT la listen pannu" nu OS ku solludu */
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        close(sockfd);
        exit(1);
    }

    printf("TFTP Server listening on port %d...\n", PORT);

    /* Infinite loop - server always run aaganum - client request varum varaiku wait */
    while (1) {

        /* Packet buffer clear panrom - previous request data clear aaganum */
        memset(&packet, 0, sizeof(packet));

        /* Client irundhu packet receive panrom - recvfrom = UDP receive + client address kedaikum */
        int n = recvfrom(sockfd, &packet, BUFFER_SIZE, 0,
                         (struct sockaddr *)&client_addr, &client_len);

        /* n < 0 = timeout or error - continue panrom - next request wait panrom */
        if (n < 0) {
            perror("Receive failed or timeout occurred");
            continue; /* Loop again - wait for next client */
        }

        /* Valid packet kedaichutu - handle_client call panrom */
        handle_client(sockfd, client_addr, client_len, &packet);
    }

    close(sockfd); /* Program exit aana socket close - never reach here normally */
    return 0;
}

/*
 * handle_client()
 * Client request packet eduthu - opcode check panrom
 * RRQ = client file download pannanum - send_file() call
 * WRQ = client file upload pannanum  - receive_file() call
 * Vera opcode = ERROR anuprom
 */
void handle_client(int sockfd, struct sockaddr_in client_addr,
                   socklen_t client_len, tftp_packet *packet)
{
    /* Packet la irundhu opcode edukurom - ntohs = network to host byte order */
    uint16_t opcode = ntohs(packet->opcode);

    /* Packet la irundhu filename edukurom - RRQ/WRQ la filename irukkum */
    char *filename  = packet->body.request.filename;

    printf("handle_client: opcode=%d filename='%s'\n", opcode, filename);

    /* RRQ = Read Request - client server la irundhu file download pannanum */
    if (opcode == RRQ) {
        /* send_file call - server file eduthu client ku anuppadum */
        send_file(sockfd, client_addr, client_len, filename);

    /* WRQ = Write Request - client file upload pannanum */
    } else if (opcode == WRQ) {
        /* receive_file call - server client irundhu file receive pannum */
        receive_file(sockfd, client_addr, client_len, filename);

    /* Unknown opcode - ERROR packet anuprom */
    } else {
        tftp_packet err_pkt;
        memset(&err_pkt, 0, sizeof(err_pkt));

        err_pkt.opcode = htons(ERROR);

        /* Error code 4 = "Illegal TFTP operation" */
        err_pkt.body.error_packet.error_code = htons(4);

        snprintf(err_pkt.body.error_packet.error_msg,
                 sizeof(err_pkt.body.error_packet.error_msg),
                 "Illegal operation: opcode=%d", opcode);

        /* Client ku error anuprom */
        sendto(sockfd, &err_pkt, sizeof(err_pkt), 0,
               (struct sockaddr *)&client_addr, client_len);

        fprintf(stderr, "handle_client: unknown opcode %d\n", opcode);
    }
}
