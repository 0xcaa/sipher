#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "usage.h"
#include "sipherfuncs.h"
#include "list.h"

#define SIZE 3000

int main(int argc, char **argv)
{
    int opt;
    char *text;
    if (argc!=2)
    {
        fprintf(stderr, "Too many arguments!\n");
        printusage(argv[0]);
        return 1;
    }

    while((opt = getopt(argc, argv, "rul")) != -1)
        switch(opt)
        {
            case 'r':
                text = calloc(SIZE, sizeof(char));
                printf("%s\n", rot(text));
                free(text);
                break;
            case 'u':
                printusage(argv[0]);
                break;
            case 'l':
                list();
                break;
            return 1;
        default:
            perror("Invalid Option");
            return 1;
        }

    return 0;
}
