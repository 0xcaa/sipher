#include <stdio.h>

void printusage(char *arg)
{
    printf("Usage: %s (-e) | (-d) (-cipher) (text or file)\n", arg);
    printf("-e = encrypt\n");
    printf("-d = decrypt\n");
    printf("sipher -list for full cipher list\n");
}

