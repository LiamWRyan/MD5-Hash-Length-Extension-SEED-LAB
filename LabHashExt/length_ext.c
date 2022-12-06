/* length_ext.c */
#include <stdio.h>
#include <arpa/inet.h>
#include <openssl/sha.h>
int main(int argc, const char *argv[])
{
int i;
unsigned char buffer[SHA256_DIGEST_LENGTH];
SHA256_CTX c;
SHA256_Init(&c);
for(i=0; i<64; i++)
SHA256_Update(&c, "*", 1);
// MAC of the original message M (padded)
c.h[0] = htole32(0x68b3acf9);
c.h[1] = htole32(0xa04b34bc);
c.h[2] = htole32(0x81c3218f);
c.h[3] = htole32(0xcfe0f01c);
c.h[4] = htole32(0x6b51c03c);
c.h[5] = htole32(0x18611eee);
c.h[6] = htole32(0x8da8f9fd);
c.h[7] = htole32(0x04a9dc98);
// Append additional message
SHA256_Update(&c, "&download=secret.txt", 20);
SHA256_Final(buffer, &c);
for(i = 0; i < 32; i++) {
printf("%02x", buffer[i]);
}
printf("\n");
return 0;
}

