#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {

    uint32_t witness = 0x01020304;
    unsigned char *bytes = (unsigned char *) &witness;

    printf("Les octets sont : ");

    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", bytes[i]);
    }

    printf("\n");

    if (bytes[0] == 0x04) {
        printf("Le système est en little-endian\n");
    } else if (bytes[0] == 0x01){
        printf("Le système est en big-endian\n");
    } else {
        printf("Le format est inconnu\n");
    }

    return 0;
}