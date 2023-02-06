#include <stdio.h>
#include <string.h>

// From libcrypto
#include <openssl/sha.h>

#define OPENSSL_API_COMPAT 11200

void sha256(char *string, char outputBuffer[65]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    outputBuffer[64] = 0;
}

int main() {
    static unsigned char buffer[65];
    sha256("SCC", buffer);
    printf("%s\n", buffer);
}
