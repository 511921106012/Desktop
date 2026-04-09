/* Client-side header - client specific structures and function declarations */

/* Header guard - duplicate include avoid panrom */
#ifndef TFTP_CLIENT_H
#define TFTP_CLIENT_H

#include "tftp.h" /* tftp_packet, PORT ellam already idha irukku */

/* Client state store pannuradhu - oru connection ku oru struct */
typedef struct {
    int sockfd;                        /* Socket file descriptor - connection handle */
    struct sockaddr_in server_addr;    /* Server IP + Port store panrom */
    socklen_t server_len;              /* server_addr size - sendto ku vendiyathu */
    char server_ip[INET_ADDRSTRLEN];   /* Server IP string - display ku use panrom */
} tftp_client_t;

/* Function prototypes - tftp_client.c la implement pannuvom */

/* connect_to_server - socket create + server address setup - packet anuppaadhu */
void connect_to_server(tftp_client_t *client, char *ip, int port);

/* put_file - local file uh server ku upload panrom - WRQ anuprom */
void put_file(tftp_client_t *client, char *filename);

/* get_file - server la irundhu file download panrom - RRQ anuprom */
void get_file(tftp_client_t *client, char *filename);

/* disconnect - socket close panrom */
void disconnect(tftp_client_t *client);

/* process_command - user type pannuradha parse panrom - connect/get/put/quit */
void process_command(tftp_client_t *client, char *command);

/* send_request - RRQ or WRQ packet build panni server ku anuprom */
void send_request(int sockfd, struct sockaddr_in server_addr, socklen_t server_len, char *filename, int opcode);

/* receive_request - server side concept - client la use aagaadhu */
void receive_request(int sockfd, struct sockaddr_in server_addr, socklen_t server_len, char *filename);

#endif /* TFTP_CLIENT_H */
