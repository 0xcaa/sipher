#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "usage.h"
#include "sipherfuncs.h"
#include "list.h"

int main(int argc, char **argv)
{
    int opt;
    if (argc!=2)
    {
        printusage(argv[0]);
        exit(255);
    }

    while((opt = getopt(argc, argv, "rula")) != -1)
        switch(opt)
        {
            case 'r':
                rot();
                break;
            case 'a':
                atbash();
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
