/* Common file for server & client */

/* Header guard start - same file rendu thadavai include aagaama protect panradhu */
#ifndef TFTP_H
#define TFTP_H

/* uint16_t use pannanum - adhukkaga stdint include panrom - fixed size integer */
#include <stdint.h>

/* htons(), inet_pton(), sockaddr_in ellam idha irundhu varudu - network programming mandatory */
#include <arpa/inet.h>

/* TFTP standard port 69 - aana root permission vaangudum so 6969 use panrom */
#define PORT 6969

/* TFTP data packet size - 512 bytes data + 4 bytes header = 516 */
#define BUFFER_SIZE 516

/* Server reply varaama wait panra max time - 5 seconds wait, illana timeout */
#define TIMEOUT_SEC 5

/* TFTP OpCodes - enna type packet nu identify pannuradhu */
typedef enum {
    RRQ   = 1,  /* Read Request  - client server la irundhu file download pannanum */
    WRQ   = 2,  /* Write Request - client server ku file upload pannanum */
    DATA  = 3,  /* Data Packet   - actual file data inge irukkum - 512 bytes씩 */
    ACK   = 4,  /* Acknowledgment - "packet kedaichutu, next pathaychu" nu confirm */
    ERROR = 5   /* Error Packet  - edhaavadhu thappaa pochu nu server/client solludu */
} tftp_opcode;

/* TFTP Packet Structure - network la pora oru packet eppadi irukkum nu define panrom */
typedef struct {

    /* Operation code - RRQ/WRQ/DATA/ACK/ERROR - enna type packet nu solludu */
    uint16_t opcode;

    /* Union - oru packet la oru type mattum irukkum - memory share panrom */
    union {

        /* RRQ and WRQ packet - file name + mode contain pannum */
        struct {
            char filename[256]; /* Enna file venumnu server ku solludu */
            char mode[8];       /* "octet" = binary mode, "netascii" = text mode */
        } request;

        /* DATA packet - actual file content inge irukkum */
        struct {
            uint16_t block_number; /* Enna number block idhu - 1,2,3... track panrom */
            char data[512];        /* Actual file data - max 512 bytes per block */
        } data_packet;

        /* ACK packet - "block kedaichutu" nu confirm panradhu */
        struct {
            uint16_t block_number; /* Enna block ku ACK pannrom nu solludu */
        } ack_packet;

        /* ERROR packet - enna error achu nu solludu */
        struct {
            uint16_t error_code;   /* Error number - 1=file not found, 2=access violation */
            char error_msg[512];   /* Human readable error message */
        } error_packet;

    } body; /* Union ku "body" nu peyar - packet body idunga */

} tftp_packet; /* Indha struct ku tftp_packet nu peyar */

/* Function declarations - tftp.c la implement pannuvom - server & client both use pannum */

/* send_file - server file uh client ku anuppadhu - RRQ ku response */
void send_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename);

/* receive_file - client anupra file uh server receive panradhu - WRQ ku response */
void receive_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename);

/* Header guard end - #ifndef ku closing */
#endif // TFTP_H
