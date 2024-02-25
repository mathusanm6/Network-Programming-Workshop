#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

int main() {

    FILE *file;
    u_int16_t entete[6];

    srand(time(NULL));

    entete[0] = htons(rand() % 65536);
    entete[1] = htons(0x0100); // QR = 0, OPCODE = 0000, AA = 0, TC = 0, RD = 1, RA = 0, Z = 000, RCODE = 0000
    entete[2] = htons(1); // QDCOUNT
    entete[3] = htons(0); // ANCOUNT
    entete[4] = htons(0); // NSCOUNT
    entete[5] = htons(0); // ARCOUNT

    file = fopen("requete", "wb");
    if (file == NULL) {
        perror("Error opening file!\n");
        return EXIT_FAILURE;
    }

    if (fwrite(entete, sizeof(u_int16_t), 6, file) != 6) {
        perror("Error writing to file!\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    printf("Entete created successfully!\n");

    char domain[] = "www.wikipedia.fr";
    char *token = strtok(domain, ".");

    while (token != NULL) {
        u_int8_t length = strlen(token);
        fwrite(&length, sizeof(u_int8_t), 1, file);
        fwrite(token, sizeof(char), length, file);
        token = strtok(NULL, ".");
    }

    u_int8_t end = 0;
    fwrite(&end, sizeof(u_int8_t), 1, file);

    u_int16_t type = htons(1);      // A record (28 for AAAA record, 1 for A record)
    fwrite(&type, sizeof(u_int16_t), 1, file);

    u_int16_t class = htons(1);
    fwrite(&class, sizeof(u_int16_t), 1, file);

    fclose(file);

    printf("File created successfully!\n");

    return EXIT_SUCCESS;
}