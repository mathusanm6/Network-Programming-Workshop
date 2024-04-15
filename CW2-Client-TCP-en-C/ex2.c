#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {

    int sockfd;
    struct sockaddr_in adso;

    memset(&adso, 0, sizeof(adso));

    adso.sin_family = AF_INET;
    adso.sin_port = htons(13);
    if (inet_pton(AF_INET, "192.168.70.237", &adso.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &adso, sizeof(adso)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[100];

    int n;
    while ((n = read(sockfd, buffer, 100)) > 0) {
        buffer[n] = 0;
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("read");
        exit(1);
    }

    close(sockfd);

    return 0;
}