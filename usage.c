#include <stdio.h>

void printusage(char *argv);

int list(void)
{
    printf("All siphers\n");
    printf("-r\tROT13 ceasar cipher\n");
    printf("-a\tAtbash cipher\n");
    printf("-g\tGold-Bug cipher\n");
    return 0;
}

void printusage(char *argv)
{
    fprintf(stdout, "Usage: %s -cipher \nThen type file or string\n", argv);
    fprintf(stdout, "sipher -l for full cipher list\n");
}
