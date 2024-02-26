#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
    u_int32_t host = 0x12345678;
    u_int32_t net = htonl(host);

    if (net == host) {
        printf("Host and network byte order are the same\n");
    } else {
        printf("Host and network byte order are different\n");
    }

    return 0;
}