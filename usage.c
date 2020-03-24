#include <stdio.h>

void printusage(char *argv)
{
    fprintf(stdout, "Usage: %s -cipher \nThen type file or string\n", argv);
    fprintf(stdout, "sipher -l for full cipher list\n");
}
