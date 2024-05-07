#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE_MSG 100

#define PORT 7
#define ADDR "::1" // localhost -> changer à "lampe" ou "nivose"

int main(int argc, char* argv[]) {
  struct sockaddr_in6 address_sock;
  struct in6_addr address;
  int socket_fd, ret_val;

  char buf[SIZE_MSG], msg[SIZE_MSG];
  int size_recv;

  address_sock.sin6_family = AF_INET6;
  address_sock.sin6_port = htons(PORT);
  inet_pton(AF_INET6, ADDR, &address);
  address_sock.sin6_addr = address;

  socket_fd = socket(PF_INET6, SOCK_STREAM, 0);

  ret_val = connect(socket_fd,
                    (struct sockaddr *) &address_sock,
                    sizeof(struct sockaddr_in6));

  if (ret_val == -1) {
    perror("Erreur");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 10; i++) {
    snprintf(msg, SIZE_MSG, "Hello%d", i);
    printf("SENDING: %s\n", msg);
    send(socket_fd, msg, strlen(msg), 0);

    size_recv = recv(socket_fd, buf, 99*sizeof(char), 0);
    buf[size_recv] = '\0';
    printf("RECEIVED: %s\n", buf);
  }

  close(socket_fd);
}
