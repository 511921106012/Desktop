/* Common file - server & client rendu peyrum use pannum */

#include "tftp.h"    /* tftp_packet, opcodes, PORT ellam idha irundhu varudu */
#include <stdio.h>   /* printf, fopen, fread, fwrite, fclose use pannanum */
#include <stdlib.h>  /* exit() use pannanum */
#include <string.h>  /* memset, snprintf use pannanum */
#include <unistd.h>  /* close() socket close pannanum */

/*
 * send_file() - SERVER side function
 * Client RRQ anuppa - server file uh eduthu client ku block by block anuppadum
 * Each 512 byte block anuppi - client ACK varum varaiku wait pannum
 * Last block < 512 bytes aana - file mudinjuchu nu client ku theriyum
 */
void send_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename)
{
    /* File open panrom - "rb" = read binary mode - text illa binary la padikrom */
    FILE *fp = fopen(filename, "rb");

    /* File illana - ERROR packet anuppi return pannivom */
    if (fp == NULL) {

        /* Error packet create panrom - memset la zero fill panrom first */
        tftp_packet err_pkt;
        memset(&err_pkt, 0, sizeof(err_pkt)); /* Safety - garbage values clear panrom */

        /* ERROR opcode set panrom - htons() = host to network byte order convert */
        err_pkt.opcode = htons(ERROR);

        /* Error code 1 = "File not found" - TFTP standard error codes */
        err_pkt.body.error_packet.error_code = htons(1);

        /* Error message format panrom - client ku readable message */
        snprintf(err_pkt.body.error_packet.error_msg,
                 sizeof(err_pkt.body.error_packet.error_msg),
                 "File not found: %s", filename);

        /* Client ku error packet anuprom - sendto = UDP la packet anupradhu */
        sendto(sockfd, &err_pkt, sizeof(err_pkt), 0,
               (struct sockaddr *)&client_addr, client_len);

        perror("send_file: fopen failed"); /* Terminal la error print panrom */
        return; /* Function exit */
    }

    /* Data packet and ACK packet variables declare panrom */
    tftp_packet data_pkt, ack_pkt;

    /* Block number 1 la start - TFTP protocol rule */
    uint16_t block_num = 1;

    /* File la irundhu ethanai bytes padichom nu store panrom */
    int bytes_read;

    /* File mudiyum varaiku loop - last block < 512 bytes aana break */
    while (1) {

        /* Data packet zero fill panrom - previous data clear aaganum */
        memset(&data_pkt, 0, sizeof(data_pkt));

        /* DATA opcode set - htons() byte order convert panrom */
        data_pkt.opcode = htons(DATA);

        /* Current block number set panrom - client track pannuvaanga */
        data_pkt.body.data_packet.block_number = htons(block_num);

        /* File la irundhu max 512 bytes padikrom */
        bytes_read = fread(data_pkt.body.data_packet.data, 1, 512, fp);

        /* Total packet size = 4 bytes header + actual data bytes */
        int send_len = 4 + bytes_read;

        /* Client ku data packet anuprom */
        if (sendto(sockfd, &data_pkt, send_len, 0,
                   (struct sockaddr *)&client_addr, client_len) < 0) {
            perror("send_file: sendto failed");
            break; /* Send fail aana loop break */
        }

        /* Client ACK anupuvanga - adha wait panrom */
        memset(&ack_pkt, 0, sizeof(ack_pkt)); /* ACK buffer clear */

        /* Client irundhu ACK receive panrom - recvfrom = UDP receive */
        int n = recvfrom(sockfd, &ack_pkt, sizeof(ack_pkt), 0,
                         (struct sockaddr *)&client_addr, &client_len);

        /* Timeout or error aana break */
        if (n < 0) {
            perror("send_file: recvfrom (ACK) failed / timeout");
            break;
        }

        /* ACK packet valid ah check panrom - opcode ACK ah? Block number match ah? */
        if (ntohs(ack_pkt.opcode) != ACK ||
            ntohs(ack_pkt.body.ack_packet.block_number) != block_num) {
            fprintf(stderr, "send_file: unexpected ACK, block=%d\n",
                    ntohs(ack_pkt.body.ack_packet.block_number));
            break; /* Wrong ACK - transfer abort */
        }

        /* 512 bytes kammiya padichom - last block - file mudinjuchu */
        if (bytes_read < 512)
            break;

        /* Next block ku move - block number increment */
        block_num++;
    }

    fclose(fp); /* File close panrom - resource free */
    printf("send_file: '%s' sent successfully.\n", filename);
}

/*
 * receive_file() - SERVER side function
 * Client WRQ anuppa - server file receive pannum
 * First ACK 0 anuppi "ready" nu solludu
 * Then client DATA blocks anuppuvaanga - server ACK pannudu
 * Last block < 512 bytes aana - transfer complete
 */
void receive_file(int sockfd, struct sockaddr_in client_addr, socklen_t client_len, char *filename)
{
    /* File create panrom - "wb" = write binary mode */
    FILE *fp = fopen(filename, "wb");

    /* File create aagalana - ERROR anuppi return */
    if (fp == NULL) {

        tftp_packet err_pkt;
        memset(&err_pkt, 0, sizeof(err_pkt));

        err_pkt.opcode = htons(ERROR);

        /* Error code 2 = "Access violation" - file create permission illana */
        err_pkt.body.error_packet.error_code = htons(2);

        snprintf(err_pkt.body.error_packet.error_msg,
                 sizeof(err_pkt.body.error_packet.error_msg),
                 "Cannot create file: %s", filename);

        sendto(sockfd, &err_pkt, sizeof(err_pkt), 0,
               (struct sockaddr *)&client_addr, client_len);

        perror("receive_file: fopen failed");
        return;
    }

    /* ACK and DATA packet variables */
    tftp_packet ack_pkt, data_pkt;

    /* ACK 0 anuprom - "ready, start anuppu" nu client ku signal */
    memset(&ack_pkt, 0, sizeof(ack_pkt));
    ack_pkt.opcode                       = htons(ACK);
    ack_pkt.body.ack_packet.block_number = htons(0); /* Block 0 = WRQ ku response */

    /* Client ku ACK 0 anuprom - 4 bytes only - ACK packet size */
    sendto(sockfd, &ack_pkt, 4, 0,
           (struct sockaddr *)&client_addr, client_len);

    /* First DATA block = block 1 - idha expect panrom */
    uint16_t expected_block = 1;

    /* Client ellaa blocks anuppum varaiku loop */
    while (1) {

        /* DATA packet receive buffer clear */
        memset(&data_pkt, 0, sizeof(data_pkt));

        /* Client irundhu DATA block receive panrom */
        int n = recvfrom(sockfd, &data_pkt, sizeof(data_pkt), 0,
                         (struct sockaddr *)&client_addr, &client_len);

        /* Timeout aana break */
        if (n < 0) {
            perror("receive_file: recvfrom failed / timeout");
            break;
        }

        /* DATA packet ah check - wrong type aana break */
        if (ntohs(data_pkt.opcode) != DATA) {
            fprintf(stderr, "receive_file: expected DATA, got opcode=%d\n",
                    ntohs(data_pkt.opcode));
            break;
        }

        /* Block number check - expected block match ah? */
        uint16_t received_block = ntohs(data_pkt.body.data_packet.block_number);
        if (received_block != expected_block) {
            fprintf(stderr, "receive_file: block mismatch expected=%d got=%d\n",
                    expected_block, received_block);
            break;
        }

        /* n = 4 bytes header + data bytes - so data only = n - 4 */
        int data_bytes = n - 4;

        /* File la data write panrom */
        fwrite(data_pkt.body.data_packet.data, 1, data_bytes, fp);

        /* This block ku ACK anuprom - "block kedaichutu, next anuppu" */
        memset(&ack_pkt, 0, sizeof(ack_pkt));
        ack_pkt.opcode                       = htons(ACK);
        ack_pkt.body.ack_packet.block_number = htons(received_block);

        /* 4 bytes only - ACK packet has no data */
        sendto(sockfd, &ack_pkt, 4, 0,
               (struct sockaddr *)&client_addr, client_len);

        /* Last block check - 512 bytes kammiya aana file mudinjuchu */
        if (data_bytes < 512)
            break;

        /* Next block expect panrom */
        expected_block++;
    }

    fclose(fp); /* File close - resource free */
    printf("receive_file: '%s' saved successfully.\n", filename);
}
