#include <stdio.h>

void printusage(char *argv[])
{
    printf("Usage: %s -cipher \nThen type file or string\n", argv[0]);
    printf("sipher -l for full cipher list\n");
}
