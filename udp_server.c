#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sockfd;
    char buffer[BUFFER_SIZE];
    char reply[] = "Message received";
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;

    /* 1. Create UDP socket */
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    /* 2. Fill server address structure */
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* 3. Bind socket */
    if (bind(sockfd, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("UDP Server listening on port %d...\n", PORT);

    addr_len = sizeof(client_addr);

    /* 4. Receive data */
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                     (struct sockaddr *)&client_addr,
                     &addr_len);

    buffer[n] = '\0';
    printf("Client says: %s\n", buffer);

    /* 5. Send reply */
    sendto(sockfd, reply, strlen(reply), 0,
           (struct sockaddr *)&client_addr,
           addr_len);

    close(sockfd);
    return 0;
}
