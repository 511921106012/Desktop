#include "tftp.h"        /* tftp_packet, opcodes, PORT */
#include "tftp_client.h" /* tftp_client_t struct, function prototypes */
#include <stdio.h>       /* printf, fgets, fopen, fread, fwrite */
#include <stdlib.h>      /* exit() */
#include <string.h>      /* memset, strcmp, strcspn, strlen, strncpy */
#include <unistd.h>      /* close() */
#include <arpa/inet.h>   /* socket(), inet_pton(), htons(), sendto(), recvfrom() */

int main()
{
    /* User type pannuradha store panrom - max 256 chars */
    char command[256];

    /* Client structure - socket + server address ellam inge store aagum */
    tftp_client_t client;

    /* memset - client structure zero fill panrom - garbage values avoid */
    memset(&client, 0, sizeof(client));

    /* Infinite loop - user quit type pannuvaraiku prompt show panrom */
    while (1) {

        /* "tftp> " prompt show panrom */
        printf("tftp> ");

        /* Buffer flush - prompt screen la immediately show aaganum */
        fflush(stdout);

        /* User input read panrom - fgets = safe input, buffer overflow avoid */
        if (fgets(command, sizeof(command), stdin) == NULL)
            break; /* EOF aana - Ctrl+D press aana - loop break */

        /* '\n' remove panrom - fgets newline include pannudu */
        command[strcspn(command, "\n")] = 0;

        /* Empty input skip panrom - just Enter press aana */
        if (strlen(command) == 0)
            continue;

        /* Command process panrom - connect/get/put/mode/quit */
        process_command(&client, command);
    }
    return 0;
}

/*
 * process_command()
 * User "tftp> " la type pannuradha parse panrom
 * connect <ip>   = server ku connect
 * get <filename> = server irundhu download
 * put <filename> = server ku upload
 * mode octet|netascii = transfer mode change
 * quit/exit      = program close
 */
void process_command(tftp_client_t *client, char *command)
{
    char cmd[64];  /* First word - "connect", "get", "put" etc */
    char arg[256]; /* Second word - IP address or filename */

    /* sscanf - command string parse panrom - "connect 192.168.1.1" -> cmd="connect" arg="192.168.1.1" */
    int n = sscanf(command, "%63s %255s", cmd, arg);

    /* n < 1 = empty command - nothing parse aagalana */
    if (n < 1) {
        printf("Commands: connect <ip>, get <file>, put <file>, mode octet|netascii, quit\n");
        return;
    }

    /* ── connect command ─────────────────────────────────────── */
    if (strcmp(cmd, "connect") == 0) {

        /* Argument illana - usage show panrom */
        if (n < 2) { printf("Usage: connect <server_ip>\n"); return; }

        /* IP address valid ah check panrom - inet_pton return value check */
        struct sockaddr_in test;
        if (inet_pton(AF_INET, arg, &test.sin_addr) <= 0) {
            printf("Error: invalid IP '%s'\n", arg); return;
        }

        /* Valid IP - connect_to_server call panrom */
        connect_to_server(client, arg, PORT);

    /* ── get command ─────────────────────────────────────────── */
    } else if (strcmp(cmd, "get") == 0) {

        if (n < 2) { printf("Usage: get <filename>\n"); return; }

        /* sockfd 0 aana - connect pannala nu arththam */
        if (client->sockfd == 0) { printf("Not connected. Use 'connect <ip>' first.\n"); return; }

        /* get_file call - server irundhu download */
        get_file(client, arg);

    /* ── put command ─────────────────────────────────────────── */
    } else if (strcmp(cmd, "put") == 0) {

        if (n < 2) { printf("Usage: put <filename>\n"); return; }

        if (client->sockfd == 0) { printf("Not connected. Use 'connect <ip>' first.\n"); return; }

        /* Local la file irukka check panrom - illana upload pannuradhu waste */
        FILE *fp = fopen(arg, "rb");
        if (!fp) { printf("Error: file '%s' not found locally.\n", arg); return; }
        fclose(fp); /* Check ku mattum open panni close pannivom */

        /* put_file call - server ku upload */
        put_file(client, arg);

    /* ── mode command ────────────────────────────────────────── */
    } else if (strcmp(cmd, "mode") == 0) {

        if (n < 2) { printf("Usage: mode octet|netascii\n"); return; }

        /* octet = binary files, netascii = text files */
        if (strcmp(arg, "octet") == 0 || strcmp(arg, "netascii") == 0)
            printf("Mode set to: %s\n", arg);
        else
            printf("Error: unknown mode '%s'. Use octet or netascii.\n", arg);

    /* ── quit/exit command ───────────────────────────────────── */
    } else if (strcmp(cmd, "quit") == 0 || strcmp(cmd, "exit") == 0) {

        disconnect(client); /* Socket close */
        printf("Goodbye.\n");
        exit(0); /* Program terminate */

    } else {
        /* Unknown command */
        printf("Unknown command '%s'. Try: connect, get, put, mode, quit\n", cmd);
    }
}

/*
 * connect_to_server()
 * UDP socket create panrom
 * Timeout set panrom
 * Server address store panrom
 * IMPORTANT: No packet sent to server here - only local setup
 */
void connect_to_server(tftp_client_t *client, char *ip, int port)
{
    /* UDP socket create - AF_INET=IPv4, SOCK_DGRAM=UDP */
    client->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client->sockfd < 0) { perror("socket() failed"); return; }

    /* Receive timeout set - server reply varaama 5 seconds wait pannum */
    struct timeval tv = { TIMEOUT_SEC, 0 }; /* 5 sec, 0 microsec */
    if (setsockopt(client->sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt() failed");
        close(client->sockfd);
        client->sockfd = 0; /* Reset - not connected state */
        return;
    }

    /* Server address structure setup */
    memset(&client->server_addr, 0, sizeof(client->server_addr)); /* Zero fill */
    client->server_addr.sin_family = AF_INET;          /* IPv4 */
    client->server_addr.sin_port   = htons(port);       /* Port number - network byte order */
    inet_pton(AF_INET, ip, &client->server_addr.sin_addr); /* IP string -> binary */

    /* server_len - sendto ku vendiyathu */
    client->server_len = sizeof(client->server_addr);

    /* IP string save panrom - display ku use panrom */
    strncpy(client->server_ip, ip, INET_ADDRSTRLEN);

    printf("Connected to server %s:%d\n", ip, port);
}

/*
 * put_file()
 * Client file uh server ku upload panrom
 * Step 1: WRQ packet anuprom
 * Step 2: Server ACK 0 anuppum - "ready" signal
 * Step 3: File 512 bytes씩 DATA blocks la anuprom
 * Step 4: Oru block ku server ACK anuppum - next block anuprom
 */
void put_file(tftp_client_t *client, char *filename)
{
    /* WRQ packet anuprom - "indha file upload pannanum" nu server ku solludu */
    send_request(client->sockfd, client->server_addr, client->server_len, filename, WRQ);

    /* Server ACK 0 wait panrom - "ready" signal */
    tftp_packet ack_pkt;
    struct sockaddr_in from_addr;   /* Server address store - recvfrom ku */
    socklen_t from_len = sizeof(from_addr);

    /* Server irundhu ACK 0 receive panrom */
    int n = recvfrom(client->sockfd, &ack_pkt, sizeof(ack_pkt), 0,
                     (struct sockaddr *)&from_addr, &from_len);

    if (n < 0) { perror("put_file: no ACK 0 from server"); return; }

    /* Server ERROR anuppuchuna - print panni return */
    if (ntohs(ack_pkt.opcode) == ERROR) {
        printf("Server error: %s\n", ack_pkt.body.error_packet.error_msg); return;
    }

    /* ACK 0 valid ah check - opcode ACK ah? block number 0 ah? */
    if (ntohs(ack_pkt.opcode) != ACK || ntohs(ack_pkt.body.ack_packet.block_number) != 0) {
        printf("put_file: unexpected response from server.\n"); return;
    }

    /* Local file open panrom - upload ku */
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("put_file: fopen"); return; }

    tftp_packet data_pkt;
    uint16_t block_num = 1; /* Block 1 irundhu start */
    int bytes_read;

    /* File mudiyum varaiku DATA blocks anuprom */
    while (1) {

        /* Data packet prepare */
        memset(&data_pkt, 0, sizeof(data_pkt));
        data_pkt.opcode                        = htons(DATA);
        data_pkt.body.data_packet.block_number = htons(block_num);

        /* File irundhu 512 bytes padikrom */
        bytes_read = fread(data_pkt.body.data_packet.data, 1, 512, fp);

        /* Server ku DATA block anuprom */
        if (sendto(client->sockfd, &data_pkt, 4 + bytes_read, 0,
                   (struct sockaddr *)&client->server_addr, client->server_len) < 0) {
            perror("put_file: sendto"); break;
        }

        /* Server irundhu ACK wait panrom */
        memset(&ack_pkt, 0, sizeof(ack_pkt));
        n = recvfrom(client->sockfd, &ack_pkt, sizeof(ack_pkt), 0,
                     (struct sockaddr *)&from_addr, &from_len);
        if (n < 0) { perror("put_file: ACK timeout"); break; }

        /* ACK valid ah check */
        if (ntohs(ack_pkt.opcode) != ACK ||
            ntohs(ack_pkt.body.ack_packet.block_number) != block_num) {
            printf("put_file: ACK mismatch. Aborting.\n"); break;
        }

        /* Last block - 512 kammiya aana file mudinjuchu */
        if (bytes_read < 512) break;

        block_num++; /* Next block */
    }

    fclose(fp);
    printf("put_file: '%s' uploaded successfully.\n", filename);
}

/*
 * get_file()
 * Server irundhu file download panrom
 * Step 1: RRQ packet anuprom
 * Step 2: Server DATA blocks anuppum
 * Step 3: Oru block receive aana - file la write panni ACK anuprom
 * Step 4: Last block < 512 bytes - download complete
 */
void get_file(tftp_client_t *client, char *filename)
{
    /* RRQ packet anuprom - "indha file venumnu" server ku solludu */
    send_request(client->sockfd, client->server_addr, client->server_len, filename, RRQ);

    /* Local la file create panrom - downloaded data inge write panrom */
    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("get_file: fopen"); return; }

    tftp_packet data_pkt, ack_pkt;
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    /* Server ellaa blocks anuppum varaiku loop */
    while (1) {

        /* Server irundhu DATA block receive panrom */
        memset(&data_pkt, 0, sizeof(data_pkt));
        int n = recvfrom(client->sockfd, &data_pkt, sizeof(data_pkt), 0,
                         (struct sockaddr *)&from_addr, &from_len);

        if (n < 0) { perror("get_file: recvfrom timeout"); break; }

        /* Server ERROR anuppuchuna - print panni stop */
        if (ntohs(data_pkt.opcode) == ERROR) {
            printf("Server error: %s\n", data_pkt.body.error_packet.error_msg); break;
        }

        /* DATA packet ah check */
        if (ntohs(data_pkt.opcode) != DATA) { printf("Expected DATA packet.\n"); break; }

        /* Block number edukurom */
        uint16_t block     = ntohs(data_pkt.body.data_packet.block_number);

        /* Data bytes = total - 4 bytes header */
        int      data_bytes = n - 4;

        /* File la data write panrom */
        fwrite(data_pkt.body.data_packet.data, 1, data_bytes, fp);

        /* This block ku ACK anuprom - "kedaichutu, next anuppu" */
        memset(&ack_pkt, 0, sizeof(ack_pkt));
        ack_pkt.opcode                       = htons(ACK);
        ack_pkt.body.ack_packet.block_number = htons(block);
        sendto(client->sockfd, &ack_pkt, 4, 0,
               (struct sockaddr *)&client->server_addr, client->server_len);

        /* Last block check */
        if (data_bytes < 512) break;
    }

    fclose(fp);
    printf("get_file: '%s' downloaded successfully.\n", filename);
}

/*
 * disconnect()
 * Socket close panrom
 * sockfd 0 ku reset - "not connected" state
 */
void disconnect(tftp_client_t *client)
{
    if (client->sockfd > 0) {        /* Valid socket ah check */
        close(client->sockfd);       /* OS ku socket return panrom */
        client->sockfd = 0;          /* Reset - next connect ku ready */
        printf("Disconnected from %s\n", client->server_ip);
    }
}

/*
 * send_request()
 * RRQ or WRQ packet build panni server ku anuprom
 * Packet format: [opcode 2bytes][filename][null][mode][null]
 */
void send_request(int sockfd, struct sockaddr_in server_addr, socklen_t server_len,
                  char *filename, int opcode)
{
    tftp_packet pkt;
    memset(&pkt, 0, sizeof(pkt)); /* Zero fill - clean packet */

    /* Opcode set - RRQ=1 or WRQ=2 - htons byte order convert */
    pkt.opcode = htons(opcode);

    /* Filename copy - max 255 chars */
    strncpy(pkt.body.request.filename, filename, 255);

    /* Mode = "octet" - binary transfer - always use this */
    strncpy(pkt.body.request.mode, "octet", 7);

    /* Packet size calculate - 2(opcode) + filename + null + "octet" + null */
    int pkt_size = 2 + strlen(filename) + 1 + strlen("octet") + 1;

    /* Server ku packet anuprom */
    if (sendto(sockfd, &pkt, pkt_size, 0,
               (struct sockaddr *)&server_addr, server_len) < 0)
        perror("send_request: sendto failed");
}

/*
 * receive_request()
 * Server side concept - client la use aagaadhu
 * Header la declare aachunu - implementation blank
 */
void receive_request(int sockfd, struct sockaddr_in server_addr,
                     socklen_t server_len, char *filename)
{
    /* Unused parameters - compiler warning avoid pannuradhu */
    (void)sockfd; (void)server_addr; (void)server_len; (void)filename;
}
